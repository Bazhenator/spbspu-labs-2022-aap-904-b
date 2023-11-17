#ifndef COMMON_INPUT_STRING_H
#define COMMON_INPUT_STRING_H

#include <iostream>
#include <cstddef>

namespace oleynikova {
  char *inputString(std::istream &in, std::size_t &capacity);
}
#endif
