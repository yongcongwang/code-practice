// By yongcong.wang @ 04/06/2020
#include <iostream>
#include <queue>
#include <functional>

class StreamMedian {
 public:
  StreamMedian() = default;
  ~StreamMedian() = default;

  void Insert(const int value) {
    if (min_heap_.size() == max_heap_.size()) {
      min_heap_.push(value);
      max_heap_.push(min_heap_.top());
      min_heap_.pop();

    } else {
      max_heap_.push(value);
      min_heap_.push(max_heap_.top());
      max_heap_.pop();
    }
  }

  int Median() const {
    const int num_cnt = min_heap_.size() + max_heap_.size();
    if (num_cnt == 0) {
      return -1;
    }

    if (num_cnt & 1) {
      return max_heap_.top();
    }

    return (max_heap_.top() + min_heap_.top()) / 2;
  }

 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;
  std::priority_queue<int, std::vector<int>, std::less<int>> max_heap_;
};

int main() {
  std::vector<int> arr{
    5, 3, 2, 7, 9, 4, 1
  };

  StreamMedian store;
  std::cout << "empty median: " << store.Median() << std::endl;
  for (auto ele : arr) {
    store.Insert(ele);
    std::cout << "median: " << store.Median() << std::endl;
  }
}
