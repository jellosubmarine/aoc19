#include "common.hpp"

#define PROGRAM_END_NORMAL -99
#define PROGRAM_END_OUTPUT -101
#define PROGRAM_END_UNEXPECTED -1

using namespace std;
vector<int> program = {
    3,     225,  1,     225,   6,     6,     1100, 1,     238,  225,   104,
    0,     1102, 79,    14,    225,   1101,  17,   42,    225,  2,     74,
    69,    224,  1001,  224,   -5733, 224,   4,    224,   1002, 223,   8,
    223,   101,  4,     224,   224,   1,     223,  224,   223,  1002,  191,
    83,    224,  1001,  224,   -2407, 224,   4,    224,   102,  8,     223,
    223,   101,  2,     224,   224,   1,     223,  224,   223,  1101,  18,
    64,    225,  1102,  63,    22,    225,   1101, 31,    91,   225,   1001,
    65,    26,   224,   101,   -44,   224,   224,  4,     224,  102,   8,
    223,   223,  101,   3,     224,   224,   1,    224,   223,  223,   101,
    78,    13,   224,   101,   -157,  224,   224,  4,     224,  1002,  223,
    8,     223,  1001,  224,   3,     224,   1,    224,   223,  223,   102,
    87,    187,  224,   101,   -4698, 224,   224,  4,     224,  102,   8,
    223,   223,  1001,  224,   4,     224,   1,    223,   224,  223,   1102,
    79,    85,   224,   101,   -6715, 224,   224,  4,     224,  1002,  223,
    8,     223,  1001,  224,   2,     224,   1,    224,   223,  223,   1101,
    43,    46,   224,   101,   -89,   224,   224,  4,     224,  1002,  223,
    8,     223,  101,   1,     224,   224,   1,    223,   224,  223,   1101,
    54,    12,   225,   1102,  29,    54,    225,  1,     17,   217,   224,
    101,   -37,  224,   224,   4,     224,   102,  8,     223,  223,   1001,
    224,   3,    224,   1,     223,   224,   223,  1102,  20,   53,    225,
    4,     223,  99,    0,     0,     0,     677,  0,     0,    0,     0,
    0,     0,    0,     0,     0,     0,     0,    1105,  0,    99999, 1105,
    227,   247,  1105,  1,     99999, 1005,  227,  99999, 1005, 0,     256,
    1105,  1,    99999, 1106,  227,   99999, 1106, 0,     265,  1105,  1,
    99999, 1006, 0,     99999, 1006,  227,   274,  1105,  1,    99999, 1105,
    1,     280,  1105,  1,     99999, 1,     225,  225,   225,  1101,  294,
    0,     0,    105,   1,     0,     1105,  1,    99999, 1106, 0,     300,
    1105,  1,    99999, 1,     225,   225,   225,  1101,  314,  0,     0,
    106,   0,    0,     1105,  1,     99999, 107,  226,   226,  224,   1002,
    223,   2,    223,   1006,  224,   329,   101,  1,     223,  223,   1108,
    677,   226,  224,   1002,  223,   2,     223,  1006,  224,  344,   101,
    1,     223,  223,   7,     677,   226,   224,  102,   2,    223,   223,
    1006,  224,  359,   101,   1,     223,   223,  108,   226,  226,   224,
    1002,  223,  2,     223,   1005,  224,   374,  101,   1,    223,   223,
    8,     226,  677,   224,   1002,  223,   2,    223,   1006, 224,   389,
    101,   1,    223,   223,   1108,  226,   226,  224,   102,  2,     223,
    223,   1006, 224,   404,   101,   1,     223,  223,   1007, 677,   677,
    224,   1002, 223,   2,     223,   1006,  224,  419,   101,  1,     223,
    223,   8,    677,   677,   224,   1002,  223,  2,     223,  1005,  224,
    434,   1001, 223,   1,     223,   1008,  226,  226,   224,  102,   2,
    223,   223,  1005,  224,   449,   1001,  223,  1,     223,  1008,  226,
    677,   224,  102,   2,     223,   223,   1006, 224,   464,  101,   1,
    223,   223,  1107,  677,   677,   224,   102,  2,     223,  223,   1006,
    224,   479,  101,   1,     223,   223,   107,  677,   677,  224,   1002,
    223,   2,    223,   1005,  224,   494,   1001, 223,   1,    223,   1107,
    226,   677,  224,   1002,  223,   2,     223,  1005,  224,  509,   101,
    1,     223,  223,   1108,  226,   677,   224,  102,   2,    223,   223,
    1006,  224,  524,   101,   1,     223,   223,  7,     226,  226,   224,
    1002,  223,  2,     223,   1005,  224,   539,  101,   1,    223,   223,
    108,   677,  677,   224,   1002,  223,   2,    223,   1005, 224,   554,
    101,   1,    223,   223,   8,     677,   226,  224,   1002, 223,   2,
    223,   1005, 224,   569,   1001,  223,   1,    223,   1008, 677,   677,
    224,   102,  2,     223,   223,   1006,  224,  584,   101,  1,     223,
    223,   107,  226,   677,   224,   102,   2,    223,   223,  1005,  224,
    599,   1001, 223,   1,     223,   7,     226,  677,   224,  102,   2,
    223,   223,  1005,  224,   614,   101,   1,    223,   223,  1007,  226,
    226,   224,  1002,  223,   2,     223,   1005, 224,   629,  101,   1,
    223,   223,  1107,  677,   226,   224,   1002, 223,   2,    223,   1006,
    224,   644,  101,   1,     223,   223,   108,  226,   677,  224,   102,
    2,     223,  223,   1006,  224,   659,   101,  1,     223,  223,   1007,
    677,   226,  224,   102,   2,     223,   223,  1006,  224,  674,   101,
    1,     223,  223,   4,     223,   99,    226};

