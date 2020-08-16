#include <iostream>

int LastNumInCircle(const int m, const int n) {
  if (m < 1 || n < 1) {
    return -1;
  }

  int last = 0;
  for (int i = 2; i < n; ++i) {
    last = (last + m) % n;
  }

  return last;
}

int main() {
  std::cout << "m: 2, n: 3:" << LastNumInCircle(2, 3) << std::endl;
}
