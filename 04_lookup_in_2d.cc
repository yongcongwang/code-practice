// By yongcong.wang @ 25/04/2020
#include <iostream>
#include <vector>

bool IsVectorContainNum(
    const std::vector<std::vector<int>> &arr, const int num) {
  if (arr.empty()) {
    return false;
  }

  int row = 0;
  int col = arr.front().size() - 1;

  while (row < arr.size() && col >=0) {
    if (arr[row][col] == num) {
      return true;
    } else if (arr[row][col] > num) {
      col--;
    } else {
      row++;
    }
  }

  return false;
}

int main() {
  std::vector<std::vector<int>> arr = {
    {1, 2, 8, 9},
    {2, 4, 8, 12},
    {4, 7, 10, 13},
    {6, 8, 11, 15}
  };

  std::cout << "2 in arr: " << IsVectorContainNum(arr, 2) << std::endl;
  std::cout << "3 in arr: " << IsVectorContainNum(arr, 3) << std::endl;
  std::cout << "0 in arr: " << IsVectorContainNum(arr, 0) << std::endl;
  std::cout << "16 in arr: " << IsVectorContainNum(arr, 16) << std::endl;
}
