// By yongcong.wang @ 16/05/2020
#include <iostream>

struct Node {
  Node(int val = 0) : value(val), next(nullptr) {}
  int value;
  Node* next;

  Node* set_next(int val) {
    next = new Node(val);
    return next;
  }
};

Node* GetOneLoopNode(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }

  Node* slow = head;
  Node* fast = head;

  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return slow;
    }
  }

  return nullptr;
}

int GetLoopCnt(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  int cnt(1);
  Node* head = node;
  while (head->next != nullptr) {
    if (head->next == node) {
      return cnt;
    } else {
      cnt++;
      head = head->next;
    }
  }
  return 0;
}

Node* GetLoopEntrance(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }

  Node* node_in_loop = GetOneLoopNode(head);
  if (node_in_loop == nullptr) {
    return nullptr;
  }

  const int loop_cnt = GetLoopCnt(node_in_loop);

  Node* fast = head;
  Node* slow = head;
  for (auto i = 0; i < loop_cnt; ++i) {
    fast = fast->next;
  }

  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
}

int main() {
  Node* head =  new Node(1);

  head->set_next(2)->set_next(3)->set_next(4)->set_next(5)->set_next(6);
  head->next->next->next->next->next->next=head->next->next->next->next->next->next;

  Node* result = GetLoopEntrance(head);
  std::cout << (result ? result->value : 0) << std::endl;
}
