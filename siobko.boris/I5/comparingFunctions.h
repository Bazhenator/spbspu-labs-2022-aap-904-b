#ifndef COMPARINGFUNCTIONS_H
#define COMPARINGFUNCTIONS_H
#include <cstddef>
#include <iostream>
namespace siobko
{
  bool isFloat(char *str, size_t stringSize);
  bool isInteger(char *str, size_t stringSize, size_t &i);
}
#endif
