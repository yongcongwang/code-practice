#include <iostream>

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

int DepthBinarySearchTree(Node* root) {
  if (root == nullptr) {
    return 0;
  }

  int left = DepthBinarySearchTree(root->left);
  int right = DepthBinarySearchTree(root->right);

  return left > right ? left + 1 : right + 1;
}
