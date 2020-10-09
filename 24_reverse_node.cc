// By yongcong.wang @ 18/05/2020

struct Node {
  Node(int val = 0) : value(val) {}

  int value;
  Node* next;
};


Node* ReverseNodeList(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  Node* prev_node = head;
  Node* curr_node = head->next;

  Node* next_node(nullptr);
  prev_node->next = nullptr;
  while (curr_node != nullptr) {
    next_node = curr_node->next;
    curr_node->next = prev_node;

    prev_node = curr_node;
    curr_node = next_node;
  }

  return prev_node;
}

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  Node* head1 = nullptr;
  Node* head2 = new Node(1);
  Node* head3 = new Node(1);
  head3->next = new Node(2);

  Node* new_head = ReverseNodeList(head);
  Node* new_head1 = ReverseNodeList(head1);
  Node* new_head2 = ReverseNodeList(head2);
  Node* new_head3 = ReverseNodeList(head3);
}


