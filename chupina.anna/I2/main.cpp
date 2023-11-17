#include <iostream>
#include <fstream>
#include "orderedTrioCount.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Incorrect amount of CML args\n";
    return 2;
  }
  try {
    const int STATIC_ARRAY_SIZE = 10;
    int staticArray[STATIC_ARRAY_SIZE] = {5,3,8,6,1,2,9,7,4,0};
    int answer;
    answer = chupina::countOrderedTrio(STATIC_ARRAY_SIZE, staticArray);
    std::cout << "Answer for static array is: " << answer << '\n';
    std::ifstream fileData;
    chupina::openFile(fileData, argv[1]);
    chupina::DynamicArray dynArrFileVals{fileData};
    answer = chupina::countOrderedTrio(dynArrFileVals.capacity, dynArrFileVals.data);
    std::cout << "Answer for dynamic array with values from file is: " << answer << '\n';
    chupina::DynamicArray dynArrRandVals;
    dynArrRandVals.fillArrayWithRandomVals();
    answer = chupina::countOrderedTrio(dynArrRandVals.capacity, dynArrRandVals.data);
    std::cout << "Answer for dynamic array with random values is: " << answer << '\n';
  } catch (const std::logic_error& e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
