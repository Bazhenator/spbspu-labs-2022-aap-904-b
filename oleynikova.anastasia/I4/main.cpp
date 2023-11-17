#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"

int main(int argc, char *argv[])
{
  if (argc != 4) {
    std::cerr << "Expected 3 parameters";
    return 1;
  }
  std::fstream inputFile(argv[2]);
  std::fstream outputFile(argv[3]);
  std::size_t rows;
  std::size_t cols;
  inputFile >> rows >> cols;
  if (!inputFile) {
    std::cerr << "Input error";
    return 1;
  }
  if (!(std::strcmp(argv[1], "1"))) {
    int fixMatrix[9] = {0};
    try {
      oleynikova::inputMatrix(inputFile, fixMatrix, rows, cols);
    }
    catch (const std::runtime_error &e) {
      std::cout << e.what();
      return 1;
    }
    int count = 0;
    count = oleynikova::countRows(fixMatrix, rows, cols);
    outputFile << "Number of rows: " << count << "\n";
  }
  else if (!(std::strcmp(argv[1], "2"))) {
    if (cols != 0 && rows != 0) {
      int *matrix = nullptr;
      try {
        matrix = new int[rows * cols];
        oleynikova::inputMatrix(inputFile, matrix, rows, cols);
      }
      catch (const std::bad_alloc &e) {
        std::cerr << e.what();
        return 1;
      }
      catch (const std::runtime_error &e) {
        std::cerr << e.what();
        delete[] matrix;
        return 1;
      }
      int count = oleynikova::countPoints(matrix, rows, cols);
      outputFile << "Number of points: " << count << "\n";
      delete[] matrix;
    }
  }
  else {
    std::cerr << "Expected the number of task: 1 or 2";
    return 1;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
