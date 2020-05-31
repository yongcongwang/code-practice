// By yongcong.wang @ 30/05/2020

#include <iostream>

struct Node {
  Node(int value = 0) : value(value), left(nullptr), right(nullptr) {}

  int value;
  Node* left;
  Node* right;
};

void Convert(Node* root, Node*& list_last) {
  if (root->left != nullptr) {
    Convert(root->left, list_last);
  }

  if (list_last == nullptr) {
    list_last = root;
    return;
  }

  list_last->right = root;
  root->left = list_last;
  list_last = root;

  if (root->right != nullptr) {
    Convert(root->right, list_last);
  }
}

Node* ConvertBinTreeToNodeList(Node* root) {
  if (root == nullptr) {
    return nullptr;
  }

  Node* list_last = nullptr;
  Convert(root, list_last);

  Node* result = root;
  while (result->left != nullptr) {
    result = result->left;
  }
  return result;
}

int main() {
  Node* root = new Node(10);
  root->left = new Node(6);
  root->left->left = new Node(4);
  root->left->right = new Node(8);

  root->right = new Node(14);
  root->right->left = new Node(12);
  root->right->right = new Node(16);

  Node* result = ConvertBinTreeToNodeList(root);
  std::cout << result->value << std::endl;
}
