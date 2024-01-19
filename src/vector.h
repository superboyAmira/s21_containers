#ifndef S21_CONTAINER_SRC_S21_VECTOR_H_
#define S21_CONTAINER_SRC_S21_VECTOR_H_

#include <iostream>
#include <initializer_list>
#include <memory>
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
        using iterator = VectorIterator<T, false>;
        using const_iterator = CommonIterator<T, true>;
        using size_type = size_t;

    private:
        Allocator alloc_;
        size_type size_;
        size_type capacity_;
        T* arr_;

    public:
        Vector() noexcept : size_(0), capacity_(0), arr_(nullptr) {};
        Vector(size_t n);
        Vector(std::initializer_list<value_type> const &items);
        Vector(const vector &v) {
            std::allocator_traits<Allocator>::select_on_container_copy_construction(alloc_);
        };
        Vector(vector &&v);
        ~Vector();
        operator=(vector &&v);

        reference at(size_type pos);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();
        T* data();

        iterator begin();
        iterator end();

        /*
        Checks if the container has no elements, i.e. whether begin() == end(). 
        */
        bool empty() const noexcept {
            bool res = false;
            if (this->begin() == this->end()) {
                res = true;
            }
            return res;
        };

        size_type size();

        /*
        Returns the number of elements in the container, i.e. std::distance(begin(), end()). 
        */
        size_type max_size() const noexcept {
            return std::distance(this->begin(), this->end());
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
            if (size > this->max_size()) {
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

        size_type capacity();
        void shrink_to_fit();

        /*
        Erases all elements from the container. After this call, size() returns zero.
        Invalidates any references, pointers, or iterators
        referring to contained elements.
        Any past-the-end iterators are also invalidated.
        */
        void clear() noexcept {
            for (auto i = 0; size_) {
                (arr_ + i)->~T();
            }
            size_ = 0;
        };
        iterator insert(iterator pos, const_reference value);
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
        void pop_back();
        void swap(vector& other);

};

}

#endif  // S21_CONTAINER_SRC_S21_VECTOR_H_