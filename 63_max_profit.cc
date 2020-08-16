#include <iostream>

#include <vector>

int MaxProfit(const std::vector<int>& arr) {
  if (arr.size() < 2) {
    return -1;
  }

  int min = arr.front();
  int max = arr[1] - arr[0];
  for (auto num : arr) {
    max = std::max(max, num - min);
    min = std::min(num, min);
  }

  return max;
}

int main() {
  std::vector<int> test{9, 11, 8, 5, 7, 12, 16, 14};
  std::cout << "result: " << MaxProfit(test) << std::endl;
}
