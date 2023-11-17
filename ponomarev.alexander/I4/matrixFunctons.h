#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

#include <fstream>
#include <cstddef>

namespace ponomarev {
  int countOnlyPositiveRows(const int *matrix, const std::size_t nMatrixRows = 3, const std::size_t nMatrixColumns = 3);
  int countNumbersInInteger(int number);
  int inputElement(std::fstream &file);
  void fillMatrixFromFile(int *matrix, std::fstream &file, const std::size_t rows = 3, const std::size_t columns = 3);
  void fillMatrixAsSpiral(int *matrix, const int dimension);
  void printMatrix(int *matrix, const std::size_t dimension, std::fstream &file);
}

#endif
