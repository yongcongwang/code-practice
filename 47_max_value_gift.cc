#include <vector>
#include <iostream>
#include <algorithm>

int MaxGiftValue(const std::vector<std::vector<int>>& map) {
  if (map.empty()) {
    return 0;
  }

  const int row_cnt = map.size();
  const int col_cnt = map.front().size();
  std::vector<std::vector<int>> gift_values(
      row_cnt, std::vector<int>(col_cnt, 0));

  for (int i = 0; i < row_cnt; ++i) {
    for (int j = 0; j < col_cnt; ++j) {
      const int left = j - 1 >= 0 ? gift_values[i][j - 1] : 0;
      const int up = i - 1 >= 0 ? gift_values[i - 1][j] : 0;

      gift_values[i][j] = std::max(left, up) + map[i][j];
    }
  }

  return gift_values.back().back();
}

int main() {
  const std::vector<std::vector<int>> test{
    {1, 10, 3, 8},
    {12, 2, 9, 6},
    {5, 7, 4, 11},
    {3, 7, 16, 5}
  };

  std::cout << "max value is " << MaxGiftValue(test) << std::endl;
}
