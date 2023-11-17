#ifndef FUNCTIONS_H
#define FUNCTION_H

namespace oleynikova {
  bool isExpression(const char *str);
  bool isTerm(const char *&str);
  bool isDigit(const char *&str);
  bool isSign(const char &str);
  bool isLetter(const char *&str);
  bool isInteger(const char *& str, bool result);
  bool isMultiplier(const char *&str);
}

#endif
