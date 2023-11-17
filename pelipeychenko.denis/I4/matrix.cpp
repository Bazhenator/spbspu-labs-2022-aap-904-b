#include "matrix.h"
#include <fstream>
#include <iostream>

pelipeychenko::dynamicMatrix::dynamicMatrix() :
  rows_(0u),
  cols_(0u),
  data_(nullptr) {};

pelipeychenko::dynamicMatrix::~dynamicMatrix() {
  delete[] data_;
}

void pelipeychenko::dynamicMatrix::fillMatrixFromFile(const char *argc[]) {
  std::ifstream in;
  in.open(argc[2]);
  if (!in) {
    throw std::invalid_argument("error: wrong file name");
  }
  in >> rows_ >> cols_;
  if (!in) {
    throw std::invalid_argument("error: wrong size params");
  }
  data_ = new int[rows_ * cols_];
  for (int *element = data_; element < data_ + rows_ * cols_; ++element) {
    in >> *element;
    if (!in) {
      throw std::invalid_argument("error: matrix must be filled with ints");
    }
  }
}

bool pelipeychenko::dynamicMatrix::checkIfLess(size_t row, size_t col, size_t compareRow, size_t compareCol) const {
  if (row == compareRow && col == compareCol) {
    return true;
  }
  if (compareCol >= cols_) {
    return true;
  }
  if (compareRow >= rows_) {
    return true;
  }
  return (data_[row * cols_ + col] < data_[compareRow * cols_ + compareCol]);
}


bool pelipeychenko::dynamicMatrix::checkIfLocalMin(size_t row, size_t col) const {
  for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (!checkIfLess(row, col, row + i, col + j)) {
        return false;
      }
    }
  }
  return true;
}

int pelipeychenko::dynamicMatrix::countLocalMins() const {
  int count = 0;
  for (size_t row = 0; row < rows_; row++) {
    for (size_t col = 0; col < cols_; col++) {
      if (checkIfLocalMin(row, col)) {
        count++;
      }
    }
  }
  return count;
}

int pelipeychenko::countRowsWithNull(const int *matrix, size_t rows, size_t cols) {
  int count = 0;
  for (const int *element = matrix; element < matrix + rows * cols; ++element) {
    if (*element == 0) {
      count++;
      element = (matrix + cols * ((element - matrix) / cols + 1)) - 1;
    }
  }
  return count;
}

void pelipeychenko::fillFromFileStaticMatrix(int *matrix, size_t &rows,
                                             size_t &cols, const char *argc[]) {
  std::ifstream in;
  in.open(argc[2]);
  if (!in) {
    throw std::invalid_argument("error: wrong file name");
  }
  in >> rows >> cols;
  if (!in) {
    throw std::invalid_argument("error: wrong size params");
  }
  for (int *element = matrix; element < matrix + rows * cols; ++element) {
    in >> *element;
    if (!in) {
      throw std::invalid_argument("error: matrix must be filled with ints");
    }
  }
}

void pelipeychenko::writeOutput(int result, const char *argc[]) {
  std::ofstream out;
  out.open(argc[3]);
  if (!out) {
    throw std::invalid_argument("error: something wrong with output file");
  }
  out << result;
  if (!out) {
    throw std::invalid_argument("error: something wrong with output file");
  }
}
