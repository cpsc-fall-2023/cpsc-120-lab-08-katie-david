// Katie Nguyen
// katiequynhtram@csu.fullerton.edu
// @ktnwin
// Partners: @Dav-929

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments{argv, argv + argc};

  // Validate that there is at least one command line argument.
  // If not, print an error message and return a non-zero value.
  if (argc <= 1) {
    std::cerr << "Error: Provide at least one command line argument."
              << "\n";
    return 1;
  }
  // Write a for-each loop to sum (add up) all of the command line
  // arguments.
  // Use a double or float type so that your program preserves fractional
  // values.
  // The loop needs to skip over the command name, which is the first element
  // of the arguments vector.
  // Each argument is a std::string. You will need to convert each string into
  // a number with the std::stod or std::stof function.
  double sum = 0.0;
  int count = 0;

  for (int i = 1; i < argc; ++i) {
    try {
      double num = std::stod(arguments[i]);
      sum += num;
      count++;
    } catch (const std::invalid_argument& e) {
      std::cerr << "Error: Argument '" << arguments[i]
                << "' is not a valid number."
                << "\n";
      return 1;
    }
  }
  // After the loop has finished summing the arguments, calculate the
  // average of the values. Recall that the average is the total value divided
  // by the number of values.
  if (count == 0) {
    std::cerr << "Error: No valid numbers found in the arguments."
              << "\n";
    return 1;
  }

  // Use cout to print out a message of the form
  // average = *AVERAGE*
  // on its own line.
  double average = sum / count;

  std::cout << "average = " << average << "\n";

  return 0;
}
