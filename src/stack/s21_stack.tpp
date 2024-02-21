#include "s21_stack.h"

namespace s21 {
/**
 * Constructor for the stack class.
 */
template <class T, class Container>
stack<T, Container>::stack() : queue_() {}

/**
 * Constructor for the stack class that initializes the stack with the elements
 * from the given initializer list.
 *
 * @param items The initializer list of elements to initialize the stack with
 *
 */
template <class T, class Container>
stack<T, Container>::stack(std::initializer_list<value_type> const& items) {
  for (auto i = items.begin(); i != items.end(); i++) push(*i);
}

/**
 * Copy constructor for the stack class.
 *
 * @param other The stack to be copied
 *
 */
template <class T, class Container>
stack<T, Container>::stack(const stack& other) : queue_(other.queue_) {}

/**
 * Move constructor for the stack class.
 *
 * @param other The stack to be moved from
 *
 * @return
 *
 * @throws
 */
template <class T, class Container>
stack<T, Container>::stack(stack&& other) : queue_(std::move(other.queue_)) {}

/**
 * Destructor for the stack class.
 */
template <class T, class Container>
stack<T, Container>::~stack() {}

/**
 * Swaps the contents of this stack with another stack.
 *
 * @param other The stack to swap with
 */
template <class T, class Container>
void stack<T, Container>::swap(stack& other) {
  std::swap(queue_, other.queue_);
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(const stack& other) {
  if (this != &other) {
    queue_ = other.queue_;
  }
  return *this;
}

template <class T, class Container>
stack<T, Container>& stack<T, Container>::operator=(stack&& other) noexcept {
  if (this != &other) {
    queue_ = std::move(other.queue_);
  }
  return *this;
}

/**
 * Check whether the stack is empty.
 *
 * @return true if the stack is empty, false otherwise
 *
 */
template <class T, class Container>
bool stack<T, Container>::empty() const {
  return queue_.empty();
}

/**
 * Returns a reference to the top element in the stack.
 *
 * @return const_reference a reference to the top element in the stack
 *
 */
template <class T, class Container>
typename stack<T, Container>::const_reference stack<T, Container>::top() const {
  return queue_.front();
}

/**
 * Pushes a value onto the stack.
 *
 * @param value the value to be pushed onto the stack
 *
 */
template <class T, class Container>
void stack<T, Container>::push(const_reference value) {
  queue_.pushInFrontForStack(value);
}

/**
 * Pops the top element from the stack.
 */
template <class T, class Container>
void stack<T, Container>::pop() {
  return queue_.pop();
}

/**
 * Returns the size of the stack.
 *
 * @return size of the stack
 */
template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size() const {
  return queue_.size();
}

/**
 * Insert multiple elements to the front of the stack.
 *
 * @param args variadic template for elements to insert
 *
 */
template <class T, class Container>
template <class... Args>
void stack<T, Container>::insert_many_front(Args&&... args) {
  for (const auto& arg : {args...}) {
    queue_.pushInFrontForStack(arg);
  }
}

}  // namespace s21