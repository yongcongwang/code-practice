// By yongcong.wang @ 29/04/2020
#include <iostream>
#include <queue>
#include <stack>

template <typename T> class MyQueue {
 public:
  void AppendTail(const T &node) {
    stack1.push(node);
  }
  T DeleteHead() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        T &tmp = stack1.top();
        stack1.pop();
        stack2.push(tmp);
      }
    }

    if (stack2.empty()) {
      std::cout << "No element in queue" << std::endl;
      // TODO: the exception
    }

    T head = stack2.top();
    stack2.pop();
    return head;
  }

 private:
  std::stack<T> stack1;
  std::stack<T> stack2;
};

int main() {
  MyQueue<int> my_queue;
  my_queue.AppendTail(5);
  my_queue.AppendTail(4);
  my_queue.AppendTail(3);
  my_queue.AppendTail(2);
  my_queue.AppendTail(1);

  std::cout << "delete head: " << my_queue.DeleteHead() << std::endl;
  std::cout << "delete head: " << my_queue.DeleteHead() << std::endl;
  std::cout << "delete head: " << my_queue.DeleteHead() << std::endl;
  std::cout << "delete head: " << my_queue.DeleteHead() << std::endl;
  std::cout << "delete head: " << my_queue.DeleteHead() << std::endl;
}
