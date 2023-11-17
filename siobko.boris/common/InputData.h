#ifndef INPUTDATA_H
#define INPUTDATA_H
#include <iostream>
#include <cstddef>
namespace siobko
{
  std::pair<char *, size_t> inputString(std::istream &in, char *str, size_t size_str);
  char *makeBiggerString(char *str, size_t &size_str);
}
#endif
