#include "common.hpp"

#define PROGRAM_END_NORMAL -99
#define PROGRAM_END_OUTPUT -101
#define PROGRAM_END_UNEXPECTED -1

using namespace std;

const vector<int> original_program = {109,  1,   204, -1,  1001, 100, 1, 100,
                                      1008, 100, 16,  101, 1006, 101, 0, 99};
vector<int> program = original_program;
int output = 0;

int process(int position) {
  const int command_size = 5;
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

      program.at(C) = 1;

      return position + 2;
    case 4:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      output = C;
      return PROGRAM_END_OUTPUT;

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

// vector<int> max_seq = {};
int max_thrust = 0;
int position = 0;
int error = 0;
int main() {
  position = 0;
  output = 0;

  while (true) {
    error = process(position);
    if (error > 0) {
      position = error;
    } else if (error == PROGRAM_END_OUTPUT) {
      position += 2;
      // cout << "Program ended with output command\n";
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

  cout << output << endl;

  // for (auto const& c : program) std::cout << c << ' ';

  return 0;
}