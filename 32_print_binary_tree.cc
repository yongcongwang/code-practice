// By yongcong.wang @ 24/05/2020

#include <deque>
#include <iostream>

struct BinNode {
  BinNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}

  int value;
  BinNode* left;
  BinNode* right;
};

void PrintBinTree(const BinNode* root) {
  if (root == nullptr) {
    return;
  }

  std::deque<const BinNode*> out;
  out.push_back(root);
  while (!out.empty()) {
    const BinNode* parrent = out.front();
    out.pop_front();
    std::cout << parrent->value << " ";

    if (parrent->left != nullptr) {
      out.push_back(parrent->left);
    }
    if (parrent->right != nullptr) {
      out.push_back(parrent->right);
    }
  }

  std::cout << std::endl;
}

int main() {
  BinNode* root = new BinNode(8);
  root->left = new BinNode(6);
  root->left->left = new BinNode(5);
  root->left->right = new BinNode(7);
  root->right = new BinNode(10);
  root->right->left = new BinNode(9);
  root->right->right = new BinNode(11);

  PrintBinTree(root);
}
