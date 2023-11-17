#include "working_with_arrays.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>

flusova::ArrayStruct::ArrayStruct():
  capacity(0),
  array(nullptr)
  {}
flusova::ArrayStruct::ArrayStruct(const char *path) {
  getDataFromFile(path);
}
flusova::ArrayStruct::~ArrayStruct() {
  delete[] array;
}
void flusova::ArrayStruct::getDataFromFile(const char *path) {
  std::ifstream fin;
  fin.open(path);
  if (!fin.is_open())
    throw std::runtime_error("No such file in directory!");
  if (fin.peek() == EOF)
    throw std::logic_error("Empty file!");
  fin >> capacity;
  if (capacity == 0) {
    array = nullptr;
  } else {
    array = new int[capacity];
    for (std::size_t i = 0; i < capacity; ++i) {
      fin >> *(array + i);
      if (fin.fail()) {
        throw std::logic_error("Integer was excepted!");
      }
    }
  }
}
void flusova::ArrayStruct::getDataForRandomArray() {
  std::cout << "Please, enter the capacity for random array: " << std::endl;
  std::cin >> capacity;
  if (std::cin.fail())
    throw std::logic_error("Integer was excpected!");
  if (capacity == 0) {
    array = nullptr;
  } else {
    array = new int[capacity];
    for (std::size_t i = 0; i < capacity; ++i) {
      array[i] = rand() % 100000 - 50000;
    }
  }
}
void flusova::printQuantityOfNegElInArray(const size_t &capacity_, int * array) {
  if (array == nullptr) {
    std::cout << "Quantity: 0" << std::endl;
  } else {
    int max = array[0];
    int counter = 0;
    const int maxInt = std::numeric_limits< int >::max();
    for (std::size_t i = 0; i < capacity_; ++i) {
      if (max < *(array + i)) {
        max = *(array + i);
        counter = 0;
      } else if (*(array + i) < 0) {
        if (maxInt - 1 < counter) {
          throw std::runtime_error("Overflow error!");
        }
        counter++;
      }
    }
    std::cout << "Quantity: " << counter << std::endl;
  }
}
