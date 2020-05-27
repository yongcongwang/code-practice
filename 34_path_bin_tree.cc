// By yongcong.wang @ 27/05/2020

#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

struct BinNode {
  BinNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}

  int value;
  BinNode* left;
  BinNode* right;
};

int SumStack(const std::vector<int>& path) {
  return std::accumulate(path.begin(), path.end(), 0);
}

void PrintStack(const std::vector<int>& path) {
  std::for_each(path.begin(), path.end(), 
                [](int ele) { std::cout << ele << " "; });
  std::cout << std::endl;
}

void PrintBinTreePathSum(
    const BinNode* root, const int sum, std::vector<int>& path) {
  path.push_back(root->value);
  if (root->left == nullptr && root->right == nullptr && SumStack(path) == sum) {
    PrintStack(path);
  }

  if (root->left != nullptr) {
    PrintBinTreePathSum(root->left, sum, path);
  }

  if (root->right != nullptr) {
    PrintBinTreePathSum(root->right, sum, path);
  }
  path.pop_back();
}

void PrintBinTreeSum(const BinNode* root, const int sum) {
  if (root == nullptr) {
    return;
  }

  std::vector<int> path;
  PrintBinTreePathSum(root, sum, path);
}

int main() {
  auto* root = new BinNode(10);
  root->left = new BinNode(5);
  root->right = new BinNode(12);
  root->left->left = new BinNode(4);
  root->left->right = new BinNode(7);

  PrintBinTreeSum(root, 22);
}
