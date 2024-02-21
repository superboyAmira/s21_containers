#ifndef CPP_S21_CONTAINERS_SRC_S21_LIST_TPP
#define CPP_S21_CONTAINERS_SRC_S21_LIST_TPP

#include "s21_list.h"

namespace s21 {
// === list class === //

// --- constructors --- //

template <typename T>
List<T>::List() : head_(new Node{}), size_(0) {}

template <typename T>
List<T>::List(size_type size) : List() {
  for (; size > 0; size--) push_back(value_type{});
}

template <typename T>
List<T>::List(std::initializer_list<value_type> const &values) : List() {
  for (auto value : values) push_back(value);
}

template <typename T>
List<T>::List(const List &l) : List() {
  for (auto value : l) push_back(value);
}

template <typename T>
List<T>::List(List &&l) noexcept : List() {
  splice(begin(), l);
}

template <typename T>
List<T>::~List() {
  clear();
  delete head_;
  head_ = nullptr;
}

// --- operators --- //

template <typename T>
typename List<T>::List &List<T>::operator=(const List &l) {
  if (this != &l) {
    this->clear();
    delete head_;
    new (this) List(l);
  }
  return *this;
}

template <typename T>
typename List<T>::List &List<T>::operator=(List &&l) noexcept {
  if (this != &l) {
    this->clear();
    splice(begin(), l);
  }
  return *this;
}

// --- methods --- //

template <typename T>
typename List<T>::const_reference List<T>::front() {
  return *begin();
}

template <typename T>
typename List<T>::const_reference List<T>::back() {
  return *--end();
}

template <typename T>
typename List<T>::List::iterator List<T>::begin() {
  return iterator(head_->next_);
}

template <typename T>
typename List<T>::List::iterator List<T>::end() {
  return iterator(head_);
}

template <typename T>
typename List<T>::List::const_iterator List<T>::begin() const {
  return const_iterator(head_->next_);
}

template <typename T>
typename List<T>::List::const_iterator List<T>::end() const {
  return const_iterator(head_);
}

template <typename T>
bool List<T>::empty() {
  return size_ == 0;
}

template <typename T>
typename List<T>::size_type List<T>::size() {
  return size_;
}

template <typename T>
typename List<T>::size_type List<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

template <typename T>
void List<T>::clear() {
  while (this->size_ > 0) erase(begin());
}

template <typename T>
typename List<T>::List::iterator List<T>::insert(iterator pos,
                                                 const_reference value) {
  Node *new_node = new Node(value);
  Node *prev_node = empty() || pos == end() ? head_->prev_ : pos.node_->prev_;

  link_nodes(prev_node, new_node);
  link_nodes(new_node, pos.node_);
  size_++;
  return iterator(new_node);
}

template <typename T>
void List<T>::erase(iterator pos) {
  if (pos != end()) {
    link_nodes(pos.node_->prev_, pos.node_->next_);
    delete pos.node_;
    this->size_--;
  }
}

template <typename T>
void List<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void List<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T>
void List<T>::pop_front() {
  erase(begin());
}

template <typename T>
void List<T>::pop_back() {
  erase(--end());
}

template <typename T>
void List<T>::swap(List &other) {
  if (this != &other) {
    std::swap(this->head_, other.head_);
    std::swap(this->size_, other.size_);
  }
}

template <typename T>
void List<T>::merge(List &other) {
  iterator pos_this = this->begin();
  iterator pos_other = other.begin();

  while (pos_this != end() && pos_other != other.end()) {
    if (*pos_this > *pos_other) {
      Node *tmp = pos_other.node_;
      ++pos_other;
      link_nodes(pos_this.node_->prev_, tmp);
      link_nodes(tmp, pos_this.node_);
      other.size_--;
      this->size_++;
    } else
      ++pos_this;
  }
  this->splice(pos_this, other);
  splice(end(), other);
}

template <typename T>
void List<T>::splice(const_iterator pos, List &other) {
  if (!other.empty()) {
    Node *pos_this = pos.iterator_.node_;
    Node *pos_other = other.head_;

    link_nodes(pos_this->prev_, pos_other->next_);
    link_nodes(pos_other->prev_, pos_this);
    this->size_ += other.size_;
    other.size_ = 0;
    other.clear();
  }
}

template <typename T>
void List<T>::reverse() {
  for (auto pos_begin = begin(), pos_end = end(); pos_begin != pos_end;
       --pos_begin)
    std::swap(pos_begin.node_->next_, pos_begin.node_->prev_);
  std::swap(head_->next_, head_->prev_);
}

template <typename T>
void List<T>::unique() {
  iterator prev_pos = begin();

  for (auto curr_pos = begin(); curr_pos != end(); ++curr_pos) {
    if (prev_pos.node_->value_ == curr_pos.node_->value_ && curr_pos != begin())
      erase(prev_pos);
    prev_pos = curr_pos;
  }
}

template <typename T>
void List<T>::sort() {
  iterator pos_main = this->begin();
  iterator pos_to_check = pos_main;

  ++pos_to_check;
  for (; pos_main != this->end(); ++pos_to_check) {
    if (pos_to_check == this->end()) {
      pos_to_check = pos_main;
      ++pos_main;
    } else if (pos_main.node_->value_ > pos_to_check.node_->value_) {
      link_nodes(pos_to_check.node_->prev_, pos_to_check.node_->next_);
      link_nodes(pos_main.node_->prev_, pos_to_check.node_);
      link_nodes(pos_to_check.node_, pos_main.node_);
      --pos_main;
      pos_to_check = pos_main;
    }
  }
}

// --- methods (bonus part) --- //

template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator it = pos.iterator_;
  for (const auto &arg : {args...}) {
    it = insert(it, arg);
    ++it;
  }
  return it;
}

