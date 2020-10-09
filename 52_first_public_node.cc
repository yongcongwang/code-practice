// By yongcong.wang @ 24/06/2020
#include <iostream>

struct Node {
  Node(int val = 0) : value(val), next(nullptr) {}
  int value;
  Node* next;

  Node* set_next(int val) {
    next = new Node(val);
    return next;
  }

  void output() {
    std::cout << value;
    if (next != nullptr) {
      std::cout << "->";
      next->output();
    } else {
      std::cout << std::endl;
    }
  }
};

Node* FirstPublicNode(Node* first, Node* second) {
  if (first == nullptr || second == nullptr) {
    return nullptr;
  }

  int first_length(0);
  Node* tmp = first;
  while (tmp != nullptr) {
    first_length++;
    tmp = tmp->next;
  }

  int second_length(0);
  tmp = second;
  while (tmp != nullptr) {
    second_length++;
    tmp = tmp->next;
  }

  Node* head_first = first;
  Node* head_second = second;
  if (first_length > second_length) {
    int skip_cnt = first_length - second_length;
    while (skip_cnt > 0) {
      head_first = head_first->next;
      skip_cnt--;
    }
  } else {
    int skip_cnt = second_length - first_length ;
    while (skip_cnt > 0) {
      head_second = head_second->next;
      skip_cnt--;
    }
  }

  while (head_first != nullptr && head_second != nullptr) {
    if (head_first->value == head_second->value) {
      return head_first;
    }
    head_first = head_first->next;
    head_second = head_second->next;
  }
  return nullptr;
}

int main() {
  Node* head1 = new Node(1);
  head1->set_next(3)->set_next(5)->set_next(7)->set_next(9);
  head1->output();
  Node* head2 = new Node(2);
  head2->set_next(4);
  head2->next->next = head1->next->next;
  head2->output();

  Node* result = FirstPublicNode(head1, head2);
  if (result != nullptr) {
    result->output();
  } else {
    std::cout << "not found" << std::endl;
  }
}