const vector<int> original_program = program;

int process(int position) {
  const int command_size = 5;
  int input = 5;
  int opcode = -1;
  int A = 0;
  int B = 0;
  int C = 0;
  std::string command = to_string(program.at(position));
  command.insert(command.begin(), command_size - command.size(), '0');
  opcode = stoi(command.substr(command_size - 2, command_size - 1));

  switch (opcode) {
    case 1:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      A = (command[command_size - 5] == '0') ? program.at(position + 3)
                                             : (position + 3);
      program.at(A) = B + C;
      return position + 4;
    case 2:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      A = (command[command_size - 5] == '0') ? program.at(position + 3)
                                             : (position + 3);
      program.at(A) = B * C;
      return position + 4;
    case 3:
      C = (command[command_size - 3] == '0') ? program.at(position + 1)
                                             : (position + 1);

      program.at(C) = input;
      return position + 2;
    case 4:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);

      if (C == 0) {
        cout << "Output: " << C << '\n';

        return position + 2;
      } else {
        cout << "Output: " << C << '\n';
        return PROGRAM_END_OUTPUT;
      }
    case 5:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      if (C != 0) {
        return B;
      } else {
        return position + 3;
      }
    case 6:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      if (C == 0) {
        return B;
      } else {
        return position + 3;
      }
    case 7:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      A = (command[command_size - 5] == '0') ? program.at(position + 3)
                                             : (position + 3);
      program.at(A) = (C < B) ? 1 : 0;
      return position + 4;
    case 8:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      B = (command[command_size - 4] == '0')
              ? program.at(program.at(position + 2))
              : program.at(position + 2);
      A = (command[command_size - 5] == '0') ? program.at(position + 3)
                                             : (position + 3);
      program.at(A) = (C == B) ? 1 : 0;
      return position + 4;
    case 99:
      return PROGRAM_END_NORMAL;
    default:
      return PROGRAM_END_UNEXPECTED;
  }
  return 1337;
}

int main() {
  int position = 0;
  int error = 0;
  while (true) {
    error = process(position);
    if (error > 0) {
      position = error;
    } else if (error == PROGRAM_END_OUTPUT) {
      cout << "Program ended with output command\n";
      break;
    } else if (error == PROGRAM_END_NORMAL) {
      cout << "Program ended normally\n";
      break;
    } else if (error == PROGRAM_END_UNEXPECTED) {
      cout << "Unexpected command\n";
      break;
    } else {
      cout << "This should not have happened\n";
      break;
    }
  }

  // for (auto const& c : program) std::cout << c << ' ';

  return 0;
}