template <typename T>
template <typename... Args>
void List<T>::insert_many_back(Args &&...args) {
  for (const auto &arg : {args...}) push_back(arg);
}

template <typename T>
template <typename... Args>
void List<T>::insert_many_front(Args &&...args) {
  iterator it = this->begin();
  insert_many(it, args...);
}

// --- support methods --- //

template <typename T>
void List<T>::link_nodes(Node *n1, Node *n2) {
  n2->prev_ = n1;
  n1->next_ = n2;
}

// === list iterator class === //

// --- operators --- //
template <typename value_type>
typename List<value_type>::ListIterator &
List<value_type>::ListIterator::operator++() {
  node_ = node_->next_;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListIterator &
List<value_type>::ListIterator::operator--() {
  node_ = node_->prev_;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListIterator
List<value_type>::ListIterator::operator++(int) {
  iterator tmp(node_);
  ++(*this);
  return tmp;
}

template <typename value_type>
typename List<value_type>::ListIterator
List<value_type>::ListIterator::operator--(int) {
  iterator tmp{node_};
  --(*this);
  return tmp;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator==(
    const ListIterator &other) const {
  return this->node_ == other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator!=(
    const ListIterator &other) const {
  return this->node_ != other.node_;
}

template <typename value_type>
typename List<value_type>::reference List<value_type>::ListIterator::operator*()
    const {
  return node_->value_;
}

// === const list iterator class === //

// --- operators --- //
template <typename value_type>
typename List<value_type>::const_reference
List<value_type>::ListConstIterator::operator*() const {
  return *iterator_;
}

template <typename value_type>
typename List<value_type>::ListConstIterator &
List<value_type>::ListConstIterator::operator++() {
  ++iterator_;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListConstIterator
List<value_type>::ListConstIterator::operator++(int) {
  ListConstIterator tmp = *this;
  ++(*iterator_);
  return tmp;
}

template <typename value_type>
typename List<value_type>::ListConstIterator &
List<value_type>::ListConstIterator::operator--() {
  --iterator_;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListConstIterator
List<value_type>::ListConstIterator::operator--(int) {
  ListConstIterator tmp = *this;
  --(*iterator_);
  return tmp;
}

template <typename value_type>
bool List<value_type>::ListConstIterator::operator==(
    const ListConstIterator &other) const {
  return iterator_ == other.iterator_;
}

template <typename value_type>
bool List<value_type>::ListConstIterator::operator!=(
    const ListConstIterator &other) const {
  return iterator_ != other.iterator_;
}
}  // namespace s21

#endif  // CPP_S21_CONTAINERS_SRC_S21_LIST_TPP