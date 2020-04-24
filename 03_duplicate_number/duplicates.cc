// By yongcong.wang @ 22/04/2020
#include <vector>
#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int GetDuplicateNum(std::vector<int> &arr) {
  if (arr.empty()) {
    return -1;
  }

  for (int i = 0; i < arr.size(); ++i) {
    while (arr[i] != i) {
      if (arr[arr[i]] == arr[i]) {
        return arr[i];
      }
      swap(arr[arr[i]], arr[i]);
    }
  }

  return -1;
}

int NumCnt(const std::vector<int> &arr, const int start, const int end) {
  int cnt(0);
  for (auto num : arr) {
    if (num >= start && num <=end) {
      cnt++;
    }
  }
  return cnt;
}
  
int GetRangeDuplication(const std::vector<int> &arr, const int start,
                        const int end) {
  if (start == end) {
    return -1;
  }

  if (end - start == 1) {
    const int cnt_start = NumCnt(arr, start, start);
    return cnt_start > 1 ? start : end;
  }

  const int mid = (start + end) / 2;
  return NumCnt(arr, start, mid) > mid - start + 1 ? 
      GetRangeDuplication(arr, start, mid) : GetRangeDuplication(arr, mid, end);
}

int GetDuplicatedNum(const std::vector<int> &arr) {
  if (arr.empty()) {
    return -1;
  }

  return GetRangeDuplication(arr, 0, arr.size() - 1);
}

int main() {
  std::vector<int> test1 = {2, 3, 5, 0, 5, 4, 1};
  std::cout << GetDuplicatedNum(test1) << std::endl;

  std::vector<int> test2 = {3, 3, 3, 3, 3, 3, 3};
  std::cout << GetDuplicateNum(test2) << std::endl;

  std::vector<int> test3;
  std::cout << GetDuplicateNum(test3) << std::endl;

  std::vector<int> test4 = {0, 1, 2, 3, 4, 5, 6};
  std::cout << GetDuplicateNum(test3) << std::endl;
}
