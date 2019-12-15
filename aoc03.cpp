#include "common.hpp"

using namespace std;

// for string delimiter
vector<string> split(string s, string delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

int main() {
  string str =
      "R75,D30,R83,U83,L12,D49,R71,U7,L72\nU62,R66,U55,R34,D71,R55,D58,R83";
  string delimiter = "\n";
  vector<vector<string>> wires_array;
  vector<string> wires = split(str, delimiter);
  for (auto j : wires) {
    wires_array.push_back(split(j, ","));
  }

  // for (auto k : wires_array.at(1)) cout << k << endl;

  return 0;
}