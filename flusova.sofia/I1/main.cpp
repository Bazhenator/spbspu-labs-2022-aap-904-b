#include <iostream>
#include "countSignChanges.h"

int main() {
  int num, yaNum, counter = 0;
  std::cout << "Please, enter an integer elements of sequence:\n";
  try {
    num = flusova::checkInput();
    if (num != 0) {
      std::cout << flusova::checkCountNums(num, yaNum, counter) << '\n';
    } else {
      std::cout << "Empty sequence!\n";
    }
  }
  catch (const std::length_error& error) {
    std::cout << error.what();
    return 1;
  }
  catch (const std::invalid_argument& error) {
    std::cout << error.what();
    return 1;
  }
  catch (const std::overflow_error& error) {
    std::cout << error.what();
    return 1;
  }
  return 0;
}
