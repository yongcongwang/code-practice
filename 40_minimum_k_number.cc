// By yongcong.wang @ 02/06/2020

#include <set>
#include <functional>
#include <iostream>
#include <vector>

bool GetMinKNumbers(
    const std::vector<int>& arr, const int k,
    std::multiset<int, std::greater<int>>* const result) {
  if (k > arr.size() || k <= 0) {
    return false;
  }

  std::multiset<int, std::greater<int>> tmp(arr.begin(), arr.begin() + k);
  result->swap(tmp);

  auto it = arr.begin() + k;
  while (it != arr.end()) {
    if (*it < *result->begin()) {
      result->erase(result->begin());
      result->insert(*it);
    }

    it++;
  }

  return true;
}

int main() {
  const std::vector<int> arr{
    4, 5, 1, 6, 2, 7, 3, 8
  };

  std::multiset<int, std::greater<int>> result;
  std::cout << "result: " << GetMinKNumbers(arr, 7, &result) << std::endl;
  result;
}
