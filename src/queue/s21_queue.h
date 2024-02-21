#ifndef CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();

  queue &operator=(const queue &other);
  queue &operator=(queue &&other);

  const_reference front() const;
  const_reference back() const;

  bool empty() const;
  size_type size() const;

  void push(const_reference value);
  void pushInFrontForStack(const_reference value);
  void pop();
  void swap(queue &other);

  template <class... Args>
  void insert_many_back(Args &&...args);

  void clear();

 private:
  struct Node {
    value_type value_;
    Node *prev_;
    Node *next_;
    Node() : value_(value_type{}), prev_(), next_(){};
  };

  size_t size_;
  Node *head_;
  Node *tail_;
  Node *end_;  // указатель на следующий элемент после последнего
               // end имеет указатель на посл. элемент, а сам элемент не имеет
               // указатель на end
};
}  // namespace s21

#include "s21_queue.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
