// By yongcong.wang @ 03/05/2020
#include <iostream>
#include <vector>
#include <cmath>

int GetMaxCuttingDP(const int length) {
  if (length < 2) {
    return 0;
  }

  if (length == 2) {
    return 1;
  }

  if (length == 3) {
    return 2;
  }

  std::vector<int> product;
  product.push_back(0);
  product.push_back(1);
  product.push_back(2);
  product.push_back(3);

  for (int i = 4; i <= length; ++i) {
    int max(0);
    for (int j = 1; j <= i / 2; ++j) {
      int curr_product = product[j] * product[i - j];
      max = max > curr_product ? max : curr_product;
    }
    product.push_back(max);
  }

  return product.back();
}

int GetMaxCuttingGreed(const int length) {
  if (length < 2) {
    return 0;
  }

  if (length == 2) {
    return 1;
  }

  if (length == 3) {
    return 2;
  }

  int ThreeCnt = length / 3;
  if (length % 3 == 1) {
    ThreeCnt--;
  }

  const int TwoCnt = (length - ThreeCnt * 3) / 2;
  return std::pow(3, ThreeCnt) * std::pow(2, TwoCnt);
}

int main() {
  std::cout << "max 0: " << GetMaxCuttingDP(0) << std::endl;
  std::cout << "max 1: " << GetMaxCuttingDP(1) << std::endl;
  std::cout << "max 2: " << GetMaxCuttingDP(2) << std::endl;
  std::cout << "max 3: " << GetMaxCuttingDP(3) << std::endl;
  std::cout << "max 4: " << GetMaxCuttingDP(4) << std::endl;
  std::cout << "max 5: " << GetMaxCuttingDP(5) << std::endl;
  std::cout << "max 8: " << GetMaxCuttingDP(8) << std::endl;
  std::cout << "max 0: " << GetMaxCuttingGreed(0) << std::endl;
  std::cout << "max 1: " << GetMaxCuttingGreed(1) << std::endl;
  std::cout << "max 2: " << GetMaxCuttingGreed(2) << std::endl;
  std::cout << "max 3: " << GetMaxCuttingGreed(3) << std::endl;
  std::cout << "max 4: " << GetMaxCuttingGreed(4) << std::endl;
  std::cout << "max 5: " << GetMaxCuttingGreed(5) << std::endl;
  std::cout << "max 8: " << GetMaxCuttingGreed(8) << std::endl;
}
