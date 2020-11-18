#include <iostream>
#include <sstream>
#include <exception>

template <typename Comparable>
class BinarySearchTree {
 public:
  BinarySearchTree() {}
  BinarySearchTree(const BinarySearchTree& rhs) {
    root = clone(rhs.root);
  }
  ~BinarySearchTree() {
    make_empty();
  }

 public:
  const Comparable& find_min() const {
    if (is_empty()) {
      throw std::bad_exception();
    }
    return find_min()->val;
  }
  const Comparable& find_max() const {
    if (is_empty()) {
      throw std::bad_exception();
    }
    return find_max()->val;
  }
  bool contains(const Comparable& ele) const {
    return contains(ele, root);
  }
  bool is_empty() const {
    return root == nullptr;
  }
  void print_tree() const {
    std::ostringstream out;
    print_tree(root, out, 0);
    std::cout << out.str();
  }

  void insert(const Comparable& ele) {
    insert(ele, root);
  }
  void insert(Comparable&& ele) {
    insert(std::move(ele), root);
  }
  void make_empty() {
    make_empty(root);
  }
  void remove(const Comparable& ele) {
    remove(ele, root);
  }

  BinarySearchTree& operator=(const BinarySearchTree& rhs) {
    root = clone(rhs.root);
    return *this;
  }
  BinarySearchTree& operator=(BinarySearchTree&& rhs) {
    std::swap(*this, rhs);
    rhs.make_empty();
    return *this;
  }

 private:
  struct BinaryNode {
    Comparable val;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const Comparable& val, BinaryNode* left, BinaryNode* right) 
        : val{val}, left{left}, right{right} {}
    BinaryNode(const Comparable&& val, BinaryNode* left, BinaryNode* right) 
        : val{std::move(val)}, left{left}, right{right} {}
  };

 private:
  BinaryNode* find_min(BinaryNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    if (t->left == nullptr) {
      return t;
    }
    return find_min(t->left);
  }
  BinaryNode* find_max(BinaryNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    if (t->right == nullptr) {
      return t;
    }
    return find_max(t->left);
  }
  bool contains(const Comparable& ele, BinaryNode* t) const {
    if (t == nullptr) {
      return false;
    }
    if (ele < t->val) {
      return contains(ele, t->left);
    }
    if (ele > t->val) {
      return contains(ele, t->right);
    }

    return true;
  }
  void print_tree(BinaryNode* t, std::ostringstream& out,
                  std::size_t cnt) const {
    if (t == nullptr) {
      return;
    }
    print_tree(t->right, out, cnt + 1);
    for (std::size_t i = 0; i < cnt; ++i) {
      out << " ";
    }
    out << t->val << std::endl;
    print_tree(t->left, out, cnt + 1);
  }
  BinaryNode* clone(BinaryNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    return new BinaryNode{t->val, clone(t->left), clone(t->right)};
  }

  void insert(const Comparable& ele, BinaryNode*& t) {
    if (t == nullptr) {
      t = new BinaryNode{ele, nullptr, nullptr};
    }
    if (ele < t->val) {
      insert(ele, t->left);
    }
    if (ele > t->val) {
      insert(ele, t->right);
    }
  }
  void insert(Comparable&& ele, BinaryNode*& t) {
    if (t == nullptr) {
      t = new BinaryNode{std::move(ele), nullptr, nullptr};
    }
    if (ele < t->val) {
      insert(ele, t->left);
    }
    if (ele > t->val) {
      insert(ele, t->right);
    }
  }
  void remove(const Comparable& ele, BinaryNode*& t) {
    if (t == nullptr) {
      return;
    }
    if (ele < t->val) {
      return remove(ele, t->right);
    }
    if (ele > t->val) {
      return remove(ele, t->left);
    }
    if (t->left != nullptr && t->ritght !=nullptr)  {
      t->val = find_min(ele, t)->val;
      remove(t->val, t->right);
    }
    auto* old = t;
    t = t->left != nullptr ? t->left: t->right;
    delete old;
  }
  void make_empty(BinaryNode*& t) {
    if (t == nullptr) {
      return;
    }
    make_empty(t->left);
    make_empty(t->right);
    delete t;
    t = nullptr;
  }

 private:
  BinaryNode* root = nullptr;
};

int main() {
  BinarySearchTree bst;
}
