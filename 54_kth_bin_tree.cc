#include <iostream>

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val = 0) : value(val), left(nullptr), right(nullptr) {}
};

const Node* KthNodeRecurse(const Node* root, int& k) {
  const Node* target = root->left == nullptr ? 
                                     root : KthNodeRecurse(root->left, k) ;
  if (k == 1) {
    return target;
  }
  k--;

  if (root->right != nullptr) {
    target = KthNodeRecurse(root->right, k);
    return k == 1 ? target : nullptr;
  }
}

const Node* KthNode(const Node* root, int num) {
  if (root == nullptr || num < 1) {
    return nullptr;
  }

  return KthNodeRecurse(root, num);
}

int main() {
  Node* root = new Node(5);
  root->left = new Node(3);
  root->left->left = new Node(2);
  root->left->right = new Node(4);
  root->right = new Node(7);
  root->right->left = new Node(6);
  root->right->right = new Node(8);

  std::cout << "1th big: " << KthNode(root, 1)->value << std::endl;
  std::cout << "2th big: " << KthNode(root, 2)->value << std::endl;
  std::cout << "3th big: " << KthNode(root, 3)->value << std::endl;
  std::cout << "4th big: " << KthNode(root, 4)->value << std::endl;
  std::cout << "8th big: " << static_cast<int>(KthNode(root, 8) == nullptr) << std::endl;
}
