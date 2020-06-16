#include <iostream>
#include <array>
#include <string>

std::size_t TransNumberToString(const std::size_t num) {
  const std::string num_str = std::to_string(num);

  const std::size_t length(num_str.size());
  std::array<length + 1, int> sum(length + 1, 0);
  sum[length - 1] = 1;
  for (std::size_t i = length - 2; i >= 0; --i) {
    sum[i] += sum[i + 1];
    const int tmp = std::stoi(std::to_string(sum[i]) +
                              std::to_string(sum[i + 1]));
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
