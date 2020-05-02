// By yongcong.wang @ 02/05/2020
#include <iostream>
#include <vector>
#include <string>

bool IsPathInMatrixCore(
    const std::vector<std::vector<char>> &matrix,
    const int row, const int col, std::vector<std::vector<bool>> &map,
    const std::vector<char> &path, const int index) {
  if (index == path.size()) {
    return true;
  }

  bool result = false;
  // up
  int row_up = row - 1;
  if (row_up >=0 && map[row_up][col] && matrix[row_up][col] == path[index]) {
    auto temp = map;
    temp[row_up][col] = false;
    result = result ||
             IsPathInMatrixCore(matrix, row_up, col, temp, path, index + 1);
  }
  // down
  int row_down = row + 1;
  if (row_down <= matrix.size() - 1 && map[row_down][col] &&
      matrix[row_down][col] == path[index]) {
    auto temp = map;
    temp[row_down][col] = false;
    result = result ||
             IsPathInMatrixCore(matrix, row_down, col, temp, path, index + 1);
  }
  // left
  int col_left = col - 1;
  if (col_left >=0 && map[row][col_left] &&
      matrix[row][col_left] == path[index]) {
    auto temp = map;
    temp[row][col_left] = false;
    result = result ||
             IsPathInMatrixCore(matrix, row, col_left, temp, path, index + 1);
  }

  // right
  int col_right = col + 1;
  if (col_right <= matrix.front().size() - 1 && map[row][col_right] &&
      matrix[row][col_right] == path[index]) {
    auto temp = map;
    temp[row][col_right] = false;
    result = result ||
             IsPathInMatrixCore(matrix, row, col_right, temp, path, index + 1);
  }

  return result;
}

bool IsPathInMatrix(const std::vector<std::vector<char>> &matrix,
                    const std::vector<char> &path) {
  if (matrix.empty() || path.empty()) {
    return false;
  }

  std::vector<std::vector<bool>> map(
      matrix.size(), std::vector<bool>(matrix.front().size(), true));

  std::vector<char> path_to_find(path);

  for (int row = 0; row < matrix.size(); ++row) {
    for (int col = 0; col < matrix.front().size(); ++col) {
      if (matrix[row][col] == path.front()) {
        auto temp = map;
        temp[row][col] = false;
        return IsPathInMatrixCore(matrix, row, col, temp, path_to_find, 1);
      }
    }
  }

  return false;
}

int main() {
  std::string str1 = "bfce";
  std::string str2 = "abfb";

  std::vector<char> path1(str1.begin(), str1.end());
  std::vector<char> path2(str2.begin(), str2.end());
  std::vector<char> path3(2, 'a');
  path3.push_back('\0');
  std::vector<char> path4;

  std::vector<char> row1{'a', 'b', 't', 'g'};
  std::vector<char> row2{'c', 'f', 'c', 's'};
  std::vector<char> row3{'j', 'd', 'e', 'h'};
  std::vector<std::vector<char>> matrix1;
  matrix1.push_back(row1);
  matrix1.push_back(row2);
  matrix1.push_back(row3);
  std::vector<std::vector<char>> matrix2(1, std::vector<char>(5, 'a'));
  std::vector<std::vector<char>> matrix3;

  std::cout << "test1: " << IsPathInMatrix(matrix1, path1) << std::endl;
  std::cout << "test0: " << IsPathInMatrix(matrix1, path2) << std::endl;
  std::cout << "test0: " << IsPathInMatrix(matrix2, path2) << std::endl;
  std::cout << "test1: " << IsPathInMatrix(matrix2, path3) << std::endl;
  std::cout << "test0: " << IsPathInMatrix(matrix3, path3) << std::endl;


}
