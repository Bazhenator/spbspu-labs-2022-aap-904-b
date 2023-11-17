#include <iostream>
#include <fstream>
#include <ctime>
#include "changeArray.h"
#include "input.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    std::cerr << "Expected one parameter";
    return 2;
  }
  const int FIX_ARR_SIZE = 10;
  int fixArr[FIX_ARR_SIZE] = { 1, -3, 0, 5, 6, -10, 4, -4, 7, 8 };

  try {
    const char *name = argv[1];
    oleynikova::Array fileArr(name);
    oleynikova::changeArray(fixArr, FIX_ARR_SIZE);
    oleynikova::printArray(fixArr, FIX_ARR_SIZE);
    int dynArrSize = oleynikova::inputElement();
    if (dynArrSize == 0) {
      return 0;
    }
    oleynikova::Array dynArr(dynArrSize);
    std::srand(std::time(nullptr));
    for (int i = 0; i < dynArrSize; i++) {
      dynArr.data_[i] = std::rand() % 20 - 10;
    }
    oleynikova::changeArray(dynArr.data_, dynArr.size_);
    oleynikova::printArray(dynArr.data_, dynArr.size_);
    oleynikova::changeArray(fileArr.data_, fileArr.size_);
    oleynikova::printArray(fileArr.data_, fileArr.size_);
  }
  catch (const std::runtime_error & e) {
    std::cout << e.what() << "\n";
    return 1;
  }
  return 0;
}
