#ifndef CHECK_IF_VALID_H
#define CHECK_IF_VALID_H

#include <cstddef>

namespace ponomarev {
  class Parser {
    Parser(char *string):
      pts(string),
      nBrackets(0)
    {}

    bool isExp();
    bool isTerm();
    bool isMult();
    bool isUnsignedInt();
    bool isAlpha();
    bool match(char etalon);

    friend bool isMathExpr(char *string);

    char *pts;
    int nBrackets;
  };

  bool isMathExpr(char *string);
}

#endif
