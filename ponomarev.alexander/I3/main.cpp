#include <iostream>
#include <cstddef>
#include "manageWithCStrings.h"
#include "../common/manageWithCStrings.h"

int main()
{
  std::cout << "Enter string: ";
  std::size_t stringCapacity = 20;
  char *string = nullptr;
  try {
    string = ponomarev::input(std::cin, stringCapacity);
  } catch (const std::runtime_error &e) {
    std::cout << "Error: " << e.what();
    return 1;
  }
  char *newString = nullptr;
  try {
    newString = new char[stringCapacity];
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what() << "\n";
    delete[] string;
    return 1;
  }
  ponomarev::removeAlpha(newString, string);
  std::cout << "String with removed alpha: " << newString;
  delete[] newString;
  delete[] string;
  return 0;
}
