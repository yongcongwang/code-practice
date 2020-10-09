// By yongcong.wang @ 15/05/2020
#include <iostream>

bool ScanUnsignedIntegar(std::string& str) {
  if (str.empty()) {
    return false;
  }

  bool is_num_found(false);
  while (!str.empty() && str.front() >= '0' && str.front() <= '9') {
    str.erase(str.begin());
    is_num_found = true;
  }

  return is_num_found;
}

bool ScanIntegar(std::string& str) {
  if (str.empty()) {
    return false;
  }

  if (str.front() == '+' || str.front() == '-') {
    str.erase(str.begin());
  }

  return ScanUnsignedIntegar(str);
}

bool IsStrNumber(std::string& str) {
  if (str.empty()) {
    return false;
  }

  bool is_num = ScanIntegar(str);

  if (!str.empty() && str.front() == '.') {
    str.erase(str.begin());
    is_num = ScanUnsignedIntegar(str) || is_num;
  }

  if (!str.empty() && (str.front() == 'e' || str.front() == 'E')) {
    str.erase(str.begin());
    is_num = ScanIntegar(str) && is_num;
  }

  return is_num && str.empty();
}

int main() {
  std::string str = "+100";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "5e2";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "-123";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "3.1416";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "-1E-16";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "12e";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "1a3.14";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "1.3.14";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "+-5";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;

  str = "12e+14.5";
  std::cout << str << ": " << IsStrNumber(str) << std::endl;
}
