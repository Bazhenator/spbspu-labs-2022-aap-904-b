#ifndef STRUCT_ARRAY_H
#define STRUCT_ARRAY_H
#include <cstddef>
namespace siobko
{
  struct Array
  {
    int* data;
    size_t size;
    size_t capacity;
    Array(size_t cap);
    Array(const char* FileName);
    ~Array();
    int& operator[](size_t index);
    void GenerateRandomArray();
    void rshift(size_t ShiftCount);
  };
}
#endif
