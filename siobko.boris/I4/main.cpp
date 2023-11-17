#include "manageArray.h"
#include "manageData.h"
#include <iostream>

int main(int argc, const char *argv[])
{
  const char *inputFile = argv[2], *outputFile = argv[3];
  if (argc != 4)
  {
    std::cerr << "Invalid argc";
    return 1;
  }
  std::ifstream inputDataFromFile(inputFile);
  if (inputDataFromFile.is_open())
  {
    if (strcmp(argv[1], "1") == 0)
    {
      try
      {
        std::pair<size_t, size_t> arrayDimension = siobko::inputArrayDimension(inputDataFromFile);
        const size_t nlines = arrayDimension.first, ncols = arrayDimension.second;
        int array2D[nlines * ncols];
        siobko::inputArrayElems(array2D, nlines, ncols, inputDataFromFile, argv[1]);
        std::uint16_t taskResult = siobko::countLinesWithDiffElems(array2D, nlines, ncols);
        siobko::printValueToFile(taskResult, outputFile);
        inputDataFromFile.close();
        return 0;
      }
      catch (const std::runtime_error &err)
      {
        std::cerr << err.what();
        return 1;
      }
    }
    else if (strcmp(argv[1], "2") == 0)
    {
      int *matrix = nullptr;
      try
      {
        size_t matrixDimension = siobko::inputMatrixDimension(inputDataFromFile);
        size_t nlines = matrixDimension, ncols = matrixDimension;
        matrix = siobko::createMatrix(matrixDimension);
        siobko::inputArrayElems(matrix, nlines, ncols, inputDataFromFile, argv[1]);
        siobko::editMatrix(matrix, matrixDimension);
        siobko::printMatrixToFile(matrix, matrixDimension, outputFile);
        delete[] matrix;
        inputDataFromFile.close();
        return 0;
      }
      catch (const std::bad_alloc &err)
      {
        delete[] matrix;
        std::cerr << err.what();
        return 1;
      }
      catch (const std::runtime_error &err)
      {
        std::cerr << err.what();
        return 1;
      }
    }
    else
    {
      std::cerr << "Invalid task number";
      return 1;
    }
  }
  else
  {
    std::cerr << "Invalid input file name";
    return 1;
  }
}
