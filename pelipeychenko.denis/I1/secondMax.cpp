#include "secondMax.h"
#include <iostream>

int pelipeychenko::intInput(bool first_element) {
  int input;
  std::cin >> input;
  if (!std::cin) {
    throw std::invalid_argument("Error: Argument must be integer");
  }
  if (first_element && input == 0) {
    throw std::invalid_argument("Error: Empty subsequence");
  }
  return input;
}

int pelipeychenko::findSecondMaxOfSubsequence() {
  int element;
  try {
    element = intInput(true);
  }
  catch (const std::invalid_argument &e) {
    std::cout << e.what() << '\n';
    return 1;
  }

  int maximum = element;
  int secondMaximum = 0;
  bool secondMaximumIsDefined = false;

  while (element != 0) {
    if (element > maximum) {
      secondMaximum = maximum;
      secondMaximumIsDefined = true;
      maximum = element;
    } else if (element < maximum && (element > secondMaximum || (element < secondMaximum && secondMaximum == 0))) {
      secondMaximum = element;
      secondMaximumIsDefined = true;
    }
    try {
      element = intInput(false);
    }
    catch (const std::invalid_argument &e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  }
  if (!secondMaximumIsDefined) {
    throw std::logic_error("Error: not enough elements to solve the task");
  }
  return secondMaximum;
}
