// By yongcong.wang @ 28/04/2020
#include <iostream>

struct BinaryTree {
  BinaryTree(int value = 0) 
      : value(value), parent(nullptr), left(nullptr), right(nullptr) {}
  int value;
  BinaryTree *parent;
  BinaryTree *left;
  BinaryTree *right;
};

BinaryTree *GetNextInorder(BinaryTree *node) {
  if (node == nullptr || node->parent == nullptr) {
    return nullptr;
  }

  if (node->right != nullptr) {
    BinaryTree *tmp = node->right;
    while (tmp->left != nullptr) {
      tmp = tmp->left;
    }
    return tmp;
  } else if (node == node->parent->left) {
    return node->parent;
  } else {
    BinaryTree *tmp = node;
    while (tmp->parent != nullptr && tmp != tmp->parent->left) {
      tmp = tmp->parent;
    }
    return tmp->parent == nullptr ? nullptr : tmp->parent;
  }
}

int main() {
  BinaryTree *head0 = nullptr;
  BinaryTree *test0 = GetNextInorder(head0);
  std::cout << "empty tree: " << (test0 ? test0->value : 0) << std::endl;

  BinaryTree *head1 = new BinaryTree(5);
  head1->left = new BinaryTree(2);
  head1->left->parent = head1;
  BinaryTree *test1 = GetNextInorder(head1->left);
  std::cout << "head and left: " << (test1 ? test1->value : 0) << std::endl;

  BinaryTree *head2 = new BinaryTree(3);
  head2->right = new BinaryTree(2);
  head2->right->parent = head2;
  BinaryTree *test2 = GetNextInorder(head2);
  std::cout << "head and right: " << (test2 ? test2->value : 0) << std::endl;

  BinaryTree *head3 = new BinaryTree(3);
  head3->left = new BinaryTree(2);
  head3->left->left = new BinaryTree(5);
  head3->left->right = new BinaryTree(1);
  head3->left->right->left = new BinaryTree(6);
  head3->left->right->right = new BinaryTree(8);
  head3->right = new BinaryTree(4);
  head3->right->left = new BinaryTree(7);
  head3->right->right = new BinaryTree(9);

  head3->left->parent = head3;
  head3->right->parent = head3;
  head3->left->left->parent = head3->left;
  head3->left->right->parent = head3->left;
  head3->left->right->left->parent = head3->left->right;
  head3->left->right->right->parent = head3->left->right;
  head3->right->left->parent = head3->right;
  head3->right->right->parent = head3->right;

  BinaryTree *test31 = GetNextInorder(head3->left->left);
  std::cout << "head all test 1: " << (test31 ? test31->value : 0) << std::endl;

  BinaryTree *test32 = GetNextInorder(head3->left);
  std::cout << "head all test 2: " << (test32 ? test32->value : 0) << std::endl;

  BinaryTree *test33 = GetNextInorder(head3->left->right->right);
  std::cout << "head all test 3: " << (test33 ? test33->value : 0) << std::endl;

  BinaryTree *test34 = GetNextInorder(head3->right->right);
  std::cout << "head all test 4: " << (test34 ? test34->value : 0) << std::endl;
}
