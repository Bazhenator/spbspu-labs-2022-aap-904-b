#ifndef MANAGE_WITH_ARRAYS_H
#define MANAGE_WITH_ARRAYS_H

#include <cstddef>

namespace ponomarev {
  struct Array
  {
    Array():
      data_(nullptr),
      capacity_(0)
    {}

    Array(std::size_t capacity):
      data_(new int[capacity]),
      capacity_(capacity)
    {}

    Array(const Array &array);

    Array(const char *fileName);

    ~Array();

    void generateRandomArray();
    int findMaxInTheInterval(int beginOfTheInterval, int endOfTheInterval);

    int * data_;
    std::size_t capacity_;
  };
  int findMaxInTheInterval(int *array, int arraySize, int beginOfTheInterval, int endOfTheInterval);
}

#endif
