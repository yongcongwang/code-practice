// By yongcong.wang @ 24/05/2020

#include <deque>
#include <stack>
#include <iostream>
#include <array>

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

void PrintBinTreeLineZ(const BinNode* root) {
  if (root == nullptr) {
    return;
  }

  std::array<std::stack<const BinNode*>, 2> out;
  std::size_t curr_index = 0;
  std::size_t next_index = 1;
  out[curr_index].push(root);
  while (!out[0].empty() || !out[1].empty()) {
    const BinNode* parrent = out[curr_index].top();
    out[curr_index].pop();
    std::cout << parrent->value << " ";

    if (curr_index == 0) {
      if (parrent->left != nullptr) {
        out[next_index].push(parrent->left);
      }
      if (parrent->right != nullptr) {
        out[next_index].push(parrent->right);
      }
    } else {
      if (parrent->right != nullptr) {
        out[next_index].push(parrent->right);
      }
      if (parrent->left != nullptr) {
        out[next_index].push(parrent->left);
      }
    }

    if (out[curr_index].empty()) {
      std::cout << std::endl;
      curr_index = 1 - curr_index;
      next_index = 1 - next_index;
    }
  }

  std::cout << std::endl;
}

void PrintBinTreeLineSplit(const BinNode* root) {
  if (root == nullptr) {
    return;
  }

  std::deque<const BinNode*> out;
  out.push_back(root);
  std::size_t curr_level_cnt = 1;
  std::size_t next_level_cnt = 0;
  while (!out.empty()) {
    const BinNode* parrent = out.front();
    out.pop_front();
    std::cout << parrent->value << " ";
    curr_level_cnt--;

    if (parrent->left != nullptr) {
      out.push_back(parrent->left);
      next_level_cnt++;
    }
    if (parrent->right != nullptr) {
      out.push_back(parrent->right);
      next_level_cnt++;
    }

    if (curr_level_cnt == 0) {
      std::cout << std::endl;
      curr_level_cnt = next_level_cnt;
      next_level_cnt = 0;
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

  PrintBinTreeLineZ(root);
  PrintBinTree(root);
  PrintBinTreeLineSplit(root);
}
