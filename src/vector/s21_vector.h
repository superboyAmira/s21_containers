/*
\author superboy
\date 26.01.2024
*/

#ifndef S21_CONTAINER_SRC_VECTOR_S21_VECTOR_H_
#define S21_CONTAINER_SRC_VECTOR_S21_VECTOR_H_

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>

namespace s21 {

template <typename T, bool is_const>
struct Iterator;

template <typename T, typename Allocator = std::allocator<T>>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using pointer = T *;
  using const_pointer = const T *;
  using iterator = Iterator<T, false>;
  using const_iterator = Iterator<T, true>;
  using size_type = size_t;
  using traits = std::allocator_traits<Allocator>;

  /*
  \brief Default constructor. Constructs an empty container with a
  default-constructed allocator.
  */
  vector() noexcept
      : alloc_(Allocator()), size_(0), capacity_(0), arr_(nullptr){};

  /*
  \brief Constructs the container with count default-inserted instances of T. No
  copies are made.
  */
  explicit vector(size_t n, const Allocator &alloc = Allocator())
      : alloc_(alloc), size_(n), capacity_(n), arr_(nullptr) {
    arr_ = traits::allocate(alloc_, n);
    for (size_type i = 0; i != n; i++) {
      try {
        traits::construct(alloc_, std::addressof(*(arr_ + i)),
                          std::move(value_type()));
      } catch (...) {
        traits::destroy(alloc_, arr_ + i);
        traits::deallocate(alloc_, arr_, capacity_);
        throw;
      }
    }
  };

  /*
  \brief Constructs the container with the contents of the initializer list
  items.
  */
  vector(std::initializer_list<value_type> const &items,
         const Allocator &alloc = Allocator())
      : alloc_(alloc),
        size_(items.size()),
        capacity_(items.size()),
        arr_(nullptr) {
    arr_ = std::allocator_traits<Allocator>::allocate(alloc_, items.size());
    std::uninitialized_copy(items.begin(), items.end(), arr_);
  };

  /*
  \brief Copy constructor. Constructs the container with the copy of the
  contents of other.
  */
  vector(const vector &v)
      : alloc_(std::allocator_traits<
               Allocator>::select_on_container_copy_construction(v.alloc_)),
        size_(v.size_),
        capacity_(v.capacity_) {
    arr_ = traits::allocate(alloc_, capacity_);

    for (auto itr_v = v.cbegin(), itr = begin(); itr_v != v.cend();
         ++itr_v, ++itr) {
      traits::construct(alloc_, std::addressof(*itr), *itr_v);
    }
  };

  /*
  \brief Move constructor. Constructs the container with the contents of other
  using move semantics. Allocator is obtained by move-construction from the
  allocator belonging to other. After the move, other is guaranteed to be
  empty().
  */
  vector(vector &&v) noexcept
      : alloc_(std::allocator_traits<
               Allocator>::select_on_container_copy_construction(v.alloc_)),
        size_(v.size_),
        capacity_(v.capacity_),
        arr_(std::move(v.arr_)) {
    v.arr_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  };

  /*
  \brief Destructs the vector.
  \details The destructors of the elements
  are called and the used storage is deallocated.
  */
  ~vector() noexcept {
    for (auto itr = begin(); itr != end(); ++itr) {
      traits::destroy(alloc_, std::addressof(*itr));
    }
    traits::deallocate(alloc_, arr_, capacity_);
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
  };

  /*
  \brief Copy assignment operator. Replaces the contents with a copy of the
  contents of other. \param[in] v another container to use as data source
  */
  vector &operator=(const vector &v) {
    if (this == &v) {
      return *this;
    }

    if (v.capacity() < capacity()) {
      try {
        for (auto itr = begin(), i = 0;
             (itr != end()) && ((size_t)(i) < v.size_); ++itr, ++i) {
          traits::destroy(alloc_, std::addressof(*itr));
          traits::construct(alloc_, std::addressof(*itr),
                            value_type(v.arr_[i]));
        }
      } catch (...) {
        throw;
      }
      size_ = v.size_;
    } else {
      clear();
      vector<T> new_vector(v);
      swap(new_vector);
    }
    return *this;
  };

  /*
  \brief Move assignment operator. Replaces the contents with those of other
  using move semantics. \param[in] v another container to use as data source
  \details https://en.cppreference.com/w/cpp/container/vector/operator%3D
  */
  vector &operator=(vector &&v) noexcept {
    clear();
    vector new_vector(std::move(v));
    swap(new_vector);
    return *this;
  };

