
template <typename Object>
class List {
 private:
  struct Node {
    Node(const Object& val = Object{}, Node* p = nullptr, Node* n = nullptr)
        : val(val), next(n), prev(p) {}
    Node(const Object&& val = Object{}, Node* p = nullptr, Node* n = nullptr)
        : val(std::move(d)), next(n), prev(p) {}

    Object val;
    Node* next;
    Node* prev;
  };

 public:
  class const_iterator {
   public:
    const_iterator() : current{} {}
   protected:
    Node* current;
    Object& retrieve() 
  };
  class iterator : public const_iterator {};

 public:
  List() {}
  List(const List& rhs) {}
  ~List() {}
  List& operator=(const List& rhs) {}
  List(const List&& rhs) {}
  List& operator=(const List&& rhs) {}

 public:
  iterator begin() {
    return {head->next};
  }
  iterator end() {
    return {tail};
  }
  const_iterator begin() const {
    return {head->next};
  }
  const_iterator end() const {
    return {tail};
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
  void push_front(const Object&& x) {
    insert(end(), std::move(x));
  }

  void pop_front() {
    erase(begin());
  }
  void pop_back() {
    erase(--end());
  }

  iterator insert(iterator itr, const Object& x) { }
  iterator insert(iterator itr, const Object&& x) { }
  iterator erase(iterator itr) { }
  iterator erase(iterator from, iterator to) { }

 private:
  int size_;
  Node* head_;
  Node* tail_;
};
