#include <iostream>
#include <vector>
#include <deque>

std::pair<int, int> SumNumbers(const std::vector<int>& arr, const int num) {
  if (arr.empty()) {
    return {0, 0};
  }

  int start = 0;
  int end = arr.size() - 1;
  while (end > start) {
    if (arr[start] + arr[end] > num) {
      end--;
    } else if (arr[start] + arr[end] < num) {
      start++;
    } else {
      return {arr[start], arr[end]};
    }
  }

  return {0, 0};
}

void PrintVec(int start, int end) {
  while (start < end) {
    std::cout << start << " ";
    start++;
  }
  std::cout << end << std::endl;
}

void SumSequence(const int num) {
  if (num < 2) {
    return;
  }

  int start = 1;
  int end = 2;
  int sum = 3;

  while (end < num) {
    if (sum > num) {
      sum -= start;
      start++;
    } else if (sum < num) {
      end++;
      sum += end;
    } else {
      PrintVec(start, end);
      end++;
      sum += end;
    }
  }
}

int main() {
  std::vector<int> arr{
    1, 2, 4, 7, 11, 15
  };

  auto result = SumNumbers(arr, 0);
  std::cout << "sum 0: " << result.first << " " << result.second << std::endl;
  result = SumNumbers(arr, 8);
  std::cout << "sum 8: " << result.first << " " << result.second << std::endl;
  result = SumNumbers(arr, 15);
  std::cout << "sum 15: " << result.first << " " << result.second << std::endl;
  result = SumNumbers(arr, 30);
  std::cout << "sum 30: " << result.first << " " << result.second << std::endl;

  std::cout << "1: " << std::endl;
  SumSequence(1);
  std::cout << "3: " << std::endl;
  SumSequence(3);
  std::cout << "15: " << std::endl;
  SumSequence(15);
}
