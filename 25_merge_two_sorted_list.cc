// By yongcong.wang @ 18/05/2020
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

Node* MergeTwoSortedLists(Node* head1, Node* head2) {
  if (head1 == nullptr) {
    return head2;
  }
  if (head2 == nullptr) {
    return head1;
  }

  Node* head;
  Node* curr_list1 = head1;
  Node* curr_list2 = head2;
  if (curr_list1->value < curr_list2->value) {
    head = curr_list1;
    curr_list1 = curr_list1->next;
  } else {
    head = curr_list2;
    curr_list2 = curr_list2->next;
  }

  Node* result = head;

  while (curr_list1 != nullptr && curr_list2 != nullptr) {
    if (curr_list1->value < curr_list2->value) {
      head->next = curr_list1;
      head = head->next;
      curr_list1 = curr_list1->next;
    } else {
      head->next = curr_list2;
      head = head->next;
      curr_list2 = curr_list2->next;
    }
  }

  if (curr_list1 != nullptr) {
    head->next = curr_list1;
  }
  if (curr_list2 != nullptr) {
    head->next = curr_list2;
  }

  return head;
}

int main() {
  Node* head1 = new Node(1);
  head1->set_next(3)->set_next(5)->set_next(7)->set_next(9);
  Node* head2 = new Node(2);
  head2->set_next(4)->set_next(6)->set_next(8)->set_next(10);

  Node* result1 = MergeTwoSortedLists(head1, head2);
  Node* result2 = MergeTwoSortedLists(nullptr, head2);
  Node* result3 = MergeTwoSortedLists(nullptr, nullptr);

}
