#include <iostream>
#include "checkValid.h"
#include "../common/manageWithCStrings.h"

int main()
{
  std::size_t capacity = 20;
  char *str = nullptr;
  try {
    str = ponomarev::input(std::cin, capacity);
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  std::cout << (ponomarev::isMathExpr(str) ? "true" : "false") << std::endl;
  delete[] str;
  return 0;
}
