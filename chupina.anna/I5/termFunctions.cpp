#include "termFunctions.h"
#include <iostream>

chupina::RecursiveDescentParser::RecursiveDescentParser(char* string):
  expression(string)
{}

bool chupina::RecursiveDescentParser::isAlpha()
{
  if (*expression >= 'a' && *expression <= 'e') {
    ++expression;
    return 1;
  }
  return 0;
}
bool chupina::RecursiveDescentParser::isDigit()
{
  if (isdigit(*expression)) {
    ++expression;
    return 1;
  }
  return 0;
}
bool chupina::RecursiveDescentParser::isUnsignedInteger(bool check)
{
  if (isDigit()) {
    check = 1;
    return isUnsignedInteger(check);
  }
  return check;
}
bool chupina::RecursiveDescentParser::isFactor()
{
  if (isUnsignedInteger(0) || isAlpha()) {
    return 1;
  }
  return 0;
}
bool chupina::RecursiveDescentParser::isSign()
{
  if (expression[0] == '+' || expression[0] == '*' || expression[0] == '-' || expression[0] == '/') {
    expression++;
    return 1;
  }
  return 0;
}
bool chupina::RecursiveDescentParser::isTerm()
{
  if (isFactor()) {
    if (expression[0]) {
      return isSign() && isTerm();
    }
    return 1;
  }
  return 0;
}
bool chupina::RecursiveDescentParser::isExpression()
{
  if (isTerm()) {
    if (expression[0]) {
      return isSign() && isExpression();
    }
    return 1;
  }
  return 0;
}
