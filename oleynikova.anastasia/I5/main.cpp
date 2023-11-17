#include <iostream>
#include "functions.h"
#include "../common/inputString.h"

int main()
{
  std::size_t capacity = 20;
  char *string = nullptr;
  try {
    string = oleynikova::inputString(std::cin, capacity);
  }
  catch (const std::runtime_error &e) {
    std::cerr << e.what();
    return 1;
  }
  std::cout << (oleynikova::isExpression(string) ? "true\n" : "false\n");
  delete[] string;
  return 0;
}
