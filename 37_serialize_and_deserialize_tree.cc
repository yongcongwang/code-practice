// By yongcong.wang @ 01/06/2020
#include <iostream>
#include <queue>

constexpr int INVALID_INT = -255;

struct Node {
  Node(int value = 0) : value(value), left(nullptr), right(nullptr) {}

  int value;
  Node* left;
  Node* right;
};

void Serialize(Node* root, std::queue<int>& ser) {
  if (root == nullptr) {
    ser.push(INVALID_INT);
    return;
  }

  ser.push(root->value);
  Serialize(root->left, ser);
  Serialize(root->right, ser);
}

void Deserialize(Node*& root, std::queue<int>& ser) {

  if (!ser.empty() && ser.front() != INVALID_INT) {
    root = new Node(ser.front());
    ser.pop();

    Deserialize(root->left, ser);
    Deserialize(root->right, ser);
  } else {
    ser.pop();
  }
}

int main() {
  Node* root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(6);

  std::queue<int> serialize;
  Serialize(root, serialize);
  std::cout << serialize.front() << std::endl;

  Node* result;
  Deserialize(result, serialize);
  std::cout << result->value << std::endl;
}
