#ifndef WORKING_WITH_MATRIX_H
#define WORKING_WITH_MATRIX_H
#include <fstream>
#include <cstddef>

namespace flusova {
  void getDataFromFile(std::ifstream &in, int* matrix, const size_t& rows, const size_t& cols, const char* task);
  int noSameElInStaticMatrixRows(const int* matrix, const size_t& rows, const size_t& cols);
  int noSameNearElInDynamicMatrixRows(const int* matrix, const size_t& rows, const size_t& cols);
}

#endif
