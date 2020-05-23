// By yongcong.wang @ 23/05/2020
#include <iostream>
#include <stack>
#include <vector>

bool IsStackInOutOrder(
    const std::vector<int>& in, const std::vector<int>& out) {
  if (in.empty() && out.empty()) {
    return true;
  }

  if (in.size() != out.size()) {
    return false;
  }

  auto it_in = in.begin();
  auto it_out = out.begin();
  std::stack<int> arr;
  while (it_in != in.end()) {
    if (arr.empty()) {
      arr.push(*it_in);
      it_in++;
      continue;
    }
    if (arr.top() == *it_out) {
      arr.pop();
      it_out++;
    } else {
      arr.push(*it_in);
      it_in++;
    }
  }

  while (!arr.empty()) {
    if (arr.top() != *it_out) {
      return false;
    }
    arr.pop();
    it_out++;
  }

  return true;
}

int main() {
  std::vector<int> in1{1, 2, 3, 4, 5};
  std::vector<int> out1{4, 5, 3, 2, 1};
  std::vector<int> out2{4, 3, 5, 1, 2};

  std::cout << IsStackInOutOrder(in1, out1) << std::endl;
  std::cout << IsStackInOutOrder(in1, out2) << std::endl;
}
