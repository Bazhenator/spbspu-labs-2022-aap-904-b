#include "matrixFunctons.h"
#include <iostream>
#include <iomanip>

int ponomarev::countOnlyPositiveRows(const int *matrix, const std::size_t nMatrixRows, const std::size_t nMatrixColumns)
{
  int counter = 0;
  bool flag = true;
  for (std::size_t i = 0; i < nMatrixRows; i++) {
    for (std::size_t k = 0; k < nMatrixColumns; k++) {
      if (matrix[i*nMatrixRows + k] <= 0) {
        flag = false;
        break;
      }
    }
    counter += (flag ? 1 : 0);
    flag = true;
  }
  return counter;
}
int ponomarev::countNumbersInInteger(int number)
{
  return (number / 10 ? 1 + countNumbersInInteger(number / 10) : 1);
}
int ponomarev::inputElement(std::fstream &file)
{
  int inputNumber;
  if (!file.eof() && (file >> inputNumber)) {
    if (file.fail()) {
      throw std::runtime_error("Input error.");
    }
    return inputNumber;
  } else {
    throw std::runtime_error("Input error, expected more elements.");
  }
}
void ponomarev::fillMatrixFromFile(int *matrix, std::fstream &file, const std::size_t rows, const std::size_t columns) {
  for (std::size_t i = 0; i < rows; i++) {
    for (std::size_t k = 0; k < columns; k++) {
      matrix[rows*i + k] = ponomarev::inputElement(file);
    }
  }
}
void ponomarev::fillMatrixAsSpiral(int *matrix, const int dimension)
{
  int currentPosition[2] = {dimension, 0};
  // How much we should add to current position when go to {up, right, down, left}
  int direction[4] = {-1, 1, 1, -1};
  int value = 1;
  // How much times we have used direction
  int horizontal = 1;
  int vertical = 0;
  for (int i = 0; i < (dimension * 2 - 1); i++) {
    int directionIndex = i % 4;
    // How much positions in row/column isn't filled
    int iterNumber = (directionIndex % 2 ? dimension - horizontal++ : dimension - vertical++);
    for (int k = 0; k < iterNumber; k++) {
      currentPosition[directionIndex % 2] += direction[directionIndex];
      matrix[currentPosition[0]*dimension + currentPosition[1]] = value++;
    }
  }
}
void ponomarev::printMatrix(int *matrix, const std::size_t dimension, std::fstream &file)
{
  for (std::size_t i = 0; i < dimension; i++) {
    for (std::size_t k = 0; k < dimension; k++) {
      file << std::setw(ponomarev::countNumbersInInteger(dimension * dimension)) << matrix[i*dimension + k] << ' ';
    }
    file << std::endl;
  }
}
