// By yongcong.wang @ 29/04/2020
#include <iostream>

int FibonacciRecursion(const int n) {
  if (n <= 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

int FibonacciLoop(const int n) {
  if (n <= 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  int result = 0;
  int fibo_minus_two = 0;
  int fibo_minus_one = 1;
  for (int i = 2; i <= n; ++i) {
    result = fibo_minus_two + fibo_minus_one;
    fibo_minus_two = fibo_minus_one;
    fibo_minus_one = result;
  }

  return result;
}

int main() {
  std::cout << "Recursion Fibonacci 0: " << FibonacciRecursion(0) 
            << std::endl;
  std::cout << "Recursion Fibonacci 1: " << FibonacciRecursion(1) 
            << std::endl;
  std::cout << "Recursion Fibonacci 10: " << FibonacciRecursion(10) 
            << std::endl;
  std::cout << "Recursion Fibonacci 30: " << FibonacciRecursion(30) 
            << std::endl;

  std::cout << "Loop Fibonacci 0: " << FibonacciLoop(0) 
            << std::endl;
  std::cout << "Loop Fibonacci 1: " << FibonacciLoop(1) 
            << std::endl;
  std::cout << "Loop Fibonacci 10: " << FibonacciLoop(10) 
            << std::endl;
  std::cout << "Loop Fibonacci 30: " << FibonacciLoop(30) 
            << std::endl;

}
