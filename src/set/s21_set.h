/*
\author superboy
\date 26.01.2024
*/

#ifndef S21_CONTAINER_SRC_SET_S21_SET_H_
#define S21_CONTAINER_SRC_SET_S21_SET_H_

#define DEBUG_ 0

#include "rbtree.h"

namespace s21 {

template <typename Key, class Compare = std::less<Key>,
          class Allocator = std::allocator<Key>>
class set {
 public:
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = RBIterator<Key, Key, false>;
  using const_iterator = RBIterator<Key, Key, true>;
  using size_type = size_t;
  using tree_type = RBTree<Key, Key, Compare, Allocator>;
  using traits = std::allocator_traits<Allocator>;

  set() noexcept {};

  set(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i < items.end(); ++i) {
      insert(*i);
    }
  };

  set(const set &other)
      : tree_(other.tree_),
        alloc_(traits::select_on_container_copy_construction(other.alloc_)),
        comp_(other.comp_){};

  set(set &&other)
      : tree_(),
        alloc_(traits::select_on_container_copy_construction(other.alloc_)),
        comp_(std::move(other.comp_)) {
    tree_.Move(std::move(other.tree_));
  };

  ~set() noexcept = default;

  set &operator=(set &&s) noexcept {
    if (this != &s) {
      tree_ = std::move(s.tree_);
    }
    return *this;
  };

  iterator begin() { return tree_.begin(); };

  const_iterator cbegin() { return tree_.cbegin(); };

  iterator end() { return tree_.end(); };

  const_iterator cend() { return tree_.cend(); };

  bool empty() const noexcept { return tree_.empty(); };

  size_type size() const noexcept { return tree_.size(); };

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  };

  void clear() noexcept { tree_.clear(); };

  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = find(value);

    if (it != end()) {
      return std::make_pair<iterator, bool>(iterator(it), false);
    } else {
      return tree_.insert(value, value);
    }
  };

  void erase(iterator pos) noexcept {
    iterator it = find((*pos).first);

    if (it != end()) {
      tree_.erase(pos);
    }
  };

#ifndef DEBUG_
  void out(int *arr) {
    for (int i = 0; i < 100; i++) {
      *(arr + i) = 0;
    };
    for (auto i = begin(), j = 0; i != end(); ++i, ++j) {
      *(arr + j) = (*i).first;
    }
  }
#endif

  void swap(set &other) noexcept { tree_.swap(other.tree_); }

  void merge(set &other) noexcept {
    for (const auto &pair : other) {
      tree_.insert(pair.first, pair.second);
    }
    other.clear();
  };

  iterator find(const Key &key) noexcept { return tree_.find(key); };

  bool contains(const Key &key) const noexcept { return tree_.contains(key); };

 private:
  tree_type tree_;
  Allocator alloc_;
  Compare comp_;
};

}  // namespace s21

#endif  // S21_CONTAINER_SRC_SET_S21_SET_H_
