// By yongcong.wang @ 22/04/2020

#include <iostream>

class Singleton {
 public:
  static Singleton *GetInstance() {
    static Singleton instance;
    return &instance;
  }
  ~Singleton() = default;
  Singleton(const Singleton &rhs) = delete;
  Singleton &operator=(const Singleton &rhs) = delete;

 public:
  void print() { std::cout << instance_cnt_ << std::endl; }

 private:
  Singleton() : instance_cnt_(0) { instance_cnt_++; };
  int instance_cnt_;
};

int main() {
  Singleton::GetInstance()->print();
  Singleton::GetInstance()->print();
  Singleton::GetInstance()->print();
}
