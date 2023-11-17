#include "workingWithMatrix.h"
#include <iostream>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <limits>
#include <set>

void flusova::getDataFromFile(std::ifstream &in, int* matrix, const size_t& rows,const size_t& cols, const char* task) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      in >> matrix[cols * i + j];
      if (!in) {
        if (!strcmp(task, "2")) {
          delete [] matrix;
        }
        throw std::runtime_error("Incorrect data!");
      }
    }
  }
}
int flusova::noSameElInStaticMatrixRows(const int* matrix, const size_t& rows, const size_t& cols) {
  const int MAX_INT = std::numeric_limits< int >::max();
  int counter = 0;
  for (size_t i = 0; i < rows; ++i) {
    std::set < int > rowValues{};
    int flag = 0;
    for (size_t j = 0; j < cols; ++j) {
      if (rowValues.find(matrix[cols * i + j]) != rowValues.end()) {
        flag = 1;
        break;
      }
      rowValues.insert(matrix[cols * i + j]);
    }
    if (flag != 1) {
      if (MAX_INT - 1 < counter) {
        throw std::runtime_error("Overflow!");
      } else {
        counter++;
      }
    }
  }
  return counter;
}
int flusova::noSameNearElInDynamicMatrixRows(const int* matrix, const size_t& rows, const size_t& cols) {
  const int MAX_INT = std::numeric_limits< int >::max();
  int counter = 0, yaCounter = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols - 1; ++j) {
      if (matrix[cols * i + j] == matrix[cols * i + (j + 1)]) {
        yaCounter = 0;
        break;
      }
      if (MAX_INT - 1 < yaCounter) {
        delete [] matrix;
        throw std::runtime_error("Overflow!");
      } else {
        yaCounter++;
      }
    }
    if (yaCounter != 0) {
      if (MAX_INT - 1 < counter) {
        delete [] matrix;
        throw std::runtime_error("Overflow!");
      } else {
        counter++;
      }
    }
    yaCounter = 0;
  }
  return counter;
}
