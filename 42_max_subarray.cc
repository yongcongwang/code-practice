#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

int MaxSubarray(const std::vector<int>& arr) {
  if (arr.empty()) {
    return -1;
  }

  int max= std::numeric_limits<int>::min();
  int sum = 0;
  for (const auto& ele : arr) {
    sum += ele;
    max = std::max(sum, max);
    sum = sum < 0 ? 0 : sum;
  }

  return max;
}

int main() {
  std::vector<int> arr{
    1, -2, 3, 10, -4, 7, 2, -5
  };

  std::vector<int> arr_neg{
    -1, -2, -3, -10, -4, -7, -2, -5
  };

  std::cout << "max is " << MaxSubarray(arr) << std::endl;
  std::cout << "max is " << MaxSubarray(arr_neg) << std::endl;
}
