#include <iostream>
#include <vector>
#include <cmath>

void PrintProbability(const int n) {
  if (n < 1) {
    return;
  }

  const int max_num(6);
  std::vector<std::vector<int>> probabilities(2, std::vector<int>(max_num, 1));

  int flag = 0;

  for (std::size_t dices_cnt = 1; dices_cnt < n; ++dices_cnt) {
    for (std::size_t dices_num = 1; dices_num <= max_num; ++dices_num) {
      probabilities[1 - flag][dices_num - 1] =
          probabilities[flag][max_num - (dices_num - 1)] + 1;
    }
    flag = 1 - flag;
  }

  const double total = pow(static_cast<double>(max_num),
                           static_cast<double>(n));
  for (auto num : probabilities[flag]) {
    std::cout << static_cast<double>(num) / total << std::endl;
  }

  return;
}

int main() {
  std::cout << "num: 0: ";
  PrintProbability(0);
  std::cout << "num: 1: ";
  PrintProbability(1);
  std::cout << "num: 2: ";
  PrintProbability(2);
  std::cout << "num: 3: ";
  PrintProbability(3);
}
