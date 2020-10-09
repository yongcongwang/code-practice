// By yongcong.wang @ 11/06/2020
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void PrintMinArray(std::vector<int>& arr) {
  if (arr.empty()) {
    return;
  }
  std::sort(arr.begin(), arr.end(),
            [](int a, int b) {
              return std::stoi(std::to_string(a) + std::to_string(b)) < 
                     std::stoi(std::to_string(b) + std::to_string(a));
            });

  for (auto ele : arr) {
    std::cout << ele;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> arr{
    3, 34, 15, 47
  };
  PrintMinArray(arr);
}
