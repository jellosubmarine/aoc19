#include "common.hpp"

int main() {
  std::string s = "123";
  s.insert(s.begin(), 5 - s.size(), '0');
  std::cout << s;
  return 0;
}