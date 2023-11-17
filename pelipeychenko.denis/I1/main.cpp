#include <iostream>
#include "secondMax.h"

int main() {

  try {
    int secondMax = pelipeychenko::findSecondMaxOfSubsequence();
    std::cout << secondMax;
  }
  catch (const std::logic_error &e) {
    std::cout << e.what();
    return 1;
  }

  return 0;
}
