#ifndef CPP_S21_CONTAINERS_SRC_S21_LIST_H
#define CPP_S21_CONTAINERS_SRC_S21_LIST_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class List {
 private:
  // --- structures and nested classes --- //
  struct Node;
  class ListIterator;
  class ListConstIterator;

 public:
  // --- class traits --- //
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;
  using size_type = std::size_t;

  // --- constructors --- //
  List();
  explicit List(size_type size);
  List(std::initializer_list<value_type> const &values);
  List(const List &l);
  List(List &&l) noexcept;
  ~List();

  // --- operators --- //
  List &operator=(const List &l);
  List &operator=(List &&l) noexcept;

  // --- methods --- //
  const_reference front();
  const_reference back();

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_front(const_reference value);
  void push_back(const_reference value);
  void pop_front();
  void pop_back();
  void swap(List &other);
  void merge(List &other);
  void splice(const_iterator pos, List &other);
  void reverse();
  void unique();
  void sort();

  // --- methods (bonus part) --- //
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  // --- list elements --- //
  struct Node {
    // --- values --- //
    value_type value_;
    Node *prev_;
    Node *next_;

    // --- constructors --- //
    Node() noexcept : value_(value_type{}), prev_(this), next_(this){};
    explicit Node(const_reference value) noexcept
        : value_(value), prev_(nullptr), next_(nullptr){};
  };

  // --- support methods --- //
  void link_nodes(Node *n1, Node *n2);

  // --- values --- //
  Node *head_;
  size_t size_;
};

template <typename value_type>
class List<value_type>::ListIterator {
 public:
  friend class List;

  // --- iterator traits --- //
  using difference_type = std::ptrdiff_t;
  using value_type = List::value_type;
  using pointer = value_type *;
  using reference = value_type &;
  using iterator_category = std::bidirectional_iterator_tag;

  // --- constructors --- //
  ListIterator() = default;
  explicit ListIterator(Node *node) noexcept : node_(node){};

  // --- operators --- //
  reference operator*() const;
  iterator &operator++();
  iterator &operator--();
  iterator operator++(int);
  iterator operator--(int);
  bool operator==(const ListIterator &other) const;
  bool operator!=(const ListIterator &other) const;

 protected:
  Node *node_;
};

template <typename value_type>
class List<value_type>::ListConstIterator : ListIterator {
 public:
  friend class List;

  // --- iterator traits --- //
  using const_reference = const value_type &;
  using const_pointer = const value_type *;

  // --- constructors --- //
  ListConstIterator() = delete;
  ListConstIterator(const ListIterator &it) : iterator_(it) {}
  ListConstIterator(Node *node) : iterator_(node) {}

  // --- operators --- //
  const_reference operator*() const;
  ListConstIterator &operator++();
  ListConstIterator operator++(int);
  ListConstIterator &operator--();
  ListConstIterator operator--(int);
  bool operator==(const ListConstIterator &other) const;
  bool operator!=(const ListConstIterator &other) const;

 private:
  iterator iterator_;
};

}  // namespace s21

#include "s21_list.tpp"
#endif  // CPP_S21_CONTAINERS_SRC_S21_LIST_H