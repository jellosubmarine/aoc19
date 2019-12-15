#include "common.hpp"

using namespace std;

int is_good(string nr) {
  int prev = 0;

  int has_double_digits = 0;
  int double_digits = -1;
  int first_part_double_digits = 0;
  for (auto s : nr) {
    int current = (s - '0');
    if ((current - prev) < 0) {
      return 0;
    }
    if ((current - prev) == 0) {
      if (double_digits == current) {
        has_double_digits = 0;
      } else {
        has_double_digits = 1;
        double_digits = current;
      }
    } else {
      double_digits = -1;
      if (has_double_digits) {
        first_part_double_digits = 1;
      }
    }
    prev = current;
  }

  if (!has_double_digits and !first_part_double_digits) {
    return 0;
  }
  cout << nr << endl;
  return 1;
}

int main() {
  int l_range = 254032;
  int u_range = 789860;
  int good_counter = 0;
  for (int i = l_range; i <= u_range; i++) {
    good_counter += is_good(to_string(i));
  }
  cout << good_counter;
  return 0;
}