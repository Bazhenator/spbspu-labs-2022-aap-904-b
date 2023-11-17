#ifndef WORKING_WITH_ARRAYS_H
#define WORKING_WITH_ARRAYS_H
#include <cstddef>

namespace flusova {
  struct ArrayStruct {
    ArrayStruct();
    ArrayStruct(const char *path);
    ~ArrayStruct();
    void getDataFromFile(const char *path);
    void getDataForRandomArray();
    std::size_t capacity;
    int *array;
  };
  void printQuantityOfNegElInArray(const std::size_t &capacity_, int *array);
}

#endif
