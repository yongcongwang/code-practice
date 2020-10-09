#include <iostream>
#include <cmath>

int GetNumLength(int num) {
  int cnt(0);
  while (num != 0) {
    num /= 10;
    cnt ++;
  }

  return cnt;
}

int OneAppearance(const int num) {
  if (num <= 0) {
    return 0;
  }

  const int length = GetNumLength(num);
  if (length == 1) {
    return 1;
  }

  const int tmp = std::pow(10, length - 1);
  const int first = num / tmp;
  const int top_one_cnt = first == 1 ? num % tmp + 1 : std::pow(10, length - 1);
  const int top_other_cnt = first * (length - 1) * std::pow(10, length - 2);
  const int sub_cnt = OneAppearance(num % 10);

  return top_one_cnt + top_other_cnt + sub_cnt;
}

int main() {
  std::cout << "num " << 0 << " contains 1: " << OneAppearance(0) << std::endl;
  std::cout << "num " << 1 << " contains 1: " << OneAppearance(1) << std::endl;
  std::cout << "num " << 9 << " contains 1: " << OneAppearance(9) << std::endl;
  std::cout << "num " << 10 << " contains 1: " << OneAppearance(10) << std::endl;
  std::cout << "num " << 11 << " contains 1: " << OneAppearance(11) << std::endl;
  std::cout << "num " << 12 << " contains 1: " << OneAppearance(12) << std::endl;
  std::cout << "num " << 22 << " contains 1: " << OneAppearance(22) << std::endl;
  std::cout << "num " << 55 << " contains 1: " << OneAppearance(55) << std::endl;
  std::cout << "num " << 65534 << " contains 1: " << OneAppearance(65534) << std::endl;
}
