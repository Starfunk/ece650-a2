#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "headers/amatrix.h"
#include "headers/node.h"

AMatrix matrix;

int main() {
  while (!std::cin.eof()) {
    // Read a line of input until EOL and store in a string.
    std::string line;

    // Get the input line. The last character is the newline '\n'.
    std::getline(std::cin, line);
    // Create an input stream based on the line.
    // We will use the input stream to parse the line.
    std::istringstream input(line);

    /* We expect each line to contain a list of numbers.
    This vector will store the numbers.
    They are assumed to be unsigned (i.e., positive) */
    std::vector<unsigned> nums;

    // Store the input command.
    char command;
    input >> command;

    // Create adjacency matrix if input is V.
    if (command == 'V') {
      unsigned number_of_vertices;
      input >> number_of_vertices;
      if (input.fail()) {
        std::cerr << "Error: parsing V command\n";
      }
      matrix.setMatrix(number_of_vertices);
    }

    // Assign edges to matrix if E is input.
    else if (command == 'E') {
      unsigned num;
      char separator;
      input >> separator;
      input >> separator;
      while (!input.eof()) {
        if (input.fail()) {
          std::cerr << "Error: parsing E command\n";
        }
        input >> num;
        nums.push_back(num);
        input >> separator;
        if (input.fail()) {
          std::cerr << "Error: parsing E command\n";
        }
        input >> num;

        nums.push_back(num);
        input >> separator;
        input >> separator;

        input >> separator;
      }
      matrix.assignEdge(nums);
      matrix.printMatrix();
    }

    // Output shortest path between vertices s and t.
    else if (command == 's') {
      unsigned s;
      unsigned t;
      input >> s;
      if (input.fail()) {
        std::cerr << "\nError: parsing s command\n";
      }
      input >> t;
      if (input.fail()) {
        std::cerr << "\nError: parsing s command\n";
      }
      if (matrix.find_shorted_path(s, t)) {
        matrix.printShortestPath();
      }
      matrix.resetAMatrix();
    }
  }
}
