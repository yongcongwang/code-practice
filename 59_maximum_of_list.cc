#include <iostream>
#include <deque>
#include <vector>

std::vector<int> MaxNum(const std::vector<int>& arr, const int window) {
  if (arr.empty() || window < 1) {
    return {};
  }

  std::deque<int> indices;
  indices.push_back(0);
  std::vector<int> max;
  for (std::size_t i = 1; i < arr.size(); ++i) {
    if (i - indices.front() >= window) {
      indices.pop_front();
    }
    if (arr[i] > arr[indices.front()]) {
      indices.clear();
      indices.push_back(i);
    } else {
      if (indices.size() == 1) {
        indices.push_back(i);
      } else {
        if (arr[indices.back()] < arr[i]) {
          indices.pop_back();
          indices.push_back(i);
        }
      }
    }

    if (i >= window - 1) {
      max.push_back(arr[indices.front()]);
    }
  }

  return max;
}

int main() {
  std::vector<int> arr{
    6, 3, 3, 3, 3, 3, 5, 1
  };

  auto result = MaxNum(arr, 3);
  for (auto ele : result) {
    std::cout << ele << std::endl;
  }
}
