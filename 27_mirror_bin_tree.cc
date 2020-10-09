// By yongcong.wang @ 19/05/2020

struct BinaryTreeNode {
  BinaryTreeNode(int val = 0) : value(val), left(nullptr), right(nullptr) {}

  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
};

void MirrorBinaryTree(BinaryTreeNode* root) {
  if (root == nullptr) {
    return;
  }

  BinaryTreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  MirrorBinaryTree(root->left);
  MirrorBinaryTree(root->right);
}

int main() {
  BinaryTreeNode* root = new BinaryTreeNode(8);
  root->left = new BinaryTreeNode(6);
  root->left->left = new BinaryTreeNode(5);
  root->left->right = new BinaryTreeNode(7);
  root->right = new BinaryTreeNode(10);
  root->right->left = new BinaryTreeNode(9);
  root->right->right = new BinaryTreeNode(11);

  MirrorBinaryTree(root);
}

