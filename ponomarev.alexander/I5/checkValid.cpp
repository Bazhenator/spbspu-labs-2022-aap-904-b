#include "checkValid.h"
#include <cctype>
#include <cstring>
#include <iostream>

bool ponomarev::isMathExpr(char *string)
{
  ponomarev::Parser mathExpr(string);
  return mathExpr.isExp();
}
bool ponomarev::Parser::isExp()
{
  if (isTerm()) {
    if (match('+') || match('-')) {
      return isExp();
    }
    return *pts == '\0' || nBrackets--;
  }
  return false;
}
bool ponomarev::Parser::isTerm()
{
  if (isMult()) {
    if (match('*') || match('/')) {
      return isTerm();
    }
    return true;
  }
  return false;
}
bool ponomarev::Parser::isMult()
{
  if (isUnsignedInt() || isAlpha()) {
    return true;
  } else if (match('(')) {
    nBrackets++;
    return isExp() && match(')');
  }
  return false;
}
bool ponomarev::Parser::isUnsignedInt()
{
  bool result = isdigit(*pts);
  if (result) {
    match(*pts);
    if (isdigit(*pts)) {
      result = isUnsignedInt();
    }
  }
  return result;
}
bool ponomarev::Parser::isAlpha()
{
  return (std::strchr("abcdefxyz", *pts)) && match(*pts);
}
bool ponomarev::Parser::match(char etalon)
{
  bool result = (etalon == *pts);
  return (result ? etalon == *(pts++) : result);
}
