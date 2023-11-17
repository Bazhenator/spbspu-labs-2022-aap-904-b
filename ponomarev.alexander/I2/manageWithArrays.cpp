#include "manageWithArrays.h"
#include <iostream>
#include <fstream>
#include <ctime>

ponomarev::Array::Array(const ponomarev::Array &array)
{
  data_ = new int[array.capacity_];
  capacity_ = array.capacity_;
  for (std::size_t i = 0; i < capacity_; i++) {
    data_[i] = array.data_[i];
  }
}
ponomarev::Array::Array(const char *fileName)
{
  std::ifstream fileInput(fileName, std::ios_base::in);
  if (!fileInput.is_open()) {
    throw std::runtime_error("File couldn't be opened.");
  }
  fileInput >> capacity_;
  if (fileInput.fail()) {
    throw std::runtime_error("File couldn't be empty.");
  }
  data_ = new int[capacity_];
  for (int i = 0, element; !fileInput.eof(); i++) {
    fileInput >> element;
    data_[i] = element;
    if (fileInput.fail()) {
      throw std::runtime_error("File data is not valid.");
    }
  }
  fileInput.close();
}
ponomarev::Array::~Array()
{
  delete[] data_;
}
void ponomarev::Array::generateRandomArray()
{
  std::srand(std::time(nullptr));
  for (std::size_t i = 0; i < capacity_; i++) {
    data_[i] = std::rand() % 101;
  }
}
int ponomarev::Array::findMaxInTheInterval(int beginOfTheInterval, int endOfTheInterval)
{
  int max = 0;
  for (std::size_t i  = 0; i < capacity_; i++) {
    bool inInterval = (data_[i] >= beginOfTheInterval) && (data_[i] <= endOfTheInterval);
    max = ((inInterval && (data_[i] > max)) ? data_[i] : max);
  }
  return max;
}

int ponomarev::findMaxInTheInterval(int *array, const int arraySize, const int beginOfTheInterval, const int endOfTheInterval)
{
  int max = 0;
  for (int i  = 0; i < arraySize; i++) {
    bool inInterval = (*(array + i) >= beginOfTheInterval) && (*(array + i) <= endOfTheInterval);
    max = ((inInterval && (*(array + i) > max)) ? *(array + i) : max);
  }
  return max;
}
