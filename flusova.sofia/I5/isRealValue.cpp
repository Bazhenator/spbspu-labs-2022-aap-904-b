#include "isRealValue.h"
#include <iostream>
#include <cstddef>
#include <cstdio>
#include <set>

bool flusova::isSign(char* str, size_t& pos)
{
  if (str[pos] == '+' || str[pos] == '-') {
    pos++;
    return true;
  }
  return false;
}
bool flusova::isDigit(char* str, size_t& pos)
{
  if (std::isdigit(str[pos])) {
    pos++;
    return true;
  }
  return false;
}
bool flusova::isUnsignedInteger(char* str, size_t& pos, bool flag = false)
{
  if (flusova::isDigit(str, pos)) {
    flag = true;
    flusova::isUnsignedInteger(str, pos, flag);
  }
  return flag;
}
bool flusova::isPoint(char* str, size_t& pos)
{
  if (str[pos] == '.') {
    pos++;
    return true;
  }
  return false;
}
bool flusova::isExp(char* str, size_t& pos)
{
  if (str[pos] == 'E') {
    pos++;
    return true;
  }
  return false;
}
bool flusova::isExhibitor(char* str, size_t& pos) {
  if (flusova::isExp(str, pos)) {
    if (flusova::isSign(str, pos)) {
      return flusova::isUnsignedInteger(str, pos);
    }
    else {
      return flusova::isUnsignedInteger(str, pos);
    }
  }
  return false;
}
bool flusova::isMantissa(char* str, size_t& pos)
{
  if (flusova::isUnsignedInteger(str, pos)) {
    if (str[pos] != '\0') {
      return flusova::isPoint(str, pos) && flusova::isUnsignedInteger(str, pos);
    }
    else {
      return true;
    }
  }
  return flusova::isPoint(str, pos) && flusova::isUnsignedInteger(str, pos);
}
bool flusova::isRealValue(char* str, size_t& pos)
{
  return flusova::isSign(str, pos) && flusova::isMantissa(str, pos) && flusova::isExhibitor(str, pos);
}
