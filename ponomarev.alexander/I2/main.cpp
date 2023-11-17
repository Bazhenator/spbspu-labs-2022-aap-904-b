#include <iostream>
#include "manageWithArrays.h"
#include "inputData.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Incorrect amount of CML args.\n";
    return 2;
  }
  std::cout << "This programm finds the maximum number in the given interval.\n";

  const int FIXED_ARRAY_SIZE = 10;
  int fixedArray[FIXED_ARRAY_SIZE] = {3, 4, 6, 8, 0, -5, 3, -1, 9, 5};

  try {
    const char *fileName = argv[1];
    ponomarev::Array fileArray(fileName);

    std::cout << "Enter the number of elements for generaeted array: ";
    int dynamicArraySize = ponomarev::inputElement();
    ponomarev::Array dynamicArray(dynamicArraySize);
    dynamicArray.generateRandomArray();

    const int BEGIN_OF_THE_INTERVAL = 0;
    const int END_OF_THE_INTERVAL = 55;

    int maxNumberInFixedArray = ponomarev::findMaxInTheInterval(fixedArray, FIXED_ARRAY_SIZE, BEGIN_OF_THE_INTERVAL, END_OF_THE_INTERVAL);
    int maxNumberInDynamicArray = dynamicArray.findMaxInTheInterval(BEGIN_OF_THE_INTERVAL, END_OF_THE_INTERVAL);
    int maxNumberInFileArray = fileArray.findMaxInTheInterval(BEGIN_OF_THE_INTERVAL, END_OF_THE_INTERVAL);

    std::cout << "\nThe maximum number in fixed array is: " << maxNumberInFixedArray << "\n";
    std::cout << "The maximum number in dynamic array is: " << maxNumberInDynamicArray << "\n";
    std::cout << "The maximum number in read from file array is: " << maxNumberInFileArray << "\n";
  } catch (const std::runtime_error & e) {
    std::cout << "Error: " << e.what();
    return 1;
  }
  return 0;
}
