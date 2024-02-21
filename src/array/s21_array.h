#ifndef CPP_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H
#define CPP_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <typename T, std::size_t S>
class Array {
 public:
  // --- class traits --- //
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  // --- constructors --- //
  Array();
  Array(std::initializer_list<value_type> const &values);
  Array(const Array &a);
  Array(Array &&a) noexcept;
  ~Array() = default;

  // --- operators --- //
  Array &operator=(const Array &a);
  Array &operator=(Array &&a) noexcept;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  // --- methods --- //
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference front();
  reference back();
  const_reference front() const;
  const_reference back() const;
  iterator data() noexcept;

  bool empty();
  size_type size();
  size_type max_size();

  void swap(Array &a);
  void fill(const_reference value);

 private:
  value_type data_[S] = {};
  size_type size_ = S;
};
}  // namespace s21

#include "s21_array.tpp"

#endif  // CPP_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_H