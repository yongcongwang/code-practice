// By yongcong.wang @ 25/04/2020
#include <iostream>

void ReplaceSpace(char *const arr, const int length) {
  if (arr == nullptr || length <= 0) {
    return;
  }

  int space_cnt = 0;
  int char_cnt = 0;
  int i = 0;
  while (arr[i] != '\0') {
    if (arr[i++] == ' ') {
      space_cnt++;
    }
    char_cnt++;
  }
  char_cnt++;

  if (char_cnt + space_cnt * 2 > length) {
    return;
  }

  int end_of_origin = char_cnt - 1;
  int start_of_new = space_cnt * 2 + char_cnt - 1;

  while (end_of_origin >= 0) {
    if (arr[end_of_origin] == ' ') {
      arr[start_of_new--] = '0';
      arr[start_of_new--] = '2';
      arr[start_of_new--] = '%';
      end_of_origin--;
    } else {
      arr[start_of_new--] = arr[end_of_origin--];
    }
  }
}

int main() {
  char arr1[20] = "hello, world!";
  ReplaceSpace(arr1, 20);
  std::cout << arr1 << std::endl;

  char arr2[20] = "";
  ReplaceSpace(arr2, 20);
  std::cout << arr2 << std::endl;

  char arr3[20] = " ";
  ReplaceSpace(arr3, 20);
  std::cout << arr3 << std::endl;

  char arr4[20] = "test   test  test";
  ReplaceSpace(arr4, 20);
  std::cout << arr4 << std::endl;
}
