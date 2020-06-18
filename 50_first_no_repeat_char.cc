#include <string>
#include <unordered_map>
#include <iostream>

char FirstNoRepeatChar(const std::string& str) {
  if (str.empty()) {
    return ' ';
  }

  std::unordered_map<char, int> map_char_cnt;
  for (const auto& c : str) {
    if (map_char_cnt.find(c) == map_char_cnt.end()) {
      map_char_cnt[c] = 1;
    } else {
      map_char_cnt[c] += 1;
    }
  }

  for (const auto& c : str) {
    if (map_char_cnt[c] == 1) {
      return c;
    }
  }

  return ' ';
}

int main() {

  std::string test = "aaa";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
  test = "aba";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
  test = "";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
  test = "a";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
  test = "abaccdeff";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
  test = "dbaccdeff";
  std::cout << test << " 1st occ: " << FirstNoRepeatChar(test) << std::endl;
}


