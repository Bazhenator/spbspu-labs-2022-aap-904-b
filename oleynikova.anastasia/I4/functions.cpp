#include "functions.h"
#include <fstream>
#include <cstdlib>
#include <cmath>

int oleynikova::countRows(const int *matrix, const std::size_t rows, const std::size_t cols)
{
  int count = 0;
  int temp = 0;
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (matrix[i * rows + j] == 0) {
        temp = 1;
        break;
      }
    }
    if (temp == 0) {
      count += 1;
    }
    temp = 0;
  }
  return count;
}

int oleynikova::countPoints(int *matrix, const std::size_t rows, const std::size_t cols)
{
  int max = pow(-10, 7);
  int min = pow(10, 7);
  int temp = 0;
  int count = 0;
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t j = 0; j < cols; j++) {
      if (matrix[i * rows + j] < min) {
        min = matrix[i * rows + j];
        temp = j;
      }
    }
    for (std::size_t k = 0; k < rows; k++) {
      if (matrix[k * rows + temp] > max) {
        max = matrix[k * rows + temp];
      }
    }
    if (min == max) {
      count += 1;
    }
    max = pow(-10, 7);
    min = pow(10, 7);
  }
  return count;
}

void oleynikova::inputMatrix(std::fstream &file, int *matrix, const std::size_t &rows, const std::size_t &cols)
{
  if (rows != 0 && cols != 0) {
    for (std::size_t i = 0; i < rows; i++) {
      for (std::size_t j = 0; j < cols; j++) {
        file >> matrix[rows * i + j];
        if (!file) {
          throw std::runtime_error("Elements must be integer");
        }
      }
    }
  }
}
