// By yongcong.wang @ 19/05/2020
#include <iostream>

struct Tree {
  Tree(int value = 0) : value(value), left(nullptr), right(nullptr) {}

  int value;
  Tree* left;
  Tree* right;
};

bool IsSubTreeMatched(Tree* root, Tree* sub) {
  if (sub == nullptr) {
    return true;
  }

  if (root == nullptr) {
    return false;
  }

  return root->value == sub->value &&
         IsSubTreeMatched(root->left, sub->left) &&
         IsSubTreeMatched(root->right, sub->right);
}

bool IsSubTree(Tree* origin, Tree* sub) {
  if (origin == nullptr || sub == nullptr) {
    return false;
  }

  bool result = false;
  if (origin->value == sub->value) {
    result = IsSubTreeMatched(origin, sub);
  }

  return result || IsSubTree(origin->left, sub) ||
         IsSubTree(origin->right, sub);
}

int main() {
  Tree* root1 = new Tree(8);
  root1->left = new Tree(8);
  root1->left->left = new Tree(9);
  root1->left->right = new Tree(2);
  root1->left->right->left = new Tree(4);
  root1->left->right->right  = new Tree(7);
  root1->right = new Tree(7);

  Tree* sub1 = new Tree(8);
  sub1->left = new Tree(9);
  sub1->right = new Tree(3);

  std::cout << IsSubTree(root1, sub1) << std::endl;
}
