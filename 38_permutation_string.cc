// By yongcong.wang @ 01/06/2020
#include <iostream>
#include <string>
#include <utility>

void PrintPermutations(std::string& str, const int curr_index) {
  if (curr_index == str.size() - 1) {
    std::cout << str << std::endl;
  } else {
    for (int i = curr_index; i < str.size(); ++i) {
      std::swap(str[curr_index], str[i]);
      PrintPermutations(str, curr_index + 1);
      std::swap(str[curr_index], str[i]);
    }
  }
}

void PrintAllPermutations(const std::string& str) {
  if (str.empty()) {
    return;
  }

  std::string tmp(str);
  PrintPermutations(tmp, 0);
}

int main() {
  std::string str = "abc";
  PrintAllPermutations(str);
}

