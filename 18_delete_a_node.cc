// By yongcong.wang @ 12/05/2020

struct ListNode {
  ListNode(int value = 0) : value(value) {}

  int value;
  ListNode *next;
};

void DeleteLastNode(ListNode* header) {
  ListNode* curr_node = header;
  while (curr_node != nullptr) {
    if (curr_node->next->next == nullptr) {
      curr_node->next = nullptr;
      return;
    }
    curr_node = curr_node->next;
  }
}

void DeleteNode(ListNode* header, ListNode* del_node) {
  if (header == nullptr) {
    return;
  }
  if (header->next == nullptr) {
    header = nullptr;
    return;
  }

  if (del_node->next == nullptr) {
    DeleteLastNode(header);
    return;
  }

  ListNode* curr_node = header;
  while (curr_node != nullptr) {
    if (curr_node->next == del_node) {
      curr_node->next = del_node->next;
      return;
    }
    curr_node = curr_node->next;
  }
}

int main() {
  DeleteNode(nullptr, nullptr);

  ListNode* header = new ListNode(2);
  DeleteNode(header, header);

  ListNode* header1 = new ListNode(3);
  header1->next = new ListNode(4);
  header1->next->next = new ListNode(5);
  DeleteNode(header1, header1->next->next);

  header1->next->next = new ListNode(5);
  header1->next->next->next = new ListNode(6);
  DeleteNode(header1, header1->next);
}
