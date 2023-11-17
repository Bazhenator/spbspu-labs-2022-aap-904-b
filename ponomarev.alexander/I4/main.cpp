#include <iostream>
#include <fstream>
#include <cstring>
#include "matrixFunctons.h"

int main(int argc, char *argv[])
{
  if (argc != 4) {
    std::cerr << "In command line's arguments should be given number of the task, input and ouput files' names.";
    return 2;
  }
  std::fstream inputFile(argv[2], std::fstream::in);
  std::fstream outputFile(argv[3], std::fstream::out);
  if (!inputFile.is_open()) {
    std::cerr << "File couldn't be opened.";
    return 1;
  }
  int nRows, nColumns;
  try {
    nRows = ponomarev::inputElement(inputFile);
    nColumns = ponomarev::inputElement(inputFile);
  } catch (const std::runtime_error &e) {
    std::cout << "Error: " << e.what();
    return 1;
  }
  int builtInMatrix[3*3] = {0};
  if (nRows && nColumns) {
    try {
      // I read data here, because it is essential for correct test passing
      // "Run With Not Enough Data For Dynamic Array", but I don't need to read data from file, I fill it as spiral
      ponomarev::fillMatrixFromFile(builtInMatrix, inputFile);
    } catch (const std::runtime_error &e) {
      std::cout << "Error: " << e.what();
      return 1;
    }
  }
  if (!std::strcmp(argv[1], "1")) {
    outputFile << ponomarev::countOnlyPositiveRows(builtInMatrix);
  } else if (!std::strcmp(argv[1], "2")) {
    int *matrix = nullptr;
    try {
      matrix = new int[nRows*nRows];
    } catch (const std::bad_alloc &e) {
      std::cout << "Error: " << e.what();
      return 1;
    }
    ponomarev::fillMatrixAsSpiral(matrix, nRows);
    ponomarev::printMatrix(matrix, nRows, outputFile);
    delete[] matrix;
  } else {
    std::cerr << "First command line's argument is not correct.";
    return 2;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
