#include <iostream>
#include <exception>
#include <algorithm>

template <typename Object>
class Vector {
 public:
  explicit Vector(int size = 0)
      : size_(0), capacity_(size_ + 10), objects_(new Object[capacity_]) {}

  Vector(const Vector& rhs)
      : size_(rhs.size_), capacity_(rhs.capacity_),
        objects_(new Object[capacity_]) {
    for (std::size_t i = 0; i < size_; ++i) {
      objects_[i] = rhs.objects_[i];
    }
  }

  Vector& operator=(const Vector& rhs) {
    Vector copied(rhs);
    std::swap(*this, copied);
    return *this;
  }

  ~Vector() { 
    delete[] objects_;
  }

  Vector(Vector&& rhs)
      : size_(rhs.size_), capacity_(rhs.capacity_), objects_(rhs.objects_) {
    rhs.size_ = 0;
    rhs.capacity_ = 0;
    rhs.objects_ = nullptr;
  }

  Vector& operator=(Vector&& rhs) {
    std::swap(size_, rhs.size_);
    std::swap(capacity_, rhs.capacity_);
    std::swap(objects_, rhs.objects_);
    return *this;
  }

 public:
  void resize(int new_size) {
    if (new_size > capacity_) {
      reserve(new_size * 2);
    }

    size_ = new_size;
  }

  void reserve(int new_capacity) {
    if (new_capacity < size_) {
      return;
    }

    Object *new_array = new Object[new_capacity];
    for (int i = 0; i < size_; ++i) {
      new_array[i] = objects_[i];
    }

    capacity_ = new_capacity;
    std::swap(objects_, new_array);
    delete[] new_array;
  }

  Object& operator[](int index) {
    if (index < 0 || size_ == 0 || index >= size_) {
      throw std::out_of_range("invalid index!");
    }
    return objects_[index];
  }

  const Object& operator[](int index) const {
    if (index < 0 || size_ == 0 || index >= size_) {
      throw std::out_of_range("invalid index!");
    }
    return objects_[index];
  }

  bool empty() const {
    return size_ == 0;
  }

  int size() const {
    return size_;
  }

  int capacity() const {
    return capacity_;
  }

  void push_back(const Object& x) {
    if (size_ == capacity_) {
      reserve(2 * capacity_ + 1);
    }

    objects_[size_] = x;
    ++size_;
  }

  void push_back(const Object&& x) {
    if (size_ == capacity_) {
      reserve(2 * capacity_ + 1);
    }

    objects_[size_] = std::move(x);
    ++size_;
  }

  void pop_back() {
    --size_;
  }

  const Object& back() const {
    if (size_ == 0) {
      throw std::out_of_range("invalid index!");
    }
    return objects_[size_ - 1];
  }

  const Object& front() const {
    if (size_ == 0) {
      throw std::out_of_range("invalid index!");
    }
    return objects_[0];
  }

 public:
  typedef Object* iterator;
  typedef const Object* const_iterator;

  iterator begin() {
    return &objects_[0];
  }

  const_iterator begin() const {
    return &objects_[0];
  }

  iterator end() {
    return &objects_[size_];
  }
  const_iterator end() const {
    return &objects_[size_];
  }

 private:
  int size_;
  int capacity_;
  Object* objects_;
};

int main() {
  Vector<double> my_vector1;
  for (int i = 0; i < 10; ++i) {
    my_vector1.push_back(static_cast<double>(i));
  }

  Vector<double> my_vector2(my_vector1);
  Vector<double> my_vector3 = my_vector2;
  Vector<double> my_vector4(std::move(my_vector3));
  Vector<double> my_vector5 = std::move(my_vector4);

  my_vector1.resize(5);
  std::cout << "my_vector_size: " << my_vector1.size() << std::endl;
  my_vector1.reserve(25);
  std::cout << "my_vector_size: " << my_vector1.size() << std::endl;
  std::cout << "my_vector_capacity: " << my_vector1.capacity() << std::endl;
  std::cout << "my_vector_empty: " << my_vector1.empty() << std::endl;
  for (int i = 0; i < 5; ++i) {
    my_vector1.push_back(std::move(my_vector5[i + 3]));
  }
  std::cout << "my_vector_front: " << my_vector1.front() << std::endl;
  std::cout << "my_vector_back: " << my_vector1.back() << std::endl;

  Vector<double>::iterator it = my_vector1.begin();
  while (it != my_vector1.end()) {
    std::cout << "," << *it << std::endl;
    it++;
  }
}
