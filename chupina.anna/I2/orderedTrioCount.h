#ifndef ORDERED_TRIO_COUNT_H
#define ORDERED_TRIO_COUNT_H
#include <fstream>

namespace chupina {
  struct DynamicArray {
    DynamicArray();
    DynamicArray(std::ifstream & fin);
    ~DynamicArray();
    std::size_t capacity;
    int * data;
    void fillArrayWithRandomVals();
  };
  int countOrderedTrio(const std::size_t & arraySize, int * arrayValues);
  void openFile(std::ifstream & fin, const char * path);
}

#endif
