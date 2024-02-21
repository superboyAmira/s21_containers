#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP
#define CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP

#include "s21_array.h"

namespace s21 {

// --- constructors --- //

template <typename T, std::size_t S>
Array<T, S>::Array() : size_(S) {}

template <typename T, std::size_t S>
Array<T, S>::Array(const std::initializer_list<value_type> &values) {
  std::copy(values.begin(), values.end(), data_);
}

template <typename T, std::size_t S>
Array<T, S>::Array(const Array &a) {
  std::copy(a.data_, a.data_ + S, data_);
}

template <typename T, std::size_t S>
Array<T, S>::Array(Array &&a) noexcept {
  std::move(a.data_, a.data_ + S, data_);
}

// --- operators --- //

template <typename T, std::size_t S>
typename Array<T, S>::Array &Array<T, S>::operator=(const Array &a) {
  std::copy(a.data_, a.data_ + S, data_);
  return *this;
}

template <typename T, std::size_t S>
typename Array<T, S>::Array &Array<T, S>::operator=(Array &&a) noexcept {
  for (size_t i = 0; i < S; ++i) data_[i] = std::move(a.data_[i]);
  return *this;
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::operator[](size_type pos) {
  if (pos >= S)
    throw std::out_of_range("Error in \"[]\": index is out of range");
  return data_[pos];
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::operator[](
    size_type pos) const {
  if (pos >= S)
    throw std::out_of_range("Error in \"[]\": index is out of range");
  return data_[pos];
}

// --- methods --- //

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::begin() {
  return data_;
}

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::end() {
  return data_ + S;
}

template <typename T, std::size_t S>
typename Array<T, S>::const_iterator Array<T, S>::cbegin() const {
  return data_;
}

template <typename T, std::size_t S>
typename Array<T, S>::const_iterator Array<T, S>::cend() const {
  return data_ + S;
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::at(size_type pos) {
  if (pos >= S)
    throw std::out_of_range("Error in \"at()\": index is out of range");
  return (*this)[pos];
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::at(size_type pos) const {
  if (pos >= S)
    throw std::out_of_range("Error in \"at()\": index is out of range");
  return (*this)[pos];
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::front() {
  return data_[0];
}

template <typename T, std::size_t S>
typename Array<T, S>::reference Array<T, S>::back() {
  return data_[S - 1];
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::front() const {
  return data_[0];
}

template <typename T, std::size_t S>
typename Array<T, S>::const_reference Array<T, S>::back() const {
  return data_[S - 1];
}

template <typename T, std::size_t S>
typename Array<T, S>::iterator Array<T, S>::data() noexcept {
  return data_;
}

template <typename T, std::size_t S>
bool Array<T, S>::empty() {
  return size_ == 0;
}

template <typename T, std::size_t S>
typename Array<T, S>::size_type Array<T, S>::size() {
  return size_;
}

template <typename T, std::size_t S>
typename Array<T, S>::size_type Array<T, S>::max_size() {
  return size();
}

template <typename T, std::size_t S>
void Array<T, S>::swap(Array &a) {
  std::swap_ranges(data_, data_ + S, a.data_);
}

template <typename T, std::size_t S>
void Array<T, S>::fill(const_reference value) {
  std::fill(data_, data_ + S, value);
}
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_S21_ARRAY_TPP