// By yongcong.wang @ 21/05/2020
#include <iostream>
#include <vector>

void PrintMatrixCircle(
    const std::vector<std::vector<int>>& matrix, const int start) {
  if (matrix.empty() || start < 0) {
    return;
  }

  const int row_max = matrix.size() - start - 1;
  const int col_max = matrix.front().size() - start - 1;


  // first step
  for (int i = start; i <= col_max; ++i) {
    std::cout << matrix[start][i] << " ";
  }

  // second step
  if (start < row_max) {
    for (int i = start + 1; i <= row_max; ++i) {
      std::cout << matrix[i][col_max] << " ";
    }
  }

  // third step
  if (start < row_max && start < col_max) {
    for (int i = col_max - 1; i >= start; --i) {
      std::cout << matrix[row_max][i] << " ";
    }
  }

  // forth step
  if (start < row_max - 1 && start < col_max) {
    for (int i = row_max - 1; i >= start + 1; --i) {
      std::cout << matrix[i][start] << " ";
    }
  }
}

void PrintMatrixReverse(const std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) {
    return;
  }

  int start(0);
  while (start * 2 < matrix.front().size() && start * 2 < matrix.size()) {
    PrintMatrixCircle(matrix, start);
    start++;
  }
}

int main() {
  std::vector<std::vector<int>> test{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  PrintMatrixReverse(test);
}
