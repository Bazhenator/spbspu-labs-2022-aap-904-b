#include "manageArray.h"
#include <fstream>
#include <unordered_set>

int *siobko::createMatrix(size_t dimension)
{
  int *array = new int[dimension * dimension];
  return array;
}
int *siobko::editMatrix(int *matrix, size_t dimension)
{
  for (size_t i = 0; i < (dimension + 1) / 2; ++i)
  {
    for (size_t j = i; j < dimension - i; ++j)
    {
      matrix[i * dimension + j] = static_cast<int>(i + 1u);

      matrix[(dimension - i - 1) * dimension + j] = static_cast<int>(i + 1u);

      matrix[j * dimension + dimension - i - 1] = static_cast<int>(i + 1u);

      matrix[j * dimension + i] = static_cast<int>(i + 1u);
    }
  }
  return matrix;
}
std::uint16_t siobko::countLinesWithDiffElems(int *matrix, size_t nlines, size_t ncols)
{
  bool condition = {true};
  std::uint16_t amount = 0;
  std::unordered_set<int> diffElems;
  for (size_t i = 0; i < nlines; ++i)
  {
    condition = true;
    for (size_t j = 0; j < ncols; ++j)
    {
      diffElems.insert(matrix[i * ncols + j]);
      if (diffElems.size() != j + 1)
      {
        condition = false;
        break;
      }
    }
    if (condition)
    {
      amount++;
    }
    diffElems.clear();
  }
  return amount;
}
