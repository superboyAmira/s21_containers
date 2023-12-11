#ifndef S21_CONTAINER_SRC_S21_VECTOR_H_
#define S21_CONTAINER_SRC_S21_VECTOR_H_

#include <iostream>
#include <initializer_list>

template <typename T>
class s21_vector {
    private:
        T value_type;
        T& reference;
        const T& const_reference;
        T* iterator;
        const T* iterator;
        size_t size_type;

    public:
        s21_vector();
        s21_vector(size_t n);
        s21_vector(std::initializer_list<value_type> const &items);
        s21_vector(const vector &v);
        s21_vector(vector &&v);
        ~s21_vector();
        operator=(vector &&v);

        reference at(size_type pos);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();
        T* data();

        iterator begin();
        iterator end();

        bool empty();
        size_type size();
        size_type max_size();
        void reserve(size_type size);
        size_type capacity();
        void shrink_to_fit();

        void clear();
        iterator insert(iterator pos, const_reference value);
        void erase(iterator pos);
        void push_back(const_reference value);
        void pop_back();
        void swap(vector& other);

};

#endif  // S21_CONTAINER_SRC_S21_VECTOR_H_