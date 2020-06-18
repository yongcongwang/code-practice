#include <iostream>
#include <vector>

int KthUglyNumber(const int k) {
  if (k < 1) {
    return -1;
  }

  int ugly_base_2 = 0;
  int ugly_base_3 = 0;
  int ugly_base_5 = 0;
  std::vector<int> ugly_list;
  ugly_list.push_back(1);
  int curr_ugly_cnt = 1;
  while (curr_ugly_cnt < k) {
    ugly_list.push_back(
        std::min(std::min(ugly_list[ugly_base_2] * 2,
                          ugly_list[ugly_base_3] * 3),
                 ugly_list[ugly_base_5] * 5));
    while (ugly_list[ugly_base_2] * 2 <= ugly_list.back()) {
      ugly_base_2++;
    }
    while (ugly_list[ugly_base_3] * 3 <= ugly_list.back()) {
      ugly_base_3++;
    }
    while (ugly_list[ugly_base_5] * 5 <= ugly_list.back()) {
      ugly_base_5++;
    }

    curr_ugly_cnt++;
  }

  return ugly_list.back();
}

int main() {
  std::cout << 5 << "th ugly number is "  <<  KthUglyNumber(5) << std::endl;
  std::cout << 1500 << "th ugly number is "  <<  KthUglyNumber(1500) << std::endl;
}
