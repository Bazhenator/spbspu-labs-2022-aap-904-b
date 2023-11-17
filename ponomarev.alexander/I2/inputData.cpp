#include "inputData.h"
#include <iostream>

int ponomarev::inputElement()
{
  int inputNumber;
  std::cin >> inputNumber;
  if (std::cin.fail()) {
    throw std::runtime_error("Input error.");
  } else {
    return inputNumber;
  }
}
