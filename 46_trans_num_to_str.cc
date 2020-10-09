#include <iostream>
#include <vector>
#include <string>

std::size_t TransNumberToString(const std::size_t num) {
  const std::string num_str = std::to_string(num);
  const std::size_t length(num_str.size());
  if (length < 2) {
    return 1;
  }

  std::vector<int> sum(length + 1, 0);
  sum[length - 1] = 1;
  sum[length] = 1;
  for (int i = length - 2; i >= 0; --i) {
    sum[i] = sum[i + 1];
    const int tmp = std::stoi(std::string(1, num_str[i]) +
                              std::string(1, num_str[i + 1]));
    if (tmp < 26) {
      sum[i] += sum[i + 2];
    }
  }

  return sum.front();
}

int main() {
  const std::size_t test = 12258;
  std::cout << "num [" << test << "] is " << TransNumberToString(test)
            << std::endl;
}
