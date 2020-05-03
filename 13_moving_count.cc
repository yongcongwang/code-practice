// By yongcong.wang @ 03/05/2020
#include <iostream>
#include <vector>

int GetDigitalSum(const int num) {
  int tmp = num;
  int sum = 0;
  while (tmp != 0) {
    sum += tmp % 10;
    tmp = tmp / 10;
  }
  return sum;
}

bool IsReachable(
    const int threshold, const int rows, const int cols, const int row,
    const int col, const std::vector<std::vector<bool>> &visited) {
  if (row >= 0 && row <= rows && col >= 0 && col <= cols &&
      GetDigitalSum(row) + GetDigitalSum(col) <= threshold &&
      !visited[row][col]) {
    return true;
  }
  return false;
}

int GetMovingCountCore(
    const int threshold, const int rows, const int cols, const int row,
    const int col, std::vector<std::vector<bool>> &visited) {
  int count = 0;
  if (IsReachable(threshold, rows, cols, row, col, visited)) {
    visited[row][col] = true;
    count = 1 + 
            GetMovingCountCore(threshold, rows, cols, row - 1, col, visited) +
            GetMovingCountCore(threshold, rows, cols, row + 1, col, visited) +
            GetMovingCountCore(threshold, rows, cols, row, col - 1, visited) +
            GetMovingCountCore(threshold, rows, cols, row, col + 1, visited);
  }
  return count;
}

int GetMovingCount(const int threshold, const int rows, const int cols) {
  if (threshold < 0 || rows < 0 || cols < 0) {
    return 0;
  }

  std::vector<std::vector<bool>> visited(
      rows + 1, std::vector<bool>(cols + 1, false));
  return GetMovingCountCore(threshold, rows, cols, 0, 0, visited);
}

int main() {
  std::cout << "3 * 3, < 5: " << GetMovingCount(5, 2, 2) << std::endl;
  std::cout << "1 * 3, < 5: " << GetMovingCount(5, 0, 2) << std::endl;
  std::cout << "7 * 1, < 2: " << GetMovingCount(2, 6, 0) << std::endl;
  std::cout << "7 * 7, < -2: " << GetMovingCount(-2, 6, 6) << std::endl;
}
