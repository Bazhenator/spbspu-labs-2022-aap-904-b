#include "inputElement.h"
#include <iostream>
#include <limits>

int oleynikova::inputElement()
{
  int number;
  std::cin >> number;
  if (!std::cin) {
    throw std::invalid_argument("The elements must me integer");
  } else {
    return number;
  }
}
