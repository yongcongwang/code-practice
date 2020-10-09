#include <iostream>
#include <array>
#include <algorithm>

bool IsContinousCards(std::array<int, 5> arr) {
  std::sort(arr.begin(), arr.end());

  int king_cnt = arr.front() == 0 ? 1 : 0;
  int break_cnt = 0;
  for (int i = 1; i < 5; ++i) {
    if (arr[i] == 0) {
      ++king_cnt;
      continue;
    }
    if (arr[i] == arr[i - 1]) {
      return false;
    }

    break_cnt = arr[i] - arr[i - 1] - 1;
  }

  return king_cnt >= break_cnt;
}

int main() {
  std::cout << IsContinousCards({0, 1, 2, 3, 4}) << std::endl;
  std::cout << IsContinousCards({0, 1, 2, 3, 5}) << std::endl;
  std::cout << IsContinousCards({0, 1, 2, 3, 6}) << std::endl;
  std::cout << IsContinousCards({3, 1, 2, 3, 6}) << std::endl;
  std::cout << IsContinousCards({5, 1, 2, 3, 6}) << std::endl;
}
