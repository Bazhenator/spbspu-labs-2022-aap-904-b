#include "inputAndMaxCountingFunctions.h"
#include <iostream>
#include <cstdlib>
#include <limits>

int ponomarev::inputElement()
{
  int inputNumber;
  std::cin >> inputNumber;
  if (!std::cin.fail()) {
    return inputNumber;
  } else {
    throw std::invalid_argument("Input error (not integer or overflow)");
  }
}
void ponomarev::changeMax(int &maxNumber, int &nMax, bool &isFirstInput, int inputNumber)
{
  const int MAX_INT = std::numeric_limits< int >::max();
  if (isFirstInput) {
    if (isFirstInput && (inputNumber == 0)) {
      throw std::logic_error("Sequence couldn't be empty.");
    }
    maxNumber = inputNumber;
    isFirstInput = false;
  }
  if ((maxNumber < inputNumber) && (inputNumber != 0)) {
    maxNumber = inputNumber;
    nMax = 1;
  } else if (maxNumber == inputNumber) {
    if (nMax > MAX_INT - 1) {
      throw std::overflow_error("Overflow.");
    }
    nMax++;
  }
}
