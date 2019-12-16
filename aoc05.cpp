#include "common.hpp"

using namespace std;
vector<int> program = {
    1,   12,  2,   3,   1,   1,   2,   3,   1,   3,   4,   3,   1,   5,   0,
    3,   2,   1,   6,   19,  1,   9,   19,  23,  1,   6,   23,  27,  1,   10,
    27,  31,  1,   5,   31,  35,  2,   6,   35,  39,  1,   5,   39,  43,  1,
    5,   43,  47,  2,   47,  6,   51,  1,   51,  5,   55,  1,   13,  55,  59,
    2,   9,   59,  63,  1,   5,   63,  67,  2,   67,  9,   71,  1,   5,   71,
    75,  2,   10,  75,  79,  1,   6,   79,  83,  1,   13,  83,  87,  1,   10,
    87,  91,  1,   91,  5,   95,  2,   95,  10,  99,  2,   9,   99,  103, 1,
    103, 6,   107, 1,   107, 10,  111, 2,   111, 10,  115, 1,   115, 6,   119,
    2,   119, 9,   123, 1,   123, 6,   127, 2,   127, 10,  131, 1,   131, 6,
    135, 2,   6,   135, 139, 1,   139, 5,   143, 1,   9,   143, 147, 1,   13,
    147, 151, 1,   2,   151, 155, 1,   10,  155, 0,   99,  2,   14,  0,   0};

const vector<int> original_program = program;

int process(int position) {
  const int command_size = 5;
  int input = 1;
  int opcode = -1;
  std::string command = to_string(program.at(position));
  command.insert(command.begin(), command_size - command.size(), '0');
  opcode = stoi(command.substr(command_size - 2, command_size - 1));

  switch (opcode) {
    case 1:
      program.at(program.at(position + 3)) =
          program.at(program.at(position + 1)) +
          program.at(program.at(position + 2));
      break;
    case 2:
      program.at(program.at(position + 3)) =
          program.at(program.at(position + 1)) *
          program.at(program.at(position + 2));
      break;
    case 3:
      program.at(program.at(position + 1)) = input;
      break;
    case 4:
      cout << "Output: " << program.at(program.at(position + 1)) << '\n';
      return 4;
    case 99:
      return 99;
    default:
      return -1;
  }
  return 0;
}

int main() {
  int position = 0;
  int error = 0;
  while (true) {
    error = process(position);
    if (error == 0) {
      position += 4;
    } else if (error == 4) {
      cout << "Program ended with 4\n";
      break;
    } else if (error == 99) {
      cout << "Program ended with 99\n";
      break;
    } else {
      cout << "Unexpected command\n";
      break;
    }
  }

  // for (auto const& c : program) std::cout << c << ' ';

  return 0;
}