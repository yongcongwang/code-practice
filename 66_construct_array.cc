#include <iostream>
#include <vector>

bool ConstructArray(const std::vector<int>& A, std::vector<int>* const B) {
  if (A.size() != B->size() || B->size() < 2) {
    return false;
  }

  (*B)[0] = 1;
  for (std::size_t i = 1; i < B->size(); ++i) {
    (*B)[i] = (*B)[i - 1] * A[i - 1];
  }

  int tmp = 1;
  for (int i = B->size() - 2; i >= 0; --i) {
    tmp *= A[i + 1];
    (*B)[i] *= tmp;
  }

  return true;
}

int main() {
  std::vector<int> A{1, 2, 3, 4, 5, 6};
  std::vector<int> B(A);

  std::cout << "constructB:" << static_cast<int>(ConstructArray(A, &B))
            << std::endl;
}
