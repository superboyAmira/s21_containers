#include "s21_list.h"

namespace s21 {

    // === constructors === //
    template<typename T>
    S21list<T>::S21list() : size_(0), head_(nullptr), tail_(nullptr), end_(nullptr) {
        this->end_ = new Node();
    }

    template<typename T>
    S21list<T>::S21list(size_t size) : size_(size), end_(nullptr) {
        if(size < 0) throw std::out_of_range("Error: Invalid size of created list");
        else if(size == 0) this->end_ = new Node();
        else {
            for(auto i = 0; i < size; i++)
                this->push_back(nullptr);
        }
    }

    template<typename T>
    S21list<T>::~S21list() {
        while(!empty()) {
            pop_back();
        }
        delete end_;
    }

    // TODO: непонятно, в какой позиции находится end_
    // === methods === //
    template<typename T>
    void S21list<T>::push_front(T value) {
        Node *new_node = new Node(value);
        if(empty()) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            head_->prev_ = new_node;
            new_node->next_ = head_;
            head_ = new_node;
        }
        size_++;
    }

    template<typename T>
    void S21list<T>::push_back(T value) {
        Node *new_node = new Node(value);
        if(empty()) {
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->next_ = new_node;
            new_node->prev_ = tail_;
            tail_ = new_node;
        }
        size_++;
    }

    template<typename T> // ну и булдыга конечно
    void S21list<T>::pop_front() {
        if(empty()) throw std::out_of_range("Error: List is empty");
        if(size_ == 1) {
            delete head_;
            tail_ = nullptr;
        } else {
            Node *new_head = head_->next_;
            head_->next_->prev_ = nullptr;
            delete head_;
            head_ = new_head;
        }
        size_--;
    }

    template<typename T>
    void S21list<T>::pop_back() {
        if(empty()) throw std::out_of_range("Error: List is empty");
        if(size_ == 1) {
            delete tail_;
            head_ = nullptr;
        } else {
            Node *new_tail = tail_->prev_;
            tail_->prev_->next_ = nullptr;
            delete tail_;
            tail_ = new_tail;
        }
        size_--;
    }

    template<typename T>
    size_t S21list<T>::size() {
        return size_;
    }

    template<typename T>
    bool S21list<T>::empty() {
        return head_ == nullptr && tail_ == nullptr;
    }

} // namespace s21
