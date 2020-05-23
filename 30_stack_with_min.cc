// By yongcong.wang @ 21/05/2020
#include <limits>
#include <iostream>

template <typename T>
class MyStack {
 public:
  MyStack() : head_(nullptr) {}
  ~MyStack() {
    while (head_ != nullptr) {
      Node* tmp = head_;
      head_ = head_->next;
      delete tmp;
    }
  };

 public:
  void push(T val) {
    Node* new_node = new Node(val);
    new_node->next = head_;
    head_ = new_node;
  }

  T pop() {
    if (head_ == nullptr) {
      return std::numeric_limits<T>::max();
    }

    T value = head_->value;
    Node* tmp = head_;
    head_ = head_->next;

    delete tmp;
    return value;
  }

  T top() {
    if (head_ == nullptr) {
      return std::numeric_limits<T>::max();
    }

    return head_->value;
  }

  bool empty() {
    return head_ == nullptr;
  }

 private:
  struct Node {
    Node(T val = 0) : value(val), next(nullptr) {}

    T value;
    Node* next;
  };

  Node* head_;
};

template <typename T>
class MinStack {
 public:
  MinStack() = default;
  ~MinStack() = default;
 
 public:
  void push(T value) {
    data_.push(value);
    assist_.push(value < assist_.top() ? value : assist_.top());
  }

  T pop() {
    if (data_.empty()) {
      return std::numeric_limits<T>::max();
    }

    assist_.pop();
    data_.pop();
  }

  T top() {
    if (data_.empty()) {
      return std::numeric_limits<T>::max();
    }

    return data_.top();
  }

  T min() {
    if (assist_.empty()) {
      return std::numeric_limits<T>::max();
    }
    return assist_.top();
  }

 private:
  MyStack<T> data_;
  MyStack<T> assist_;
};

int main() {
  MinStack<int> min_stack;
  std::cout << "min init: " << min_stack.min() << std::endl;
  min_stack.push(2);
  std::cout << "min push2: " << min_stack.min() << std::endl;
  min_stack.push(3);
  std::cout << "min push3: " << min_stack.min() << std::endl;
  min_stack.push(1);
  std::cout << "min push1: " << min_stack.min() << std::endl;
  min_stack.push(4);
  std::cout << "min push4: " << min_stack.min() << std::endl;
  min_stack.pop();
  std::cout << "min pop4: " << min_stack.min() << std::endl;
  min_stack.pop();
  std::cout << "min pop1: " << min_stack.min() << std::endl;
  min_stack.pop();
  std::cout << "min pop3: " << min_stack.min() << std::endl;
  min_stack.pop();
  std::cout << "min pop2: " << min_stack.min() << std::endl;
  std::cout << "min top: " << min_stack.top() << std::endl;
  min_stack.pop();
  std::cout << "min top: " << min_stack.top() << std::endl;
  std::cout << "min pop5: " << min_stack.min() << std::endl;
}
