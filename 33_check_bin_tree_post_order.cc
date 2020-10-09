// By yongcong.wang @ 26/05/2020
#include <iostream>
#include <vector>

bool IsBinSearchTreePostOrder(
    std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end) {
  if (it_begin == it_end) {
    return true;
  }

  auto left_child = it_begin;
  while (left_child != it_end) {
    if (*left_child > *it_end) {
      break;
    }
    left_child++;
  }

  auto right_child = left_child;
  while (right_child != it_end) {
    if (*right_child < *it_end) {
      return false;
    }
    right_child++;
  }

  return IsBinSearchTreePostOrder(it_begin, left_child - 1) &&
         IsBinSearchTreePostOrder(left_child, it_end - 1);
}

int main() {
  std::vector<int> arr1{5, 7, 6, 9, 11, 10, 8};
  std::cout << "arr1:"
            << IsBinSearchTreePostOrder(arr1.begin(), arr1.end() - 1) << std::endl;
  std::vector<int> arr2{7, 4, 6, 5};
  std::cout << "arr2:"
            << IsBinSearchTreePostOrder(arr2.begin(), arr2.end() - 1) << std::endl;
}
