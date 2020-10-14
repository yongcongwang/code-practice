
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

   protected:
    Node* current;

    Object& retrieve() {
      return current->val;
    }

    const_iterator(Node* p) : current(p) {}

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
    delete head;
    delete tail;
  }

  List(const List& rhs) {
    init();
    for (auto& x : rhs) {
      push_back(x)
    }
  }
  
  List& operator=(const List& rhs) {
    List copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  List(const List&& rhs)
      : size_{rhs.size_}, head_(rhs.head_), tail_(rhs.tail_) {
    rhs.size_ = 0;
    rhs.head_ = nullptr;
    rhs.tail_ = nullptr;
  }

  List& operator=(const List&& rhs) {
    std::swap(size_, rhs.size_);
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    return *this;
  }

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
