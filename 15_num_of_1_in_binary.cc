// By yongcong.wang @ 03/05/2020
#include <iostream>

int NumOfOneMethod1(int n) {
  int cnt(0);
  unsigned int flag(1);

  while (flag) {
    cnt += n & flag ? 1 : 0;
    flag = flag << 1;
  }
  return cnt;
}

int NumOfOneMethod2(int n) {
  int cnt(0);

  while (n) {
    cnt++;
    n = (n - 1) & n;
  }

  return cnt;
}

int main() {
  std::cout << "0: "  << NumOfOneMethod1(0) << std::endl;
  std::cout << "1: "  << NumOfOneMethod1(1) << std::endl;
  std::cout << "15: "  << NumOfOneMethod1(15) << std::endl;
  std::cout << "-1: "  << NumOfOneMethod1(-1) << std::endl;
  std::cout << "-------" << std::endl;
  std::cout << "0: "  << NumOfOneMethod2(0) << std::endl;
  std::cout << "1: "  << NumOfOneMethod2(1) << std::endl;
  std::cout << "15: "  << NumOfOneMethod2(15) << std::endl;
  std::cout << "-1: "  << NumOfOneMethod2(-1) << std::endl;
}
