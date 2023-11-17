#include "countSignChanges.h"
#include <iostream>
#include <limits>

bool flusova::checkSign(int &num, int &yaNum) {
  return (((num > 0) && (yaNum < 0)) || ((num < 0) && (yaNum > 0)));
}

int flusova::checkInput() {
  int num;
  std::cin >> num;
  if (std::cin.fail()) {
    throw std::invalid_argument("Invalid argument!");
  }
  return num;
}

int flusova::checkCountNums(int& num, int& yaNum, int& counter) {
  int constexpr max_int = std::numeric_limits< int >::max();
  while (num != 0) {
    yaNum = num;
    num = flusova::checkInput();
    if (num != 0) {
      if (flusova::checkSign(num, yaNum)) {
        if (max_int - 1 < counter) {
          throw std::overflow_error("Overflow error!\n");
        }
        else {
          counter++;
        }
      }
    }
  }
  std::cout << "Quantity of changing sign: ";
  return counter;
}
