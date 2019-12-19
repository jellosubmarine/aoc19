#include "common.hpp"

using namespace std;

class Data {
 private:
  string _name;
  Data* _parent = nullptr;

 public:
  Data(string name, Data* parent);
  ~Data();
};

Data::Data(string name, Data* parent) {
  _name = name;
  _parent = parent;
}

Data::~Data() {}

int main() {
  ifstream infile("aoc06.txt");
  vector<Data> orbits;
  string a, b;
  char c;
  while ((infile >> a >> c >> b) && (c == ')')) {
    // orbits.push_back(Data(b, a));
    cout << b << " " << a << endl;
  }
  return 0;
}