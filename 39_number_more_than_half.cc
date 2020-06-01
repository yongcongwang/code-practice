// By yongcong.wang @ 01/06/2020

#include <iostream>
#include <vector>

int NumAppearMoreThanHalf(const std::vector<int>& arr) {
  if (arr.empty()) {
    return -1;
  }

  int base = arr.front();
  int base_cnt = 0;

  for (const auto &ele : arr) {
    if (ele == base) {
      base_cnt++;
    } else if (base_cnt > 0) {
      base_cnt--;
    } else {
      base = ele;
      base_cnt = 1;
    }
  }

  return base;
}

int main() {
  std::vector<int> arr{
    1, 2, 3, 2, 2, 2, 5, 4, 2
  };

  std::cout << NumAppearMoreThanHalf(arr) << std::endl;
}


