#include <iostream>
#include "makeString.h"
#include "../common/inputString.h"

int main()
{
  std::size_t capacity = 20;
  char *string = nullptr;
  try {
    string = oleynikova::inputString(std::cin, capacity);
  }
  catch (const std::runtime_error &e) {
    std::cout << e.what();
    return 1;
  }
  char *newString = nullptr;
  try {
    newString = new char[capacity];
  }
  catch (const std::bad_alloc &e) {
    std::cerr << e.what();
    delete[] string;
    return 1;
  }
  oleynikova::makeString(newString, string);
  std::cout << newString;
  delete[] newString;
  delete[] string;
  return 0;
}
