/*
\author superboy
\date 26.01.2024
*/

#ifndef S21_CONTAINER_SRC_SET_S21_SET_H_
#define S21_CONTAINER_SRC_SET_S21_SET_H_

#include <iostream>
#include <initializer_list>
#include <memory>
#include <iterator>
#include <limits>
#include <rbtree.h>

namespace s21 {

template<typename Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>>
class set {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = RBIterator<Key, false>;
        using const_iterator = RBIterator<Key, true>;
        using size_type = size_t;

    
        set() {};
        set(std::initializer_list<value_type> const &items);
        set(const set &s);
        set(set &&s);
        ~set();
        set& operator=(set &&s);

        iterator begin() { return iterator(node_); };
        iterator cbegin() { return const_iterator(node_); };
        iterator end() { return iterator(node_ + size_); };
        iterator cend() { return const_iterator(node_ + size_); };

    private:
        rbtree_node_ptr node_;
        Allocator alloc_;
        Compare comp_;
        size_type size_;
};

}

#endif  // S21_CONTAINER_SRC_SET_S21_SET_H_