  /*
  \brief Returns a reference to the element at specified location pos,
  with bounds checking.
  \exception If pos is not within the range of the container,
  an exception of type std::out_of_range is thrown.
  */
  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range(__FILE__ + __LINE__);
    }
    return *(arr_ + pos);
  };

  /*
  \brief Returns a reference to the element at specified location pos.
  \warning No bounds checking is performed.
  */
  reference operator[](size_type pos) { return arr_[pos]; };

  /*
  \brief Returns a reference to the first element in the container.
  \warning Calling back on an empty container causes undefined behavior.
  */
  const_reference front() { return *(arr_); };

  /*
  \brief Returns a reference to the last element in the container.
  \warning Calling back on an empty container causes undefined behavior.
  */
  const_reference back() { return *(arr_ + size_ - 1); };

  /*
  \brief Returns pointer to the underlying array serving as element storage.
  */
  pointer data() const noexcept { return arr_; };

  /*
  \brief Returns an iterator to the first element of the vector.
  \details If the vector is empty, the returned iterator will be equal to end().
  */
  iterator begin() noexcept { return iterator(arr_); };

  /*
  \brief Returns an iterator to the element following the last element of the
  vector. \details This element acts as a placeholder; attempting to access it
  results in undefined behavior.
  */
  iterator end() noexcept { return iterator(arr_ + size_); };

  /*
  \brief Returns an const iterator to the first element of the vector.
  \details If the vector is empty, the returned iterator will be equal to end().
  */
  const_iterator cbegin() const noexcept { return const_iterator(arr_); };

  /*
  \brief Returns an const iterator to the element following the last element of
  the vector. \details This element acts as a placeholder; attempting to access
  it results in undefined behavior.
  */
  const_iterator cend() const noexcept { return const_iterator(arr_ + size_); };

  /*
  \brief Checks if the container has no elements,.
  */
  bool empty() const noexcept {
    bool res = false;
    if (cbegin() == cend()) {
      res = true;
    }
    return res;
  };

  /*
  \brief Returns the number of elements in the container.
  */
  size_type size() const noexcept { return size_; };

  /*
  \brief Returns the maximum number of elements the container is able to hold
  due to system or library implementation limitations.
  */
  size_type max_size() const noexcept { return traits::max_size(alloc_); };

  /*
  \brief Increase the capacity of the vector
  \param[in] new_cap  	new capacity of the vector, in number of elements
  \details (the total number of elements that the vector can hold without
  requiring reallocation) to a value that's greater or equal to new_cap.
  If new_cap is greater than the current capacity(),
  new storage is allocated, otherwise the function does nothing.
  Strong exeption guarantee!
  */
  void reserve(size_type new_cap) {
    if (new_cap <= capacity()) {
      return;
    }
    if (new_cap > max_size()) {
      throw std::length_error("size > max_size/reserve/vector\n");
    }
    pointer new_data = traits::allocate(alloc_, new_cap);

    try {
      std::uninitialized_move(begin(), end(), new_data);  // 58 min vector video
      for (auto itr = begin(); itr != end(); ++itr) {
        traits::destroy(alloc_, std::addressof(*itr));
      };

      traits::deallocate(alloc_, arr_, capacity());
      arr_ = new_data;
      capacity_ = new_cap;
    } catch (...) {
      traits::deallocate(alloc_, new_data, new_cap);
      throw;
    }
  }

  /*
  \brief Returns the number of elements that the container has currently
  allocated space for.
  */
  size_type capacity() const noexcept { return capacity_; };

  /*
  \brief Requests the removal of unused capacity.
  */
  void shrink_to_fit() {
    if (capacity_ == size_) {
      return;
    }
    traits::deallocate(alloc_, arr_, size_);
    capacity_ = size_;
  };

  /*
  \brief Erases all elements from the container.
  \details After this call, size() returns zero.
  Invalidates any references, pointers, or iterators
  referring to contained elements.
  Any past-the-end iterators are also invalidated.
  */
  void clear() noexcept {
    if constexpr (!std::is_trivially_destructible_v<
                      T>) {  // проверки, является ли T тривиально разрушаемым
      for (auto itr = begin(); itr != end(); ++itr) {
        traits::destroy(alloc_, std::addressof(*itr));
      }
    }
    size_ = 0;
  };

  /*
  \brief Insert element before pos.
  \param[in] pos iterator to the element to insert
  \param[in] value value to the element to insert
  \return Iterator pointing to the inserted value
  */
  iterator insert(iterator pos, const_reference value) {
    size_type index = std::distance(begin(), pos);
    if (pos == end()) {
      push_back(value);
      return begin() + index;
    }
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    std::uninitialized_move(end() - 1, end(), end());
    for (size_type i = size_; i > index; --i) {
      arr_[i] = std::move_if_noexcept(arr_[i - 1]);
    }
    traits::construct(alloc_, std::addressof(arr_[index]), value_type(value));
    ++size_;
    return begin() + index;
  };

  /*
  \brief Removes the element at pos.
  \param[in] pos iterator to the element to remove
  \return Iterator following the last removed element.
  If pos refers to the last element, then the end() iterator is returned.
  */
  iterator erase(iterator pos) {
    if (pos == end()) {  // The iterator pos must be valid and dereferenceable.
      return end();
    }
    if (pos == std::prev(end())) {
      pop_back();
      return end();
    }
    size_type index = std::distance(begin(), pos);
    traits::destroy(alloc_, std::addressof(*pos));
    for (; index < size_ - 1; ++index) {
      arr_[index] = std::move_if_noexcept(arr_[index + 1]);
    }
    size_--;
    return begin() + index;
  };

  /*
  \brief Appends the given element value to the end of the container.
  \param[in] value the value of the element to append
  \details
  1) The new element is initialized as a copy of value.
  2) value is moved into the new element.
  If after the operation the new size() is greater than old capacity()
  a reallocation takes place, in which case all iterators (including
  the end() iterator) and all references to the elements are invalidated.
  Otherwise only the end() iterator is invalidated.
  */
  void push_back(const_reference value) {
    if (capacity_ == 0) {
      reserve(capacity() + 1);
    }
    if (capacity_ == size_) {
      reserve(capacity() * 2);
    }
    traits::construct(alloc_, std::addressof(*(end())), value_type(value));
    size_++;
  };

  /*
  \brief Removes the last element of the container.
  \details Calling pop_back on an empty container results in undefined behavior.
  Iterators (including the end()
  iterator) and references to the last element are invalidated.
  */
  void pop_back() noexcept {
    traits::destroy(alloc_, std::addressof(*(std::prev(end()))));
    size_--;
  };

  /*
  \brief Exchanges the contents and capacity of the container with those of
  other. \param[in] other container to exchange the contents with
  */
  void swap(vector &other) noexcept {
    std::swap(alloc_, other.alloc_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
    std::swap(arr_, other.arr_);
  };

  /*
  \brief Resizes the container to contain count elements, does nothing if count
  == size(). \param[in] n new size of the container
  */
  void resize(size_type n) {
    if (n == size_) {
      return;
    }
    if (n > capacity_) {
      reserve(n);
      size_ = n;
    }
    if (n < capacity_) {
      size_ = n;
    }
  };

 private:
  Allocator alloc_;
  size_type size_;
  size_type capacity_;
  pointer arr_;
};

