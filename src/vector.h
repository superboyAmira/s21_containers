#ifndef S21_CONTAINER_SRC_VECTOR_H_
#define S21_CONTAINER_SRC_VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <memory>
#include <iterator>
#include <limits>

namespace containers {

// template <typename T, bool IsConst>
// class Iterator;
template <typename T, bool is_const>
struct Iterator;


template <typename T, typename Allocator = std::allocator<T>>
class Vector {
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

        Vector() noexcept : alloc_(Allocator()), size_(0), capacity_(0), arr_(nullptr) {};
        
        Vector(size_t n, const Allocator& alloc = Allocator()) : alloc_(alloc), size_(n), capacity_(n) {
            arr_ = traits::allocate(alloc_, n);
            for (size_type i = 0; i != n; i++) {
                try{
                    traits::construct(alloc_, std::addressof(*(arr_ + i)), std::move(value_type()));
                } catch (...) {
                    traits::destroy(alloc_, arr_ + i);
                    traits::deallocate(alloc_, arr_, capacity_);
                    throw;
                }
            }
        };
        
        Vector(std::initializer_list<value_type> const &items, const Allocator& alloc = Allocator()) : alloc_(alloc), size_(items.size()), capacity_(items.size()), arr_(nullptr) {
            arr_ = std::allocator_traits<Allocator>::allocate(alloc_, items.size());
            std::uninitialized_copy(items.begin(), items.end(), arr_);
        };

        Vector(Vector &v) : alloc_(std::allocator_traits<Allocator>::select_on_container_copy_construction(v.alloc_)), size_(v.size_), capacity_(v.capacity_) {
            arr_ = traits::allocate(alloc_, capacity_);
  
            for (auto itr_v = v.cbegin(), itr = begin(); itr_v != v.cend(); ++itr_v, ++itr) {
                traits::construct(alloc_, std::addressof(*itr), *itr_v);
            }
        };


        Vector(Vector &&v) noexcept : alloc_ (std::allocator_traits<Allocator>::select_on_container_copy_construction(v.alloc_)), size_(v.size_), capacity_(v.capacity_), arr_(std::move(v.arr_)) {
            v.arr_ = nullptr;
            v.size_ = 0;
            v.capacity_ = 0;
        };

        /*
        Destructs the vector. 
        The destructors of the elements 
        are called and the used storage is deallocated.
        */
        ~Vector() noexcept {
            for (auto itr = begin(); itr != end(); ++itr) {
                traits::destroy(alloc_, std::addressof(*itr));
            }
            traits::deallocate(alloc_, arr_, capacity_);
            arr_ = nullptr;
            size_ = 0;
            capacity_ = 0;
        };

        Vector& operator=(const Vector &v) {
            if (this == &v) {
                return *this;
            }
            
            if (v.capacity() < capacity()) {
                try {
                    for (auto itr = begin(), i = 0; itr != end(); ++itr, ++i) {
                        traits::destroy(alloc_, std::addressof(*itr));
                        traits::construct(alloc_, std::addressof(*itr), value_type(v.arr_[i]));
                    }
                } catch (...) {
                    throw;
                }
                size_ = v.size_;
            } else {
                clear();
                Vector<T> new_vector(v);
                swap(new_vector);
            }
            return *this;
        };


        Vector& operator=(Vector &&v) noexcept {
            // if (traits::propagate_on_container_move_assignment::value == true) {
                clear();
                Vector new_vector(std::move(v));
                swap(new_vector);
            // } else {
                // ... https://en.cppreference.com/w/cpp/container/vector/operator%3D
            // }
            return *this;
        };


        /*
        Returns a reference to the element at specified location pos,
        with bounds checking.
        If pos is not within the range of the container, 
        an exception of type std::out_of_range is thrown. 
        */
        reference at(size_type pos) {
            if (pos >= size_) {
                throw std::out_of_range(__FILE__ + __LINE__);
            }
            return *(arr_ + pos);
        };

