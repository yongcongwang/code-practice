#include <iostream>
#include <algorithm>
#include <initializer_list>

template<typename T>
class ListStack {
 public:
  ListStack() : {}
  explicit ListStack(T val)
      : head_{new Node{0, new Node{val}}}, top_{head_->next}, size_{1} {}
  ListStack(std::initializer_list<T> l) : size_{l.size()} {
    for (const auto& e : l) {
      top_->next = new Node{e};
      top_ = top_->next;
    }
  }

 private:
  struct Node {
    T val;
    Node* next;
  };

 private:
  Node* head_{new Node{}};
  Node* top_{head_};
  size_{0};
};
