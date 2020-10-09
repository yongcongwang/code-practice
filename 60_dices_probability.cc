#include <iostream>
#include <vector>
#include <cmath>

void PrintProbability(const int n) {
  if (n < 1) {
    return;
  }

  const int max_num(6);
  std::vector<std::vector<int>> probabilities(
      2, std::vector<int>(n * max_num + 1, 0));

  int flag = 0;
  for (std::size_t i = 1; i <= max_num; ++i) {
    probabilities[flag][i] = 1;
    probabilities[1 - flag][i] = 1;
  }

  for (std::size_t dices_cnt = 2; dices_cnt <= n; ++dices_cnt) {
    for (std::size_t i = 1; i < dices_cnt; ++i) {
      probabilities[1 - flag][i] = 0;
    }

    for (std::size_t sum_cnt = dices_cnt; sum_cnt <= max_num * dices_cnt;
         ++sum_cnt) {

      probabilities[1 - flag][sum_cnt] = 0;
      for (std::size_t i = 1; i < sum_cnt && i <= max_num; ++i) {
        probabilities[1 - flag][sum_cnt] += probabilities[flag][sum_cnt - i];
      }
    }

    flag = 1 - flag;
  }

  const double total = pow(static_cast<double>(max_num),
                           static_cast<double>(n));
  for (std::size_t i = n; i <= n * max_num; ++i) {
    std::cout << "sum[" << i << "]: " 
              << static_cast<double>(probabilities[flag][i]) / total
              << std::endl;
  }

  return;
}

int main() {
  std::cout << "num: 0: " << std::endl;
  PrintProbability(0);
  std::cout << "num: 1: " << std::endl;
  PrintProbability(1);
  std::cout << "num: 2: " << std::endl;
  PrintProbability(2);
  std::cout << "num: 3: " << std::endl;
  PrintProbability(3);
}
