#include "input.h"
#include <iostream>

int oleynikova::inputElement()
{
  int number;
  std::cin >> number;
  if (!std::cin) {
    throw std::runtime_error("Size must be integer");
  }
  return number;
}
