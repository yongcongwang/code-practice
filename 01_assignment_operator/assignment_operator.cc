// By yongcong.wang @ 20/04/2020

class MyString {
 public:
  MyString(char *data = nullptr) {
    my_string = data;
  }
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

  ~MyString() = default;

 private:
  char *my_string;
};
