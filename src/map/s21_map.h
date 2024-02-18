/*
\author superboy
\date 18.02.2024
*/

#ifndef S21_CONTAINER_SRC_MAP_S21_MAP_H_
#define S21_CONTAINER_SRC_MAP_S21_MAP_H_

#define DEBUG_ 0

#include "../set/rbtree.h"

namespace s21 {

template <typename Key, typename T, class Compare = std::less<T>,
          class Allocator = std::allocator<T>>
class map {
 public:
  using value_type = std::pair<Key, T>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = RBIterator<Key, T, false>;
  using const_iterator = RBIterator<Key, T, true>;
  using size_type = size_t;
  using tree_type = RBTree<Key, T, Compare, Allocator>;
  using traits = std::allocator_traits<Allocator>;

  map() noexcept {};

  map(std::initializer_list<value_type> const &items) {
    for (auto i = items.begin(); i < items.end(); ++i) {
      insert(*i);
    }
  };

  map(const map &other)
      : tree_(other.tree_),
        alloc_(traits::select_on_container_copy_construction(other.alloc_)),
        comp_(other.comp_){};

  map(map &&other)
      : tree_(),
        alloc_(traits::select_on_container_copy_construction(other.alloc_)),
        comp_(std::move(other.comp_)) {
    tree_.Move(std::move(other.tree_));
  };

  ~map() noexcept = default;

  map &operator=(map &&s) noexcept {
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

  size_type max_size() const noexcept { return traits::max_size(alloc_); };

  void clear() noexcept { tree_.clear(); };

  T &at(const Key &key) {
    if (!contains(key)) {
      throw std::out_of_range("map::at error");
    }
    return (*(find(key))).second;
  };

  T &operator[](const Key &key) noexcept { return (*(find(key))).second; };

  std::pair<iterator, bool> insert(const value_type &value) {
    iterator it = find(value.first);

    if (it != end()) {
      return std::make_pair<iterator, bool>(iterator(it), false);
    } else {
      return tree_.insert(value.first, value.second);
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

  void swap(map &other) noexcept { tree_.swap(other.tree_); }

  void merge(map &other) noexcept {
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

#endif  // S21_CONTAINER_SRC_MAP_S21_MAP_H_
