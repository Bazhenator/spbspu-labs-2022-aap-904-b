#include <iostream>
#include <cstring>
#include "matrix.h"

int main(int argc, const char *argv[]) {
  if (argc != 4) {
    std::cerr << "4 arguments was expected but " << argc << " was given";
    return 1;
  }
  int result;
  if (!strcmp(argv[1], "1")) {
    const size_t size = 500;
    int matrix[size * size] = {0};
    size_t row, col;
    try {
      pelipeychenko::fillFromFileStaticMatrix(&matrix[0], row, col, argv);
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << "\n";
      return 1;
    }
    result = pelipeychenko::countRowsWithNull(&matrix[0], row, col);

  } else if (!strcmp(argv[1], "2")) {
    pelipeychenko::dynamicMatrix matrix;
    try {
      matrix.fillMatrixFromFile(argv);
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << "\n";
      return 1;
    } catch (std::bad_alloc &e) {
      std::cerr << "bad_alloc error" << "\n";
      return 1;
    }
    result = matrix.countLocalMins();
  } else {
    std::cerr << "error: wrong number" << "\n";
    return 1;
  }
  try {
    pelipeychenko::writeOutput(result, argv);
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