/*
\brief Implementation self-made iterator, based on std::bidirectional_iterator
type \param[in] T value template \param[in] is_const const bool flag \details
https://internalpointers.com/post/writing-custom-iterators-modern-cpp
*/

template <typename T, bool is_const>
struct Iterator {
 public:
  friend class vector<T>;
  using iterator_category = std::bidirectional_iterator_tag;
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using pointer = std::conditional_t<is_const, const T *, T *>;
  using reference = std::conditional_t<is_const, const T &, T &>;

  Iterator() : value_(nullptr){};

  Iterator(pointer val) : value_(val){};

  Iterator operator+(const Iterator &other) const {
    Iterator tmp = *this;
    while (tmp != other) {
      ++tmp;
    }
    return tmp;
  }

  Iterator operator-(const Iterator &other) const {
    Iterator tmp = *this;
    while (tmp != other) {
      --tmp;
    }
    return tmp;
  }

  Iterator operator+(int n) const {
    Iterator tmp = *this;
    for (int i = 0; i < n; i++) {
      ++tmp;
    }
    return tmp;
  };

  Iterator operator-(int n) const {
    Iterator tmp = *this;
    for (int i = 0; i < n; i++) {
      --tmp;
    }
    return tmp;
  };
  Iterator operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
  };

  Iterator operator--(int) {
    Iterator tmp = *this;
    --(*this);
    return tmp;
  };

  Iterator &operator++() {
    value_++;
    return *this;
  };  // prefix

  Iterator &operator--() {
    value_--;
    return *this;
  };  // prefix

  friend bool operator<=(const Iterator &a, const Iterator &b) {
    return (a.value_ <= b.value_);
  };
  friend bool operator>=(const Iterator &a, const Iterator &b) {
    return (a.value_ >= b.value_);
  }
  friend bool operator<(const Iterator &a, const Iterator &b) {
    return (a.value_ < b.value_);
  };
  friend bool operator>(const Iterator &a, const Iterator &b) {
    return (a.value_ > b.value_);
  };
  friend bool operator!=(const Iterator &a, const Iterator &b) {
    return (a.value_ != b.value_);
  };
  friend bool operator==(const Iterator &a, const Iterator &b) {
    return (a.value_ == b.value_);
  };

  reference operator*() const { return *value_; };

  pointer operator->() const { return value_; };

 private:
  pointer value_;
};

}  // namespace s21

#endif  // S21_CONTAINER_SRC_VECTOR_S21_VECTOR_H_
