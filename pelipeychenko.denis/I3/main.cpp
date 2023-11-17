#include <iostream>
#include <stringFunctions.h>

#include "stringManaging.h"

int main() {
  std::size_t size = 0u;
  char *result, *cstring;
  try {
    cstring = pelipeychenko::inputString(std::cin, size);
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  try {
    result = new char[size];
  } catch (const std::bad_alloc &e) {
    std::cerr << "bad_alloc error" << "\n";
    delete[] cstring;
    return 1;
  }

  pelipeychenko::deleteDigits(result, cstring);
  std::cout << result << "\n";
  delete[] result;
  delete[] cstring;
  return 0;
}