        /*
        Returns a reference to the element at specified location pos. 
        No bounds checking is performed. 
        */
        reference operator[](size_type pos) {
            return arr_[pos];
        };

        /*
        Returns a reference to the first element in the container.

        Calling front on an empty container causes undefined behavior.
        */
        const_reference front() {
            return *(arr_);
        };

        /*
        Returns a reference to the last element in the container.

        Calling back on an empty container causes undefined behavior. 
        */
        const_reference back() {
            return *(arr_ + size_ - 1);
        };

        /*
        Returns pointer to the underlying array serving as element storage.
        The pointer is such that range [data(), data() + size()) is always a valid range,
        even if the container is empty (data() is not dereferenceable in that case). 
        */
        pointer data() const noexcept {
            return arr_;
        };

        /*
        Returns an iterator to the first element of the vector.
        If the vector is empty, the returned iterator will be equal to end(). 
        */
        iterator begin() noexcept {
            return iterator(arr_);
        };

        /*
        Returns an iterator to the element following the last element of the vector.
        This element acts as a placeholder; attempting to access it results in undefined behavior. 
        */
        iterator end() noexcept {
            return iterator(arr_ + size_);
        };

        const_iterator cbegin() const noexcept {
            return const_iterator(arr_);
        };

        const_iterator cend() const noexcept {
            return const_iterator(arr_ + size_);
        };

        /*
        Checks if the container has no elements, i.e. whether begin() == end(). 
        */
        bool empty() const noexcept {
            bool res = false;
            if (cbegin() == cend()) {
                res = true;
            }
            return res;
        };

        /*
        Returns the number of elements in the container, i.e. std::distance(begin(), end())
        */
        size_type size() const noexcept {
            return size_;
        };

        /*
        Returns the maximum number of elements the container is
        able to hold due to system or library implementation limitations, 
        i.e. std::distance(begin(), end()) for the largest container. 
        */
        size_type max_size() const noexcept {
            return traits::max_size(alloc_) / sizeof(T);
        };

        /*
        Increase the capacity of the vector 
        (the total number of elements that the vector can hold without 
        requiring reallocation) to a value that's greater or equal to new_cap. 
        If new_cap is greater than the current capacity(), 
        new storage is allocated, otherwise the function does nothing.

        Strong exeption guarantee!
        */
        void reserve(size_type size) {
            if (size <= capacity()) {
                return;
            }
            if (size > max_size()) {
                throw std::length_error("size > max_size/reserve/vector\n");
            }
            pointer new_data = traits::allocate(alloc_, size);

            try {
                std::uninitialized_move(begin(), end(), new_data); // 58 min vector video
                for (auto itr = begin(); itr != end(); ++itr) { traits::destroy(alloc_, std::addressof(*itr)); };

                traits::deallocate(alloc_, arr_, capacity());
                arr_ = new_data;
                capacity_ = size;
            }
            catch (...) {
                traits::deallocate(alloc_, new_data, size);
                throw;
            }
        }


        /*
        Returns the number of elements that the container has currently allocated space for. 
        */
        size_type capacity() const noexcept {
            return capacity_;
        };

        /*
        
        */
        void shrink_to_fit() {
            if (capacity_ == size_) {
                return;
            }
            traits::deallocate(alloc_, arr_, size_);
            capacity_ = size_;
        };

        /*
        Erases all elements from the container. After this call, size() returns zero.
        Invalidates any references, pointers, or iterators
        referring to contained elements.
        Any past-the-end iterators are also invalidated.
        */
        void clear() noexcept {
            if constexpr (!std::is_trivially_destructible_v<T>) { // проверки, является ли T тривиально разрушаемым
                for (auto itr = begin(); itr != end(); ++itr) {
                    traits::destroy(alloc_, std::addressof(*itr));
                }
            }
            size_ = 0;
        }

