#include <iostream>
#include <cstddef>
#include <inputData.h>
#include "solvingStringTasks.h"

int main()
{
  char* cstring = nullptr;
  try
  {
    size_t capacity = 10;
    cstring = flusova::inputData(std::cin, capacity);
    cstring[capacity - 1] = '\0';
    std::cout << flusova::checkSameDigitsInCline(cstring) << '\n';
    std::cout << flusova::checkSameNearElInCline(cstring) << '\n';
    delete[] cstring;
  } catch(const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }
  return 0;
}




