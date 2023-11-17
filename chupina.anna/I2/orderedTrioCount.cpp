#include "orderedTrioCount.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <limits>

chupina::DynamicArray::DynamicArray():
  capacity(0),
  data(nullptr)
{}

chupina::DynamicArray::DynamicArray(std::ifstream & fin)
{
  fin >> capacity;
  if (fin.fail()) {
    throw std::logic_error("Size of the array must be integer between 0 and 2147483647");
  }
  data = new int[capacity];
  for (std::size_t i = 0; i < capacity; ++i) {
    fin >> *(data + i);
    if (fin.fail()) {
      throw std::logic_error("Values must be integer");
    }
  }
}

chupina::DynamicArray::~DynamicArray()
{
  delete[] data;
}

void chupina::DynamicArray::fillArrayWithRandomVals()
{
  std::cout << "Input size of the array: ";
  std::cin >> capacity;
  if (std::cin.fail()) {
    throw std::logic_error("Size of the array must be integer between 0 and 2147483647");
  }
  data = new int[capacity];
  std::srand(std::time(nullptr));
  for (std::size_t i = 0; i < capacity; ++i) {
    *(data + i) = std::rand() % 10001;
  }
}

int chupina::countOrderedTrio(const std::size_t & arraySize, int * arrayValues)
{
  if (arraySize < 3) {
    return 0;
  }
  const int MAX_INT = std::numeric_limits< int >::max();
  int answer = 0;
  for (std::size_t i = 0; i < arraySize-2; ++i) {
    if (arrayValues[i] > arrayValues[i+1] and arrayValues[i+1] > arrayValues[i+2]) {
      if (MAX_INT - 1 >= answer) {
        answer++;
      } else {
        throw std::logic_error("Answer is overflow");
      }
    }
  }
  return answer;
}

void chupina::openFile(std::ifstream & fin, const char * path)
{
  fin.open(path);
  if (fin.fail()) {
    throw std::logic_error("Can not open/read the file");
  }
  if (fin.peek() == EOF) {
    throw std::logic_error("Empty file");
  }
}
