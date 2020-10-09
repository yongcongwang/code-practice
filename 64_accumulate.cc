#include <iostream>
#include <vector>


// solution 1: constructor
class Sum1 {
 public:
  Sum1() {
  }

  Sum1(const Sum1& rhs) {
    ++N;
    sum += N;
  }

  //Sum1& operator=(const Sum1& rhs) {
  //  ++N;
  //  sum += N;
  //  return *this;
  //}

 public:
  static int GetSum() {
    return sum;
  }

 private:
  static int N;
  static int sum;
};

int Sum1::N = 0;
int Sum1::sum = 0;

int GetSum1(const int n) {
  std::vector<Sum1> tmp(n, Sum1());

  return Sum1::GetSum();
}

// solution 2: virtual function
class SumBase2 {
 public:
  virtual int GetSum(int n) = 0;
};

std::vector<SumBase2*> funs;

class SumNormal2 : public SumBase2 {
 public:
  int GetSum(int n) {
    return n + funs[static_cast<std::size_t>(n == 0)]->GetSum(n - 1);
  }
};

class SumEnd2 : public SumBase2 {
 public:
  int GetSum(int n) {
    return 0;
  }
};

int GetSum2(const int n) {
  funs.push_back(new SumNormal2());
  funs.push_back(new SumEnd2());
  return funs.front()->GetSum(100);
}

// solution 3: function pointer
typedef int (*GetSumBase3)(int);
std::vector<GetSumBase3> funcs;
int GetSumNormal3(int n) {
  return n + funcs[static_cast<std::size_t>(n == 0)](n - 1);
}
int GetSumEnd3(int n) {
  return 0;
}

int GetSum3(int n) {
  funcs = {GetSumNormal3, GetSumEnd3};
  return funcs.front()(n);
}

// solution4: template
template <int N>
int GetSumBase4() {
  return N + GetSumBase4<N - 1>();
}

template <>
int GetSumBase4<1>() {
  return 1;
}

int GetSum4(int n) {
  return GetSumBase4<100>();
}

int main() {
  std::cout << "sum 100, solution1: " << GetSum1(100) << std::endl;
  std::cout << "sum 100, solution2: " << GetSum2(100) << std::endl;
  std::cout << "sum 100, solution3: " << GetSum3(100) << std::endl;
  std::cout << "sum 100, solution4: " << GetSum4(100) << std::endl;
}
