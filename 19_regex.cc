// By yongcong.wang @ 14/05/2020
#include <iostream>

bool IsMatchRecursive(char* str, char* pattern) {
  if (*str == '\0' && *pattern == '\0') {
    return true;
  }

  if (*str != '\0' && *pattern == '\0') {
    return false;
  }

  if (*(pattern + 1) == '*') {
    if (*str == *pattern || *pattern == '.' && *str != '\0') {
      return IsMatchRecursive(str, pattern + 2) ||
             IsMatchRecursive(str + 1, pattern + 2) ||
             IsMatchRecursive(str + 1, pattern);
    } else {
      return IsMatchRecursive(str, pattern + 2);
    }
  }

  if (*str == *pattern || *pattern == '.' && *str != '\0') {
    return IsMatchRecursive(str + 1, pattern + 1);
  }

  return false;
}

bool IsMatch(char* str, char* pattern) {
  if (str == nullptr || pattern == nullptr) {
    return false;
  }

  return IsMatchRecursive(str, pattern);
}

int main() {
  char str1[10] = "aaa";
  char pattern1[10] = "a.a";
  char pattern2[10] = "ab*ac*a";
  char pattern3[10] = "aa.a";
  char pattern4[10] = "ab*a";
  std::cout << "pattern1: " << IsMatch(str1, pattern1) << std::endl;
  std::cout << "pattern2: " << IsMatch(str1, pattern2) << std::endl;
  std::cout << "pattern3: " << IsMatch(str1, pattern3) << std::endl;
  std::cout << "pattern4: " << IsMatch(str1, pattern4) << std::endl;
}
