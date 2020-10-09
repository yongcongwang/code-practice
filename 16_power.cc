// By yongcong.wang @ 05/05/2020

#include <iostream>

double pos_power(const double base, const int exponent) {
  double result = 1;
  for (int i = 0; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

double power(const double base, const int exponent) {
  if (base == 0) {
    return 0;
  }
  if (exponent == 0) {
    return 1;
  }
  if (exponent == 1) {
    return base;
  }

  const int exp = exponent > 0 ? exponent : -exponent;
  double result = pos_power(base, exp >> 1);
  result *= result;
  result *= exp & 0x01 ? base : 1;
  return exponent > 0 ? result : 1.0 / result;
}

int main() {
  std::cout << "2.5^3 " << power(2.5, 3) << std::endl;
  std::cout << "-2.5^3 " << power(-2.5, 3) << std::endl;
  std::cout << "0-^3 " << power(0, 3) << std::endl;
  std::cout << "2.5^-3 " << power(2.5, -3) << std::endl;
  std::cout << "-2.5^3 " << power(-2.5, -3) << std::endl;
  std::cout << "0-^3 " << power(0, -3) << std::endl;
}
