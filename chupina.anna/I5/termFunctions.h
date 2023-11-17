#ifndef TERM_FUNCTIONS_H
#define TERM_FUNCTIONS_H

namespace chupina {
  class RecursiveDescentParser {
    public:
      RecursiveDescentParser() = delete;
      RecursiveDescentParser(char* string);
      ~RecursiveDescentParser() = default;

      bool isAlpha();
      bool isDigit();
      bool isUnsignedInteger(bool check = 0);
      bool isFactor();
      bool isSign();
      bool isTerm();
      bool isExpression();

    private:
      char* expression;
  };
}

#endif
