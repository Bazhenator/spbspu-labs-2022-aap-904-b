#include <iostream>
#include "inputAndMaxCountingFunctions.h"

int main()
{
  int inputNumber = 1;
  int nMax = 0;
  int maxNumber = 0;
  bool isFirstInput = true;
  std::cout << "This programm counts number of elements equal to maximum.\n";
  std::cout << "Input elements of sequesnce or \"0\" to end: \n";
  while (inputNumber != 0) {
    try {
      inputNumber = ponomarev::inputElement();
      ponomarev::changeMax(maxNumber, nMax, isFirstInput, inputNumber);
    } catch (std::overflow_error & e) {
      std::cout << "Error: " << e.what();
      return 1;
    } catch (std::invalid_argument & e) {
      std::cout << "Error: " << e.what();
      return 1;
    } catch (std::logic_error & e) {
      std::cout << "Error: " << e.what();
      return 1;
    }
  }
  std::cout << "Number of elements equal to maximum number is: " << nMax;
  return 0;
}
