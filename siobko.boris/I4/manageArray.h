#ifndef MANAGEARRAY_H
#define MANAGEARRAY_H
#include <iostream>

namespace siobko
{
  int *createMatrix(size_t dimension);
  int *editMatrix(int *matrix, size_t dimension);
  std::uint16_t countLinesWithDiffElems(int *matrix, size_t nlines, size_t ncols);
}
#endif
