#include "common.hpp"

#define PROGRAM_END_NORMAL -99
#define PROGRAM_END_OUTPUT -101
#define PROGRAM_END_UNEXPECTED -1

using namespace std;
vector<int> program = {3,  26, 1001, 26, -4, 26, 3, 27, 1002, 27,
                       2,  27, 1,    27, 26, 27, 4, 27, 1001, 28,
                       -1, 28, 1005, 28, 6,  99, 0, 0,  5};

const vector<int> original_program = program;
vector<int> input = {0, 0};
int output = 0;
vector<int> phase_seq = {9, 8, 7, 6, 5};
int input_seq = 0;

int process(int position, int first_run) {
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
      // cout << "Input: ";
      // cin >> input;
      if (first_run) {
        program.at(C) = input[input_seq];
        cout << "if" << input[input_seq] << endl;

        input_seq++;

      } else {
        program.at(C) = output;
        cout << "else" << output << endl;
      }
      return position + 2;
    case 4:
      C = (command[command_size - 3] == '0')
              ? program.at(program.at(position + 1))
              : program.at(position + 1);
      input_seq = 0;
      input[1] = C;
      output = C;
      // return position + 2;
      return PROGRAM_END_OUTPUT;
    // if (C == 0) {
    //   // cout << "Output: " << C << '\n';
    //   output = C;
    //   return position + 2;
    // } else {
    //   // cout << "Output: " << C << '\n';
    //   output = C;
    //   return PROGRAM_END_OUTPUT;
    // }
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
vector<int> position_list = {0, 0, 0, 0, 0};

int main() {
  do {
    position_list = {0, 0, 0, 0, 0};
    input[1] = 0;
    output = 0;
    vector<int> first_run = {1, 1, 1, 1, 1};
    bool outerloop = true;

    while (outerloop) {
      for (int i = 0; i < 5; i++) {
        input[0] = phase_seq[i];
        int error = 0;
        while (true) {
          error = process(position_list[i], first_run[i]);
          if (error > 0) {
            position_list[i] = error;
          } else if (error == PROGRAM_END_OUTPUT) {
            position_list[i] += 2;
            first_run[i] = 0;
            cout << "Program ended with output command\n";
            break;
          } else if (error == PROGRAM_END_NORMAL) {
            cout << "Program ended normally\n";
            if (i == 4) {
              outerloop = false;
            }
            break;
          } else if (error == PROGRAM_END_UNEXPECTED) {
            cout << "Unexpected command\n";
            break;
          } else {
            cout << "This should not have happened\n";
            break;
          }
        }
      }
    }
    if (output > max_thrust) {
      max_thrust = output;
    }
    cout << max_thrust << endl;
    return 0;

    break;
  } while (std::next_permutation(phase_seq.begin(), phase_seq.end()));
  cout << max_thrust << endl;
  // for (auto const& c : program) std::cout << c << ' ';

  return 0;
}