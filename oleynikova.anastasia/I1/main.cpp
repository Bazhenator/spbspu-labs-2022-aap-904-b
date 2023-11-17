#include <iostream>
#include "inputElement.h"

int main()
{
  const int END_OF_SEQUENCE = 0;
  int number = 0;
  std::cout << "Enter members" << "\n";
  try {
    number = oleynikova::inputElement();
  } catch (const std::invalid_argument & e) {
    std::cout << e.what();
    return 1;
  } catch (const std::overflow_error & e) {
    std::cout << e.what();
    return 1;
  }
  int count = 0;
  int secondNumber = 0;
  int temp = 0;
  while (number != END_OF_SEQUENCE) {
    secondNumber = number;
    try {
      number = oleynikova::inputElement();
    } catch (const std::invalid_argument & e) {
      std::cout << e.what();
      return 1;
    } catch (const std::overflow_error & e) {
      std::cout << e.what();
      return 1;
    }
    if (number != END_OF_SEQUENCE) {
      temp = 1;
      if (number > secondNumber) {
        count += 1;
      }
    } else {
      std::cout << "The number of related elements : " << count << "\n";
      break;
    }
  }
  if (temp == 0) {
    std::cout << "Empty sequence" << "\n";
  }
  return 0;
}
