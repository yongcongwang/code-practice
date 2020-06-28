#include <iostream>
#include <vector>

int GetLeftIndex(
    const std::vector<int>& arr, const int num, int start, int end) {
  if (start < 0 || end < start) {
    return -1;
  }

  int mid = (end + start) / 2;

  if (arr[mid] == num) {
    if (mid == 0 || arr[mid - 1] < num) {
      return mid;
    }

    return GetLeftIndex(arr, num, start, mid - 1);
  }

  if (arr[mid] > num) {
    return GetLeftIndex(arr, num, start, mid - 1);
  }

  return GetLeftIndex(arr, num, mid + 1, end);
}

int GetRightIndex(
    const std::vector<int>& arr, const int num, int start, int end) {
  if (start < 0 || end < start) {
    return -1;
  }

  int mid = (end + start) / 2;

  if (arr[mid] == num) {
    if (mid == arr.size() - 1 || arr[mid + 1] > num) {
      return mid;
    }

    return GetRightIndex(arr, num, mid + 1, end);
  }

  if (arr[mid] > num) {
    return GetRightIndex(arr, num, start, mid - 1);
  }

  return GetRightIndex(arr, num, mid + 1, end);
}

int TimesInArray(const std::vector<int>& arr, const int num) {
  if (arr.empty()) {
    return -1;
  }

  int left = GetLeftIndex(arr, num, 0, arr.size() - 1);
  int right = GetRightIndex(arr, num, left, arr.size() - 1);

  if (left >= 0 && right >= 0) {
    return right - left + 1;
  }

  return -1;
}

int main() {
  std::vector<int> empty;
  std::vector<int> test{
    1, 2, 3, 3, 3, 4, 5
  };

  std::cout << "empty: " << TimesInArray(empty, 3) << std::endl;
  std::cout << "test1: " << TimesInArray(test, 1) << std::endl;
  std::cout << "test2: " << TimesInArray(test, 2) << std::endl;
  std::cout << "test3: " << TimesInArray(test, 3) << std::endl;
  std::cout << "test5: " << TimesInArray(test, 5) << std::endl;
}
