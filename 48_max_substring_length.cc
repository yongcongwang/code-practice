#include <string>
#include <iostream>
#include <unordered_map>

int MaximumSubstringWithoutRepeat(const std::string& str) {
  if (str.empty()) {
    return 0;
  }

  std::unordered_map<char, int> substring_idxs;
  int max_length(0);
  int start_idx(0);

  for (int i = 0; i < str.size(); ++i) {
    auto it = substring_idxs.find(str[i]);
    if (it != substring_idxs.end()){
      const int new_start = it->second + 1;
      for (auto j = start_idx; j < new_start; ++j) {
        substring_idxs.erase(str[j]);
      }
      start_idx = new_start;
    }
    substring_idxs[str[i]] = i;
    max_length = std::max(max_length, i - start_idx + 1);
  }

  return max_length;
}

int main() {
  const std::string test1 = "";
  const std::string test2 = "a";
  const std::string test3 = "aa";
  const std::string test4 = "aaa";
  const std::string test5 = "aba";
  const std::string test6 = "acfr";
  const std::string test7 = "arabcacfr";

  std::cout << "string: [" << test1 << "] is "
            << MaximumSubstringWithoutRepeat(test1) << std::endl;
  std::cout << "string: [" << test2 << "] is "
            << MaximumSubstringWithoutRepeat(test2) << std::endl;
  std::cout << "string: [" << test3 << "] is "
            << MaximumSubstringWithoutRepeat(test3) << std::endl;
  std::cout << "string: [" << test4 << "] is "
            << MaximumSubstringWithoutRepeat(test4) << std::endl;
  std::cout << "string: [" << test5 << "] is "
            << MaximumSubstringWithoutRepeat(test5) << std::endl;
  std::cout << "string: [" << test6 << "] is "
            << MaximumSubstringWithoutRepeat(test6) << std::endl;
  std::cout << "string: [" << test7 << "] is "
            << MaximumSubstringWithoutRepeat(test7) << std::endl;
}
