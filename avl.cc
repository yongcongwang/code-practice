#include <iostream>
#include <sstream>
#include <exception>
#include <algorithm>

template <typename Comparable>
class AvlTree {
 public:
  AvlTree() {}
  AvlTree(const AvlTree& rhs) {
    root = clone(rhs.root);
  }
  ~AvlTree() {
    make_empty();
  }

 public:
  const Comparable& find_min() const {
    if (is_empty()) {
      throw std::bad_exception();
    }
    return find_min(root)->val;
  }
  const Comparable& find_max() const {
    if (is_empty()) {
      throw std::bad_exception();
    }
    return find_max(root)->val;
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

  AvlTree& operator=(const AvlTree& rhs) {
    root = clone(rhs.root);
    return *this;
  }
  AvlTree& operator=(AvlTree&& rhs) {
    std::swap(*this, rhs);
    rhs.make_empty();
    return *this;
  }

 private:
  struct AvlNode {
    Comparable val;
    AvlNode* left;
    AvlNode* right;
    int height;

    AvlNode(const Comparable& val, AvlNode* left, AvlNode* right,
               int height = 0) 
        : val{val}, left{left}, right{right}, height{height} {}
    AvlNode(const Comparable&& val, AvlNode* left, AvlNode* right, int height = 0) 
        : val{std::move(val)}, left{left}, right{right}, height{0} {}
  };

 private:
  AvlNode* find_min(AvlNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    if (t->left == nullptr) {
      return t;
    }
    return find_min(t->left);
  }
  AvlNode* find_max(AvlNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    if (t->right == nullptr) {
      return t;
    }
    return find_max(t->right);
  }
  bool contains(const Comparable& ele, AvlNode* t) const {
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
  void print_tree(AvlNode* t, std::ostringstream& out,
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
  AvlNode* clone(AvlNode* t) const {
    if (t == nullptr) {
      return nullptr;
    }
    return new AvlNode{t->val, clone(t->left), clone(t->right)};
  }

  void insert(const Comparable& ele, AvlNode*& t) {
    if (t == nullptr) {
      t = new AvlNode{ele, nullptr, nullptr};
    } else if (ele < t->val) {
      insert(ele, t->left);
    } else if (ele > t->val) {
      insert(ele, t->right);
    }

    balance(t);
  }
  void insert(Comparable&& ele, AvlNode*& t) {
    if (t == nullptr) {
      t = new AvlNode{std::move(ele), nullptr, nullptr};
    } else if (ele < t->val) {
      insert(ele, t->left);
    } else if (ele > t->val) {
      insert(ele, t->right);
    }

    balance(t);
  }
  void remove(const Comparable& ele, AvlNode*& t) {
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
    balance(t);
  }
  void make_empty(AvlNode*& t) {
    if (t == nullptr) {
      return;
    }
    make_empty(t->left);
    make_empty(t->right);
    delete t;
    t = nullptr;
  }
  void balance(AvlNode*& t) {
    if (t == nullptr) {
      return;
    }

    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
      if (height(t->left->left) >= height(t->left->right)) {
        rotate_with_left_child(t);
      } else {
        double_with_left_child(t);
      }
    } else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
      if (height(t->right->right) >= height(t->right->left)) {
        rotate_with_right_child(t);
      } else {
        double_with_right_child(t);
      }
    }

    t->height = std::max(height(root->left), height(root->right)) + 1;
  }

  int height(AvlNode* const root) const {
    return root == nullptr ? -1 : root->height;
  }


  void rotate_with_left_child(AvlNode*& t) {
    if (t == nullptr) {
      return;
    }
    auto* left_child = t->left;
    t->left = left_child->right;
    left_child->right = t;
    left_child->height = std::max(height(left_child->left),
                             height(left_child->right)) + 1;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    t = left_child;
  }

  void rotate_with_right_child(AvlNode*& t) {
    if (t == nullptr) {
      return;
    }
    auto* right_child = t->right;
    t->right = right_child->left;
    right_child->left = t;
    right_child->height = std::max(height(right_child->left),
                              height(right_child->right)) + 1;
    t->height = std::max(height(t->left), height(t->right)) + 1;
    t = right_child;
  }

  void double_with_left_child(AvlNode*& t) {
    rotate_with_right_child(t->left);
    rotate_with_left_child(t);
  }
  void double_with_right_child(AvlNode*& t) {
    rotate_with_left_child(t->right);
    rotate_with_right_child(t);
  }

 private:
  AvlNode* root = nullptr;
  const int ALLOWED_IMBALANCE = 1;
};

int main() {
  AvlTree<int> bst;
  bst.insert(1);
  bst.insert(3);
  bst.insert(5);
  bst.insert(7);
  bst.insert(9);
  bst.print_tree();
  std::cout << "min:" << bst.find_min() << std::endl;
  std::cout << "max:" << bst.find_max() << std::endl;
  std::cout << "contain 2:" << bst.contains(2) << std::endl;
  std::cout << "contain 3:" << bst.contains(3) << std::endl;
  std::cout << "empty():" << bst.is_empty() << std::endl;
  bst.make_empty();
  std::cout << "empty():" << bst.is_empty() << std::endl;
}
