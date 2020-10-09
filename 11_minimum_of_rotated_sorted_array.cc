// By yongcong.wang @ 01/05/2020
#include <iostream>
#include <vector>

int GetMinimumTravesal(const std::vector<int> &arr) {
  if (arr.empty()) {
    return 0;
  }

  int min = arr[0];
  for (auto &num : arr) {
    if (num < min) {
      min = num;
    }
  }

  return min;
}

int GetMinimumBin(const std::vector<int> &arr, const int start_index, const int end_index) {
  if (start_index == end_index) {
    return arr[start_index];
  }

  if (end_index - start_index == 1) {
    return arr[start_index] < arr[end_index] ? arr[start_index] : arr[end_index];
  }

  int mid_index = (start_index + end_index) / 2;


  if (arr[start_index] == arr[mid_index] && arr[mid_index] == arr[end_index]) {
    return GetMinimumTravesal(arr);
  }

  if (arr[mid_index] >= arr[start_index]) {
    return GetMinimumBin(arr, mid_index, end_index);
  } else {
    return GetMinimumBin(arr, start_index, mid_index);
  }
}

int GetMinimumBinary(const std::vector<int> &arr) {
  if (arr.empty()) {
    return 0;
  }

  return GetMinimumBin(arr, 0, arr.size() - 1);
}

int main() {
  std::vector<int> arr1{3, 4, 5, 1, 2};
  std::vector<int> arr2{3, 4, 4, 1, 2};
  std::vector<int> arr3{1, 1, 1, 0, 1};
  std::vector<int> arr4{3};
  std::vector<int> arr5;
  std::cout << GetMinimumBinary(arr1) << std::endl;
  std::cout << GetMinimumBinary(arr2) << std::endl;
  std::cout << GetMinimumBinary(arr3) << std::endl;
  std::cout << GetMinimumBinary(arr4) << std::endl;
  std::cout << GetMinimumBinary(arr5) << std::endl;
}
