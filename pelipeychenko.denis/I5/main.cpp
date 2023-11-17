#include <iostream>
#include <stringFunctions.h>

#include "recursion.h"

int main() {
  std::size_t size = 0u;
  try {
    char *data = pelipeychenko::inputString(std::cin, size);
    pelipeychenko::customString string(data, size);
    std::cout << (string.checkIfReal() ? "true" : "false") << "\n";
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
