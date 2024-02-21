#include "s21_queue.h"

namespace s21 {

/**
 * Constructor for the queue class.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
template <typename T>
queue<T>::queue() : size_(0), head_(nullptr), tail_(nullptr), end_(nullptr) {}

/**
 * Constructor for the queue class.
 *
 * @param items
 *
 * @return None
 *
 * @throws None
 */
template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) : queue() {
  for (auto item : items) {
    push(item);
  }
}

/**
 * Constructor for creating a queue as a copy of another queue.
 *
 * @param q The queue to be copied
 *
 * @return
 *
 * @throws
 */
template <typename T>
queue<T>::queue(const queue &q) : queue() {
  Node *copyNode = q.head_;
  while (copyNode) {
    push(copyNode->value_);
    copyNode = copyNode->next_;
  }
}

/**
 * Move constructor for the queue class.
 *
 * @param q The queue to be moved from.
 *
 * @return
 *
 * @throws
 */
template <typename T>
queue<T>::queue(queue &&q) {
  head_ = q.head_;
  tail_ = q.tail_;
  size_ = q.size_;
  q.size_ = 0;
  q.head_ = nullptr;
  q.tail_ = nullptr;
}

/**
 * Destructor for the queue class.
 *
 */
template <typename T>
queue<T>::~queue() {
  clear();
}

template <typename T>
typename queue<T>::queue &queue<T>::operator=(const queue &q) {
  if (this != &q) {
    while (!empty()) {
      pop();
    }
    Node *copyNode = q.head_;
    while (copyNode) {
      push(copyNode->value_);
      copyNode = copyNode->next_;
    }
  }
  return *this;
}

template <typename T>
typename queue<T>::queue &queue<T>::operator=(queue &&q) {
  if (this != &q) {
    while (!empty()) {
      pop();
    }
    size_ = q.size_;
    head_ = q.head_;
    tail_ = q.tail_;
    q.size_ = 0;
    q.head_ = nullptr;
    q.tail_ = nullptr;
  }
  return *this;
}

/**
 * Returns the front element of the queue.
 *
 * @return const_reference the front element of the queue
 */
template <typename T>
typename queue<T>::const_reference queue<T>::front() const {
  return head_->value_;
}

/**
 * Returns the value at the back of the queue.
 *
 * @return const_reference the value at the back of the queue
 */
template <typename T>
typename queue<T>::const_reference queue<T>::back() const {
  return tail_->value_;
}

/**
 * Checks if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise
 */
template <typename T>
bool queue<T>::empty() const {
  return head_ == nullptr;
}

/**
 * Returns the size of the queue.
 *
 * @return The size of the queue.
 */
template <typename T>
typename queue<T>::size_type queue<T>::size() const {
  return size_;
}

/**
+ * Pushes a new element onto the back of the queue.
+ *
+ * @param value the value to be added to the queue
+ *
+ * @return void
+ *
+ * @throws None
+ */

template <typename T>
void queue<T>::push(const_reference value) {
  Node *node = new Node;
  node->value_ = value;
  node->prev_ = tail_;
  node->next_ = nullptr;
  if (tail_) {
    tail_->next_ = node;
  }
  tail_ = node;
  if (head_ == nullptr) {
    head_ = node;
  }
  ++size_;
}

template <typename T>
void queue<T>::pushInFrontForStack(const_reference value) {
  Node *node = new Node;
  node->value_ = value;
  node->next_ = head_;
  node->prev_ = nullptr;
  if (head_) {
    head_->prev_ = node;
  }
  head_ = node;
  if (tail_ == nullptr) {
    tail_ = node;
  }
  ++size_;
}

/**
 * Removes and returns the front element of the queue.
 *
 * @return void
 *
 * @throws None
 */
template <typename T>
void queue<T>::pop() {
  if (head_) {
    Node *node = head_;
    head_ = head_->next_;
    if (head_) {
      head_->prev_ = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete node;
    --size_;
  }
}

/**
 * Swaps the content of this queue with another queue.
 *
 * @param other The queue to swap with
 *
 * @return No return value
 *
 * @throws No specific exceptions
 */
template <typename T>
void queue<T>::swap(queue &other) {
  std::swap(size_, other.size_);
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
}

/**
 * Clears the queue by repeatedly popping elements until it is empty.
 */
template <typename T>
void queue<T>::clear() {
  while (!empty()) {
    pop();
  }
}

/**
 * Insert multiple elements to the back of the queue.
 *
 * @param args the elements to insert
 *
 * @return void
 *
 * @throws None
 */
template <class T>
template <class... Args>
void queue<T>::insert_many_back(Args &&...args) {
  for (const auto &arg : {args...}) {
    push(arg);
  }
}

}  // end of namespace s21
