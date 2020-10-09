// By yongcong.wang @ 25/04/2020
#include <iostream>
#include <string>

struct Node {
  Node(int val = 0) : value(val), next(nullptr) {}
  int value;
  Node *next;
};

void reverse_print(Node *node) {
  if (node == nullptr) {
    return;
  }

  if (node->next == nullptr) {
    std::cout << node->value << "<-";
    return;;
  }

  reverse_print(node->next);
  std::cout << node->value << "<-";
}

int main() {
  Node *head = new Node(3);
  head->next = new Node(5);
  head->next->next = new Node(7);
  head->next->next->next = new Node(9);

  Node *head_one = new Node(11);
  Node *head_null = nullptr;

  reverse_print(head);
  std::cout << std::endl;
  reverse_print(head_one);
  std::cout << std::endl;
  reverse_print(head_null);
  std::cout << std::endl;
}
