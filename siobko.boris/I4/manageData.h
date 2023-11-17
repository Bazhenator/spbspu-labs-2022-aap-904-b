#ifndef MANAGEDATA_H
#define MANAGEDATA_H
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>

namespace siobko
{
  void printValueToFile(std::uint16_t value, const char *outputfile);
  void printMatrixToFile(int *matrix, size_t dimension, const char *outputfile);
  size_t inputMatrixDimension(std::ifstream &InputDimension);
  std::pair<size_t, size_t> inputArrayDimension(std::ifstream &InputDimension);
  void inputArrayElems(int *array, size_t nlines, size_t ncols, std::ifstream &InputElem, const char *taskNumber);
}
#endif
