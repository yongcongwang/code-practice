#include <algorithm>
#include <exception>
#include <iostream>

template <typename Object>
class List {
 private:
  struct Node {
    Node(const Object& val = Object{}, Node* p = nullptr, Node* n = nullptr)
        : val(val), next(n), prev(p) {}

    Object val;
    Node* next;
    Node* prev;
  };

 public:
  class const_iterator {
   public:
    const_iterator() : current{} {}

    const Object& operator*() const {
      return retrieve();
    }
    const_iterator& operator++() {
      current = current->next;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator old = *this;
      ++(*this);
      return old;
    }

    bool operator==(const const_iterator& rhs) const {
      return current == rhs.current;
    }

    bool operator!=(const const_iterator& rhs) const {
      return !(*this == rhs);
    }

   public:
    const_iterator begin() const {
      const_iterator itr{*this, head_};
      return ++itr;
    }

   protected:
    const List<Object> *the_list;
    Node* current;

    Object& retrieve() const {
      return current->val;
    }

    const_iterator(Node* p) : current(p) {}
    const_iterator(const List<Object>& lst, Node* p)
        : the_list{&lst}, current{p} {}

    void assert_is_valid() const {
      if (the_list == nullptr || current == nullptr ||
          current == the_list->head_) {
        throw std::bad_exception();
      }
    }

    friend class List<Object>;
  };

  class iterator : public const_iterator {
   public:
    iterator() = default;

    Object& operator*() {
      return const_iterator::retrieve();
    }

    const Object& operator*() const {
      return const_iterator::operator*();
    }

    iterator &operator++() {
      this->current = this->current->next;
      return *this;
    }

    iterator operator++(int) {
      iterator old = *this;
      ++(*this);
      return old;
    }

    iterator insert(iterator itr, const Object& x) {
      itr.assert_is_valid();
      if (itr.the_list != this) {
        throw std::bad_exception();
      }

      Node* p = itr.current;
      ++size_;
      return { *this, p->prev = p->prev->next = new Node{x, p->prev, p} };
    }

   protected:
    iterator(Node* p) : const_iterator(p) {}

    friend class List<Object>;
  };

 public:
  List() {
    init();
  }
  ~List() {
    clear();
    delete head_;
    delete tail_;
  }

  List(const List& rhs) {
    init();
    for (auto& x : rhs) {
      push_back(x);
    }
  }
  
  List& operator=(const List& rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  List(List&& rhs)
      : size_{rhs.size_}, head_(rhs.head_), tail_(rhs.tail_) {
    rhs.size_ = 0;
    rhs.head_ = nullptr;
    rhs.tail_ = nullptr;
  }

  List& operator=(List&& rhs) {
    std::swap(size_, rhs.size_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    return *this;
  }

  void init() {
    size_ = 0;
    head_ = new Node;
    tail_ = new Node;
    head_->next = tail_;
    tail_->prev = head_;
  }

 public:
  iterator begin() {
    return {head_->next};
  }
  iterator end() {
    return {tail_};
  }
  const_iterator begin() const {
    return {head_->next};
  }
  const_iterator end() const {
    return {tail_};
  }

  int size() const {
    return size_;
  }

  bool empty() const {
    return size() == 0;
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
  }

  Object& front() {
    return *begin();
  }
  const Object& front() const {
    return *begin();
  }
  Object& back() {
    return *(--end());
  }
  const Object& back() const {
    return *(--end());
  }

  void push_front(const Object& x) {
    insert(begin(), x);
  }
  void push_front(const Object&& x) {
    insert(begin(), std::move(x));
  }
  void push_back(const Object& x) {
    insert(end(), x);
  }
  void push_back(const Object&& x) {
    insert(end(), std::move(x));
  }

  void pop_front() {
    erase(begin());
  }
  void pop_back() {
    erase(--end());
  }

  iterator insert(iterator itr, const Object& x) {
    Node* p = itr.current;
    ++size_;
    return { p->prev = p->prev->next = new Node{x, p->prev, p} };
  }

  iterator insert(iterator itr, const Object&& x) {
    Node* p = itr.current;
    ++size_;
    return { p->prev = p->prev->next = new Node{std::move(x), p->prev, p} };
  }

  iterator erase(iterator itr) {
    Node* p = itr.current;
    iterator res{ p->next };
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --size_;

    return res;
  }

  iterator erase(iterator from, iterator to) {
    for (iterator itr = from; itr != to; ++itr) {
      itr = erase(itr);
    }

    return to;
  }

 private:
  int size_;
  Node* head_;
  Node* tail_;
};

int main() {
  List<double> list1;
  for (int i = 0; i < 5; ++i) {
    list1.push_back(i);
  }

  List<double> list2;
  for (int i = 0; i < 5; ++i) {
    list2.push_front(i);
  }

  List<double> list3 = list1;
  List<double> list4 = std::move(list2);

  List<double> list5;
  list5 = list3;
  list5 = std::move(list3);

  auto it = list5.begin();
  while (it != list5.end()) {
    std::cout << "list5:" << *it << std::endl;
    ++it;
    list5.pop_front();
  }

  auto itr = list1.begin();
  itr++;
  list1.erase(it);
  while (itr != list1.end()) {
    std::cout << "list1: " << *itr << std::endl;
  }

  return 0;
}
