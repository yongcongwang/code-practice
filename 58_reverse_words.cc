#include <iostream>
#include <string>

void ReverseString(std::string::iterator start, std::string::iterator end) {
  while (start < end) {
    auto tmp = *start;
    *start =  *end;
    *end = tmp;
    start++;
    end--;
  }
}


std::string ReverseSentence(std::string sentence) {
  if (sentence.empty()) {
    return "";
  }

  ReverseString(sentence.begin(), sentence.end() - 1);
  std::cout << "reverse: " << sentence << std::endl;

  auto start = sentence.begin();
  auto end = sentence.begin();
  while (end != sentence.end()) {
    if (*end == ' ') {
      ReverseString(start, end - 1);
      start = end + 1;
      end = start;
    } else {
      end++;
    }
  }

  return sentence;
}

std::string LeftTurnString(std::string str, const int num) {
  if (str.empty() || num >= str.size()) {
    return "";
  }
  if (num < 1) {
    return str;
  }

  ReverseString(str.begin(), str.end() - 1);
  ReverseString(str.end() - num, str.end() - 1);
  ReverseString(str.begin(), str.end() - num - 1);

  return str;
}

int main() {
  std::string tmp = "I am a student";
  //ReverseSentence(tmp);
  std::cout << "origin: " << tmp << "; reverse: " << ReverseSentence(tmp) << std::endl;
  std::string str = "asdfghjkl";
  std::cout << "origin: " << str << "; reverse: " << LeftTurnString(str, 2) << std::endl;
}
