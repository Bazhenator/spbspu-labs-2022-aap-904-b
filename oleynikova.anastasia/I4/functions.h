#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include <cstdlib>

namespace oleynikova {
  int countRows(int const *matrix, const std::size_t rows, const std::size_t cols);
  int countPoints(int *matrix, const std::size_t rows, const std::size_t cols);
  void inputMatrix(std::fstream &file, int *matrix, const std::size_t &rows, const std::size_t &cols);
}

#endif
