// By yongcong.wang @ 11/05/2020
#include <iostream>
#include <vector>

void PrintNoneZeroNumber(const std::vector<char> &digits) {
  auto it = digits.begin();
  while (*it == '0') {
    it++;
  }

  while (it != digits.end()) {
    std::cout << *it;
    it++;
  }
  std::cout << std::endl;
}

void PrintOneToNthDigits(std::vector<char> &digits, const std::size_t index) {
  if (index == digits.size() - 1) {
    PrintNoneZeroNumber(digits);
    return;
  }

  for (std::size_t i = 0; i < 10; ++i) {
    digits[index + 1] = i + '0';
    PrintOneToNthDigits(digits, index + 1);
  }
}

void PrintOneToNDigits(const std::size_t n) {
  if (n == 0) {
    return;
  }

  std::vector<char> digits(n, '0');
  for (std::size_t i = 0; i < 10; ++i) {
    digits[0] = i + '0';
    PrintOneToNthDigits(digits, 0);
  }
}

int main() {
  std::cout << "max 0: " << std::endl;
  PrintOneToNDigits(0);

  std::cout << "max 1: " << std::endl;
  PrintOneToNDigits(1);

  std::cout << "max 3: " << std::endl;
  PrintOneToNDigits(3);
}
