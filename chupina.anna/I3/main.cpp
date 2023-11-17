#include <cstringFunctions.h>
#include "stringsManaging.h"

int main() {
  size_t capacity = 0;
  char* cString = nullptr;
  char* newCString = nullptr;
  try {
    cString = chupina::inputString(std::cin, capacity);
    newCString = new char[capacity];
  } catch (const std::bad_alloc &e) {
    delete [] cString;
    throw;
  } catch (const std::runtime_error &e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  newCString = chupina::replaceUpperToLowerCase(newCString, cString);
  std::cout << newCString << '\n';
  delete [] newCString;
  return 0;
}
