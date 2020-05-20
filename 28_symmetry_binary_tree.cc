// By yongcong.wang @ 20/05/2020
#include <iostream>

struct BinTreeNode {
 BinTreeNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}

 int value;
 BinTreeNode* left;
 BinTreeNode* right;
};

bool IsSymmetryTwo(BinTreeNode* root1, BinTreeNode* root2) {
  if (root1 == nullptr && root2 == nullptr) {
    return true;
  }

  if (root1 == nullptr || root2 == nullptr) {
    return false;
  }

  if (root1->value != root2->value) {
    return false;
  }

  return IsSymmetryTwo(root1->left, root2->right) &&
         IsSymmetryTwo(root1->right, root2->left);
}

bool IsSymmetry(BinTreeNode* root) {
  return IsSymmetryTwo(root, root);
}

int main() {
  BinTreeNode* root1 = new BinTreeNode(8);
  root1->left = new BinTreeNode(6);
  root1->left->left = new BinTreeNode(5);
  root1->left->right = new BinTreeNode(7);
  root1->right = new BinTreeNode(6);
  root1->right->left = new BinTreeNode(7);
  root1->right->right = new BinTreeNode(5);

  BinTreeNode* root2 = new BinTreeNode(8);
  root2->left = new BinTreeNode(6);
  root2->left->left = new BinTreeNode(5);
  root2->left->right = new BinTreeNode(7);
  root2->right = new BinTreeNode(9);
  root2->right->left = new BinTreeNode(7);
  root2->right->right = new BinTreeNode(5);

  BinTreeNode* root3 = new BinTreeNode(8);
  root3->left = new BinTreeNode(6);
  root3->left->left = new BinTreeNode(5);
  root3->left->right = new BinTreeNode(7);
  root3->right = new BinTreeNode(6);
  root3->right->left = new BinTreeNode(7);

  std::cout << IsSymmetry(root1) << std::endl;
  std::cout << IsSymmetry(root2) << std::endl;
  std::cout << IsSymmetry(root3) << std::endl;
  std::cout << IsSymmetry(nullptr) << std::endl;
}
