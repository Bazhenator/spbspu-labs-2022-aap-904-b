#ifndef CHANGE_ARRAY_H
#define CHANGE_ARRAY_H

#include <cstddef>

namespace oleynikova {
  void changeArray(int *arr, const int SIZE);
  void printArray(int *arr, const int SIZE);

  struct Array
  {
    Array();
    Array(std::size_t size);
    Array(const Array &arr);
    Array(const char *name);
    ~Array();

    int *data_;
    std::size_t size_;
  };
}

#endif
