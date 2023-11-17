#include <cstringFunctions.h>
#include "termFunctions.h"

int main()
{
  size_t capacity = 10;
  char* expression = nullptr;
  try {
    expression = chupina::inputString(std::cin, capacity);
  } catch (const std::bad_alloc &e) {
    delete [] expression;
    throw;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  chupina::RecursiveDescentParser Expression(expression);
  if (Expression.isExpression()) {
    std::cout << "true" << '\n';
  } else {
    std::cout << "false" << '\n';
  }
  delete [] expression;
  return 0;
}
