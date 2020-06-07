#include <iostream>

int GetNumDigit(const int value, const int cnt) {
  if (cnt < 0) {
    return -1;
  }
  for (int i = 0)

  while ()
}


int GetDigitsMax(const int digit) {
  if (digit < 1) {
    return 0;
  }

  return 9 * std::pow(10, digit - 1);
}

int DigitInSerail(const int num) {
  if (num < 0) {
    return -1;
  }

  int digit = 1;
  int sum = 0;
  for (; sum < num; ++digit) {
    sum += GetDigitsMax(digit);
  }

  int value = i * std::pow(10, digit -1) + 
              (num - (sum - GetDigitsMax(digit))) / digit;
  int cnt = (num - (sum - GetDigitsMax(digit))) % digit;

  if (cnt == 0) {
    return value % 10;
  } 

  value ++;
  while ()
  return value / std::pow(10, cnt)
  return GetNumDigit(value + 1, cnt);
}
