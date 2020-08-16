#include <iostream>

int Add(int a, int b) {
  int sum = 0;
  int carray = 0;

  do {
    sum = a ^ b;
    carray = (a & b) << 1;
    a = sum;
    b = carray;
  } while (b != 0);

  return a;
}

int main() {
  std::cout << "1 + 2 = " << Add(1, 2) << std::endl;
  std::cout << "0 + 0 = " << Add(0, 0) << std::endl;
  std::cout << "-1 + 0 = " << Add(-1, 0) << std::endl;
  std::cout << "5 + 3 = " << Add(5, 3) << std::endl;
}
