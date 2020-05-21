// By yongcong.wang @ 21/05/2020
#include <limits>
#include <iostream>

template <typename T>
class MyStack {
 public:
  MyStack() = default;
  ~MyStack() {
    if (head_ != nullptr) {
      delete head_;
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
      return;
    }

    Node* tmp = head_;
    head_ = head_->next;

    T value = tmp->value;
    delete tmp;
    return value;
  }

  T top() {
    if (head_ != nullptr) {
      return head_->value;
    }

    return std::numeric_limits<T>::max();
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
  MinStack() : min_(std::numeric_limits<T>::max()) {}
  ~MinStack() = default;
 
 public:
  void push(T value) {
    if (value < min_) {
      min_ = value;
    }
    data_.push(value);
    assist_.push(min_);
  }

  T pop() {
    if (data_.empty()) {
      return std::numeric_limits<T>::max();
    }
    assist_.pop();
    if (data_.pop() < min_) {
      min_ = assist_.top();
    }
  }

  T top() {
    if (data_.empty()) {
      return std::numeric_limits<T>::max();
    }

    return data_.top();
  }

  T min() {
    return min_;
  }

 private:
  MyStack<T> data_;
  MyStack<T> assist_;
  T min_;
};

int main() {
  MinStack<int> min_stack;
  min_stack.push(2);
  min_stack.push(3);
  min_stack.push(1);
  min_stack.push(4);

  std::cout << "min: " << min_stack.min() << std::endl;
}
