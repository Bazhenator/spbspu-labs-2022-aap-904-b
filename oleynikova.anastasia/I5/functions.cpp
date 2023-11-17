#include "functions.h"

bool oleynikova::isExpression(const char *str)
{
  if (oleynikova::isTerm(str)) {
    if (*str != '\0') {
      return (oleynikova::isSign(*str)) && oleynikova::isTerm(++str);
    }
    return true;
  }
  return false;
}

bool oleynikova::isTerm(const char *&str)
{
  if (oleynikova::isMultiplier(str)) {
    if (*str != '\0') {
      return (oleynikova::isSign(*str) && oleynikova::isTerm(++str));
    }
    return true;
  }
  return false;
}

bool oleynikova::isDigit(const char *&str)
{
  if (*str >= '0' && *str <= '9') {
    str++;
    return true;
  }
  return false;
}

bool oleynikova::isSign(const char &str)
{
  if ((str == '+') || (str == '-') || (str == '*')) {
    return true;
  }
  return false;
}

bool oleynikova::isLetter(const char *&str)
{
  if (*str >= 'a' && *str <= 'e') {
    ++str;
    return true;
  }
  return false;
}

bool oleynikova::isInteger(const char *&str, bool result = 0)
{
  if (oleynikova::isDigit(str)) {
    result = true;
    oleynikova::isInteger(str, result);
  }
  return result;
}

bool oleynikova::isMultiplier(const char *&str)
{
  if (oleynikova::isInteger(str) || oleynikova::isLetter(str)) {
    return true;
  }
  return false;
}
