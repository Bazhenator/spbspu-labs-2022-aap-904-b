#ifndef IS_REAL_VALUE_H
#define IS_REAL_VALUE_H
#include <cstddef>
#include <iostream>

namespace flusova {
  bool isSign(char* str, size_t& pos);
  bool isDigit(char* str, size_t& pos);
  bool isUnsignedInteger(char* str, size_t& pos, bool flag);
  bool isExhibitor(char* str, size_t& pos);
  bool isPoint(char* str, size_t& pos);
  bool isExp(char* str, size_t& pos);
  bool isMantissa(char* str, size_t& pos);
  bool isRealValue(char* str, size_t& pos);
}

#endif
