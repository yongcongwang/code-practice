#include <iostream>
#include <vector>

int FirstOneDigit(int num) {
  int result(0);
  while((num & 1) == 0 && result < 8 * sizeof(int)) {
    num = num >> 1;
    result++;
  }

  return result;
}

bool IsDigitKOne(int num, int k) {
  num = num >> k;
  return num & 1;
}

std::pair<int, int> TwoTimesNumber(const std::vector<int>& arr) {
  if (arr.empty()) {
    return {-1, -1};
  }

  int result_or(0);
  for (auto num : arr) {
    result_or ^= num;
  }

  int digit_one = FirstOneDigit(result_or);

  int result1(0);
  int result2(0);

  for (auto num : arr) {
    if (IsDigitKOne(num, digit_one)) {
      result1 ^= num;
    } else {
      result2 ^= num;
    }
  }

  return {result1, result2};
}

int main() {
  std::vector<int> test{
    2, 4, 3, 6, 3, 2, 5, 5
  };
  auto result = TwoTimesNumber(test);

  std::cout << "result: " << result.first << ", " << result.second << std::endl;
}
