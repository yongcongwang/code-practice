#include <iostream>
#include <cmath>

int GetDigitsSum(const int digits) {
  if (digits == 1) {
    return 10;
  }

  return 9 * std::pow(10, digits - 1);
}

int GetDigitsStart(const int digits) {
  if (digits == 1) {
    return 0;
  }

  return std::pow(10, digits - 1);
}

int GetNumDigits(int num, int digits) {
  int target_num = GetDigitsStart(digits) + num / digits;
  int digit_right = digits - num % digits;

  while (digit_right > 1) {
    target_num /= 10;
  }
  return target_num % 10;
}

int GetDigitInStream(int num) {
  if (num < 0) {
    return -1;
  }

  int digits = 1;
  while (true) {
    int digits_sum = GetDigitsSum(digits);
    if (num < digits_sum) {
      return GetNumDigits(num, digits);
    }
    digits ++;
    num -= digits_sum;
  }
}

int main() {
  std::cout << "5: " << GetDigitInStream(5) << std::endl;
  std::cout << "13: " << GetDigitInStream(13) << std::endl;
  std::cout << "19: " << GetDigitInStream(19) << std::endl;
}
