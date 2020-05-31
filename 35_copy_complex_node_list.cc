// By yongcong.wang @ 28/05/2020
#include <iostream>

struct Node {
  Node(int val = 0) : value(val), sibling(nullptr), next(nullptr) {}

  int value;
  Node* sibling;
  Node* next;
};

void CopyEachNode(Node* origin) {
  Node* head = origin;
  while (head != nullptr) {
    Node* tmp = head->next;
    head->next = new Node(head->value);
    head->next->next = tmp;
    head = tmp;
  }
}

void CopySibingInfo(Node* origin) {
  Node* head = origin;
  while (head != nullptr) {
    Node* tmp = head->sibling;
    if (tmp != nullptr) {
      head->next->sibling = tmp->next;
    }
    head = head->next->next;
  }
}

Node* SplitTwoList(Node* origin) {
  Node* even_head = origin->next;
  Node* curr_odd = origin;
  Node* curr_even = even_head;
  Node* curr_node = even_head->next;
  int curr_node_cnt(1);
  while (curr_node != nullptr) {
    if (curr_node_cnt & 1) {
      curr_odd->next = curr_node;
      curr_odd = curr_odd->next;
    } else {
      curr_even->next = curr_node;
      curr_even = curr_even->next;
    }
    curr_node = curr_node->next;
    curr_node_cnt++;
  }

  return even_head;
}

Node* CopyNodeList(Node* origin) {
  if (origin == nullptr) {
    return nullptr;
  }

  CopyEachNode(origin);
  CopySibingInfo(origin);
  return SplitTwoList(origin);
}

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->sibling = head->next->next;
  head->next->sibling = head->next->next->next->next;
  head->next->next->next->sibling = head->next;

  Node* result = CopyNodeList(head);
  std::cout << result->value << std::endl;
}
