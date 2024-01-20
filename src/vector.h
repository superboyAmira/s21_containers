#ifndef S21_CONTAINER_SRC_VECTOR_H_
#define S21_CONTAINER_SRC_VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <memory>
#include <iterator>
#include <limits>

namespace s21 {

template <typename T, typename Allocator = std::allocator<T>>
class Vector {
    private:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using pointer = T *;
        using const_pointer = const T *;
        using iterator = Iterator<T, false>;
        using const_iterator = Iterator<T, true>;
        using size_type = size_t;
        // using traits = std::allocator_traits<Allocator>;

    private:
        Allocator alloc_;
        size_type size_;
        size_type capacity_;
        T* arr_;

    public:
        Vector() noexcept : size_(0), capacity_(0), arr_(nullptr) {};
        Vector(size_t n) {
            
        };
        Vector(std::initializer_list<value_type> const &items);
        Vector(const vector &v) {
            std::allocator_traits<Allocator>::select_on_container_copy_construction(alloc_);
        };
        Vector(vector &&v);

        /*
        Destructs the vector. 
        The destructors of the elements 
        are called and the used storage is deallocated.
        */
        ~Vector() noexcept {
            for (auto itr = begin(); itr != end(); ++itr) {
                std::allocator_traits<Allocator>::destroy(alloc_, itr);
            }
            std::allocator_traits<Allocator>::deallocate(alloc_, arr_, capacity_);
            arr_ = nullptr;
        };

        operator=(vector &&v);


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
            return *(begin() + pos);
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
            return *(begin());
        };

        /*
        Returns a reference to the last element in the container.

        Calling back on an empty container causes undefined behavior. 
        */
        const_reference back() {
            return *(begin() + size_ - 1);
        };

        /*
        Returns pointer to the underlying array serving as element storage.
        The pointer is such that range [data(), data() + size()) is always a valid range,
        even if the container is empty (data() is not dereferenceable in that case). 
        */
        T* data() {
            return array_;
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

        /*
        Checks if the container has no elements, i.e. whether begin() == end(). 
        */
        bool empty() const noexcept {
            bool res = false;
            if (begin() == end()) {
                res = true;
            }
            return res;
        };

        /*
        Returns the number of elements in the container, i.e. std::distance(begin(), end())
        */
        size_type size() const noexcept {
            return std::distance(begin(), end());
        };

        /*
        Returns the maximum number of elements the container is
        able to hold due to system or library implementation limitations, 
        i.e. std::distance(begin(), end()) for the largest container. 
        */
        size_type max_size() const noexcept {
            return std::allocator_traits<Allocator>::max_size(Allocator{}) / sizeof(T);
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
            if (size <= capacity) {
                return;
            }
            if (size > max_size()) {
                throw std::length_error("size > max_size::reserve::vector\n");
            }

            T* new_arr = reinterpret_cast<T*>(new int8_t[size * sizeof(T)]);
            size_type iterator = 0;
            try {
                std::uninitialized_copy(arr_, arr_ + size, new_arr);
            } catch (...) {
                delete[] reinterpret_cast<int8_t>(new_arr);
                throw std::bad_alloc("bad alloc_::reserve::vector");
            }
            arr_ = new_arr;
            capacity_ = size;
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
            std::allocator_traits<Allocator>::deallocate(alloc_, arr_, size_);
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
                    std::allocator_traits<Allocator>::destroy(alloc_, std::addressof(*itr));
                }
            }
            size_ = 0;
        }

        iterator insert(iterator pos, const_reference value) {
            
        };
        void erase(iterator pos);

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
            using traits = std::allocator_traits<Allocator>;
            
            if (size_ == capacity_) {
                T* new_arr = traits::allocate(capacity_ * 2);

                for (size_type i = 0; i < size; ++i) {
                    traits::construct(alloc_, std::addressof(new_arr + i), std::move_if_noexcept(value));
                    traits::destroy(alloc, arr_ + i);
                }
            }
            traits::deallocate(arr_, size_);
            arr_ = new_arr;
            size_++;
        };

        /*
        Removes the last element of the container.
        Calling pop_back on an empty container results in undefined behavior.
        Iterators (including the end() 
        iterator) and references to the last element are invalidated. 
        */
        void pop_back() {

        };
        void swap(vector& other);

};

template <typename T, bool IsConst>
class Iterator {
    public:
        friend class s21::Vector<T>;
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using pointer = T *;
        using const_pointer = const T *;
        using size_type = size_t;
        using conditional_ptr = std::conditional_t<IsConst, const_pointer, pointer>;
        using conditional_ref = std::conditional_t<IsConst, const_reference, reference>;

        Iterator() : val(nullptr) {};
        Iterator(value) : val(value) {};
        conditional_ref operator+(int n) { return *(value + n); }
        conditional_ref operator-(int n) { return *(value - n); }
        conditional_ref operator++(int) { return *(value++); }
        conditional_ref operator--(int) { return *(value--); }
        conditional_ref operator++() { return *(value++); }
        conditional_ref operator--() { return *(value--); }
        bool operator<=(const CommonIterator &other) const {
            return (value <= other.value);
        }
        bool operator>=(const CommonIterator &other) const {
            return (value >= other.value);
        }
        bool operator<(const CommonIterator &other) const {
            return (value < other.value);
        }
        bool operator>(const CommonIterator &other) const {
            return (value > other.value);
        }
        bool operator!=(const CommonIterator &other) const {
            return (value != other.value);
        }
        bool operator==(const CommonIterator &other) const {
            return (value == other.value);
        }
        conditional_ref operator*() const { return *value; }
        conditional_ptr operator->() const { return value; }

    private:
        conditional_ptr val; 
};

}

#endif  // S21_CONTAINER_SRC_VECTOR_H_