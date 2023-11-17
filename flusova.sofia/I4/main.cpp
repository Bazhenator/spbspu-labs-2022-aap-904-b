#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "workingWithMatrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4) {
    std::cerr << "The amount of CML arguments must be equal to four!" << '\n';
    return 2;
  }
  if (!strcmp(argv[1], "1")) {
    std::ifstream in {argv[2]};
    if (in.peek() == EOF) {
      std::cerr << "Excpected data hasn't been reached!" << '\n';
      return 1;
    }
    size_t rows, cols;
    in >> rows >> cols;
    if (!in) {
      std::cerr << "Values must be unsigned long long integers!" << '\n';
      return 1;
    }
    if (rows == 0 && cols == 0) {
      return 0;
    }
    int staticMatrix[rows * cols];
    try {
      flusova::getDataFromFile(in, staticMatrix, rows, cols, argv[1]);
      std::ofstream to {argv[3]};
      to << flusova::noSameElInStaticMatrixRows(staticMatrix, rows, cols);
    } catch (const std::runtime_error &e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  }
  else if (!strcmp(argv[1], "2")) {
    std::ifstream in {argv[2]};
    if (in.peek() == EOF) {
      std::cerr << "Excpected data hasn't been reached!" << '\n';
      return 1;
    }
    size_t rows, cols;
    in >> rows >> cols;
    if (!in) {
      std::cerr << "Values must be unsigned long long integers!" << '\n';
      return 1;
    }
    if (rows == 0 && cols == 0) {
      return 0;
    }
    try {
      int *dynamicMatrix = new int[rows * cols];
      flusova::getDataFromFile(in, dynamicMatrix, rows, cols, argv[1]);
      std::ofstream to {argv[3]};
      to << flusova::noSameNearElInDynamicMatrixRows(dynamicMatrix, rows, cols);
      delete [] dynamicMatrix;
    } catch (const std::bad_alloc &e) {
      std::cerr << "Memory hasn't been allocated!" << '\n';
      return 1;
    } catch (const std::runtime_error &e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  }
  else {
    std::cerr << "There are no extra-tasks!" << '\n';
    return 1;
  }
  return 0;
}
