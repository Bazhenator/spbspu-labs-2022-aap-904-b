#include <iostream>
#include "working_with_arrays.h"

int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Two CML arguments was excepted!" << std::endl;
      return 2;
    }
    std::cout << "STATIC ARRAY" << std::endl;
    const int STATIC_DATA_SIZE = 10;
    int staticData[STATIC_DATA_SIZE] = {6,234,-8,0,78,456,-9,87,-94,-1};
    flusova::printQuantityOfNegElInArray(STATIC_DATA_SIZE, staticData);
    std::cout << "ARRAY_FROM_TXT" << std::endl;
    flusova::ArrayStruct textArray{argv[argc - 1]};
    textArray.getDataFromFile(argv[argc - 1]);
    flusova::printQuantityOfNegElInArray(textArray.capacity, textArray.array);
    std::cout << "RANDOM ARRAY" << std::endl;
    flusova::ArrayStruct randomArray{};
    randomArray.getDataForRandomArray();
    flusova::printQuantityOfNegElInArray(randomArray.capacity, randomArray.array);
  }
  catch (const std::runtime_error &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  catch (const std::logic_error &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
