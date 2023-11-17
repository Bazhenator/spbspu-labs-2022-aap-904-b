#include "manageData.h"
#include <fstream>
#include <iostream>

void siobko::printValueToFile(std::uint16_t value, const char *outputfile)
{
  std::ofstream fout(outputfile);
  if (fout.is_open())
  {
    fout << value;
    fout.close();
  }
  else
  {
    throw std::runtime_error("invalid output file name");
  }
}
void siobko::printMatrixToFile(int *matrix, size_t dimension, const char *outputFile)
{
  std::ofstream fout(outputFile);
  if (fout.is_open())
  {
    for (size_t i = 0; i < dimension; ++i)
    {
      for (size_t j = 0; j < dimension; ++j)
      {
        fout << matrix[i * dimension + j] << " ";
      }
      fout << '\n';
    }
    fout.close();
  }
  else
  {
    delete[] matrix;
    throw std::runtime_error("invalid output file name");
  }
}
size_t siobko::inputMatrixDimension(std::ifstream &InputDimension)
{
  size_t dimension;
  InputDimension >> dimension;
  if (InputDimension.fail())
  {
    throw std::runtime_error("Input Dimension error");
  }
  return dimension;
}
std::pair<size_t, size_t> siobko::inputArrayDimension(std::ifstream &InputDimension)
{
  size_t nlines, ncols;
  InputDimension >> nlines >> ncols;
  if (InputDimension.fail())
  {
    throw std::runtime_error("Input error");
  }
  return {nlines, ncols};
}

void siobko::inputArrayElems(int *array, size_t nlines, size_t ncols, std::ifstream &InputElem, const char *taskNumber)
{
  for (size_t i = 0; i != nlines; ++i)
  {
    for (size_t j = 0; j != ncols; ++j)
    {
      InputElem >> array[i * ncols + j];
      if (InputElem.fail() || (InputElem.eof() && strcmp(taskNumber, "2") == 0))
      {
        if (strcmp(taskNumber, "2") == 0)
        {
          delete[] array;
        }
        throw std::runtime_error("Input elem error");
      }
    }
  }
}
