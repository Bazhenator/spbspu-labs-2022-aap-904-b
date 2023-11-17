#include "changeArray.h"
#include <iostream>
#include <fstream>

void oleynikova::changeArray(int *arr, const int SIZE)
{
  int temp = 0;
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - 1; j++) {
      if (arr[j] >= 0) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void oleynikova::printArray(int *arr, const int SIZE)
{
  std::cout << "Converted array:\n";
  for (int i = 0; i < SIZE; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

oleynikova::Array::Array(const oleynikova::Array &arr)
{
  size_ = arr.size_;
  if (size_ != 0) {
    data_ = new int[size_];
    for (std::size_t i = 0; i < size_; i++) {
      data_[i] = arr.data_[i];
    }
  }
}
oleynikova::Array::Array():
  data_(nullptr),
  size_(0)
{}
oleynikova::Array::Array(std::size_t size):
  data_(new int[size]),
  size_(size)
{}
oleynikova::Array::Array(const char *name)
{
  std::ifstream file;
  file.open(name, std::ios::in);
  if (!file.is_open()) {
    throw std::runtime_error("File was not opened");
  }
  file >> size_;
  if (!file) {
    throw std::runtime_error("Empty file");
  }
  if (size_ != 0) {
    data_ = new int[size_];
    for (std::size_t i = 0; i < size_; i++) {
      file >> data_[i];
      if (!file) {
        throw std::runtime_error("Elements must be integer");
      }
    }
  }
  file.close();
}
oleynikova::Array::~Array()
{
  if (size_ != 0) {
    delete[] data_;
  }
}
