#include <iostream>
#include <cstddef>
#include <inputData.h>
#include "isRealValue.h"

int main() {
  size_t capacity = 20;
  size_t pos = 0;
  char* data = nullptr;
  try {
    data = flusova::inputData(std::cin, capacity);
    std::cout << (flusova::isRealValue(data, pos) ? "true" : "false") << '\n';
  }
  catch (const std::bad_alloc& e) {
    delete [] data;
    throw;
  }
  catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << '\n';
    delete [] data;
    return 1;
  }
  delete [] data;
  return 0;
}
