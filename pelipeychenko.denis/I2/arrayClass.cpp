#include "arrayClass.h"
#include <ctime>
#include <fstream>

pelipeychenko::Array::Array(const char *path) :
  size_(getFileSize(path)),
  data_(new int[size_]) {}

pelipeychenko::Array::Array(std::size_t size) :
  size_(size),
  data_(new int[size]) {}

pelipeychenko::Array::~Array() {
  delete[] data_;
}

std::size_t pelipeychenko::Array::getFileSize(const char *path) {
  std::ifstream in;
  in.open(path);
  if (in.peek() == EOF) {
    throw std::invalid_argument("Error: file is empty");
  }
  if (!in) {
    throw std::invalid_argument("Error: something wrong with file opening");
  }
  std::size_t size;
  in >> size;
  if (!in) {
    throw std::invalid_argument("Error: file size must be integer");
  }
  return size;
}

void pelipeychenko::Array::fillFromFile(const char *path) const {
  std::ifstream in;
  in.open(path);
  in.ignore(size_, '\n');
  for (std::size_t i = 0; i < size_; ++i) {
    in >> data_[i];
    if (!in) {
      throw std::invalid_argument("Error: array must consist of integer");
    }
  }
}

void pelipeychenko::Array::fillWithRandom() const {
  std::srand(time(nullptr));
  for (std::size_t i = 0; i < size_; ++i) {
    data_[i] = (rand() % 7 == 0 ? -rand() : rand());
  }
}

int pelipeychenko::Array::findCountLeftToMin() const {
  if (size_ == 0u) {
    return 0;
  }
  int min = data_[size_ - 1];
  int count = 0;
  for (std::size_t i = size_ - 1; i >= 1; --i) {
    if (data_[i - 1] < min) {
      count = 0;
      min = data_[i - 1];
    } else if (data_[i - 1] > 0) {
      count++;
    }
  }
  return count;
}
