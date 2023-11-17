#ifndef LOGIC_H
#define LOGIC_H
#include <fstream>
#include <cstddef>

namespace chupina {
  void fillMatrix(std::ifstream & fin, int * matrix, const size_t & nRow, const size_t & nColumn);
  int countRowsWithRepetitiveEls(const int * matrix, const size_t & nRow, const size_t & nColumn);
  int getRowNumWithLongestSubstring(const int * matrix, const size_t & nRow, const size_t & nColumn);
}

#endif