        /*
        Inserts value before pos.
        */
        iterator insert(iterator pos, const_reference value) {
            size_t index = std::distance(begin(), pos);
            if (pos == end()) {
                push_back(value);
                return begin() + index;
            }
            if (size_ == capacity_) {
                reserve(capacity_ == 0 ? 1 : capacity_ * 2);
            }
            std::uninitialized_move(end() - 1, end(), end());
            for (size_type i = size_; i > index; --i) {
                arr_[i] = std::move(arr_[i - 1]);
            }
            // new (&arr_[index]) value_type(value);
            traits::construct(alloc_, std::addressof(arr_[index]), value_type(value));
            ++size_;
            return begin() + index;
        }

        /*
         Removes the element at pos.
        */
        void erase(iterator pos) {
            if (pos == end()) { // The iterator pos must be valid and dereferenceable.
                return;
            }
            traits::destroy(alloc_, std::addressof(*pos));
            // std::uninitialized_move(pos, end(), end() + 1);
            // traits::construct(alloc_, std::addressof(*(begin() + pos)), value_type(value));
            // ++size_;
            // return begin() + pos;
            
            // size_type new_size = size_ - 1;
            // pointer new_arr = nullptr;
            // size_type new_capacity = new_size;

            // new_arr = traits::allocate(alloc_, new_capacity);
            // try {
            //     std::uninitialized_copy(begin(), pos - 1, new_arr);
            //     std::uninitialized_copy(pos, end(), new_arr + *pos);
            // } catch (...) {
            //     traits::deallocate(alloc_, new_arr, new_capacity);
            //     throw;
            // }
            // for (auto it = begin(); it != end(); ++it) {
            //     traits::destroy(alloc_, arr_, it);
            // }
            // traits::deallocate(alloc_, arr_, capacity_);

            // arr_ = new_arr;
            // capacity_ = new_capacity;
            // size_ = new_size;
        };

        /*
        Appends the given element value to the end of the container.
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
        Removes the last element of the container.
        Calling pop_back on an empty container results in undefined behavior.
        Iterators (including the end() 
        iterator) and references to the last element are invalidated. 
        */
        void pop_back() noexcept {
            traits::destroy(alloc_, std::addressof(*(std::prev(end()))));
            size_--;
        };

        void swap(Vector &other) noexcept {
            std::swap(alloc_, other.alloc_);
            std::swap(size_, other.size_);
            std::swap(capacity_, other.capacity_);
            std::swap(arr_, other.arr_);
        };

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

        // void print() {
        //     T t[capacity_];
        //     for (auto itr = 0, i = 0; itr != capacity_; ++itr, i++) {t[i] = arr_[itr];};
        // }

    private:
        Allocator alloc_;
        size_type size_;
        size_type capacity_;
        pointer arr_;
};

// https://internalpointers.com/post/writing-custom-iterators-modern-cpp
template <typename T, bool is_const>
struct Iterator {
    public:
        friend class Vector<T>;
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = std::conditional_t<is_const, const T*, T*>;
        using reference         = std::conditional_t<is_const, const T&, T&>;

        Iterator() : value_(nullptr) {};

        Iterator(pointer val) : value_(val) {};
        
        Iterator operator+(const Iterator& other) const {
            Iterator tmp = *this;
            while (tmp != other) {
                ++tmp;
            }
            return tmp;
        }

        Iterator operator-(const Iterator& other) const {
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
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; };

        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; };

        Iterator& operator++() { value_++; return *this; }; // prefix

        Iterator& operator--() { value_--; return *this; }; // prefix

        friend bool operator<=(const Iterator &a ,const Iterator &b) {
            return (a.value_ <= b.value_);
        };
        friend bool operator>=(const Iterator &a, const Iterator &b) {
            return (a.value_ >= b.value_);
        }
        friend bool operator<(const Iterator &a, const Iterator &b) {
            return (a.value_ < b.value_);
        };
        friend bool operator>(const Iterator &a,const Iterator &b) {
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

}
#endif  // S21_CONTAINER_SRC_VECTOR_H_
