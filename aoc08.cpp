#include "common.hpp"

using namespace std;

string digitstr =
#include "aoc08.hpp"
    ;

vector<vector<vector<int>>> layered_image;
vector<vector<int>> end_image(6, vector<int>(25, -1));

vector<int> nr_of_zeros;
int nr_digits = 0;
int digitstr_it = 0;
int running = 1;
int layer_it = -1;

void decode(vector<vector<vector<int>>> &image) {
  nr_digits = digitstr.length();

  while (running) {
    if (digitstr_it == nr_digits) {
      break;
    } else if (digitstr_it % (25 * 6) == 0) {
      vector<vector<int>> x;
      x.resize(6, vector<int>(25));
      image.push_back(x);

      layer_it++;
      //   cout << "upping layer" << endl;
      //   cout << "Layers: " << image.size() << endl;

      //   cout << "Rows: " << image.at(0).size() << endl;

      //   cout << "Columns: " << image.at(0).at(0).size() << endl;
    }
    int zeros = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 25; j++) {
        image.at(layer_it).at(i).at(j) = (digitstr[digitstr_it] - '0');
        // if (image.size() == 243) {
        //   cout << "Layer IT :" << layer_it << endl;
        //   cout << "Nr of layers :" << image.size() << endl;
        // }
        if (image.at(layer_it).at(i).at(j) == 0) {
          zeros++;
        }
        digitstr_it++;
      }
    }
    nr_of_zeros.push_back(zeros);
    // cout << "EIJAFHSLF{" << endl;
  }
  //   cout << "dojgfhsdfkjlhgds;flokjgh" << endl;
}

void actually_decode() {
  for (int row = 0; row < 6; row++) {
    for (int column = 0; column < 25; column++) {
      for (int layer = 0; layer < 100; layer++) {
        if (end_image.at(row).at(column) == 0 ||
            end_image.at(row).at(column) == 1) {
          break;
        } else {
          end_image.at(row).at(column) =
              layered_image.at(layer).at(row).at(column);
        }
      }
    }
  }
}

int find_checksum() {
  vector<vector<int>> chosen_one = layered_image.at(
      distance(nr_of_zeros.begin(),
               min_element(nr_of_zeros.begin(), nr_of_zeros.end())));
  // image.at(min_element(nr_of_zeros.begin(), nr_of_zeros.end()));
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 25; j++) {
      if (chosen_one.at(i).at(j) == 1) {
        ones++;
      } else if (chosen_one.at(i).at(j) == 2) {
        twos++;
      }
    }
  }

  return ones * twos;
}

int main() {
  decode(layered_image);
  actually_decode();
  //   cout << find_checksum() << endl;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 25; j++) {
      cout << " " << end_image[i][j] << "";
    }
    cout << "\n";
  }
  return 0;
}