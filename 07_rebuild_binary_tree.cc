// By yongcong.wang @ 27/04/2020

#include <iostream>
#include <vector>

struct BinaryTree {
  BinaryTree(int value = 0) : value(value), left(nullptr), right(nullptr) {}
  int value;
  BinaryTree *left;
  BinaryTree *right;
};

BinaryTree *construct_bin_tree(
    const std::vector<int> &preorder, const int start_index_preorder,
    const int end_index_preorder, const std::vector<int> &inorder,
    const int start_index_inorder, const int end_index_inorder) {

  if (end_index_preorder == start_index_preorder) {
    return new BinaryTree(preorder[start_index_preorder]);
  }

  int inorder_head_index = -1;
  for (int i = start_index_inorder; i <= end_index_inorder; ++i) {
    if (inorder[i] == preorder[start_index_preorder]) {
      inorder_head_index = i;
      break;
    }
  }
  if (inorder_head_index < 0) {
    return nullptr;
    std::cout << "error occurs" << std::endl;
  }

  auto *new_head = new BinaryTree(preorder[start_index_preorder]);
  const int gap = inorder_head_index - start_index_inorder;
  if (gap != 0) {
    new_head->left = construct_bin_tree(
        preorder, start_index_preorder + 1, start_index_preorder + gap,
        inorder, start_index_inorder, inorder_head_index - 1);
  }

  if (gap != end_index_inorder - start_index_inorder) {
    new_head->right = construct_bin_tree(
        preorder, start_index_preorder + gap + 1, end_index_preorder,
        inorder, inorder_head_index + 1, end_index_inorder);
  }

  return new_head;
}

BinaryTree *rebuild_binary_tree(
    const std::vector<int> &preorder, const std::vector<int> &inorder) {
  if (preorder.empty() || inorder.empty() ||
      preorder.size() != inorder.size()) {
    return nullptr;
  }

  return construct_bin_tree(
      preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main() {
  std::vector<int> preorder = {1, 2, 4, 7, 3, 5, 6, 8};
  std::vector<int> inorder = {4, 7, 2, 1, 5, 3, 8, 6};

  auto *bin_tree = rebuild_binary_tree(preorder, inorder);
  std::cout << "binary_tree" << bin_tree->value << std::endl;
}
