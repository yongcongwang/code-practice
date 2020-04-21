// By yongcong.wang @ 20/04/2020
#include <iostream>

class MyString {
 public:
  MyString() : my_string(nullptr) {}
  MyString(char *data) : my_string(data) {}

  MyString(const MyString &rhs) = default;

  MyString &operator=(const MyString &rhs) {
    if (this != &rhs) {
      MyString tmp_string(rhs);
      char *tmp = tmp_string.my_string;
      tmp_string.my_string = my_string;
      my_string = tmp;
    }

    return *this;
  }

  void print() {
    if (my_string == nullptr) {
      return;
    }
    std::cout << my_string << std::endl;
  }


  ~MyString() = default;

 private:
  char *my_string;
};

int main() {
  char test1[20] = "str1";
  char test2[20] = "str2";
  char test3[20] = "str3";
  MyString str_a(test1);
  MyString str_b;
  MyString str_c(test3);

  str_a.print();
  str_b.print();
  str_b = str_a;
  str_a.print();
  str_b.print();
  str_a = str_b = str_c;
  str_a.print();
  str_b.print();
  str_b.print();
}
