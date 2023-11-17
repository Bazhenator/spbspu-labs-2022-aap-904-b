#include "logic.h"
#include <iostream>
#include <limits>
#include <set>

const int MAX_INT = std::numeric_limits< int >::max();

void chupina::fillMatrix(std::ifstream & fin, int * matrix, const size_t & nRow, const size_t & nColumn)
{
  for (size_t i = 0; i < nRow; ++i) {
    for (size_t j = 0; j < nColumn; ++j) {
      fin >> matrix[nColumn * i + j];
      if (fin.fail()) {
        throw std::runtime_error("Integer expected");
      }
    }
  }
}
int areRepetElsInRow(const int * row, const size_t & nRow, const size_t & nColumn)
{
  std::set<int> setRow;
  for (size_t i = 0; i < nColumn; ++i) {
    setRow.insert(row[nRow + i]);
  }
  return !(setRow.size() == nColumn);
}
int chupina::countRowsWithRepetitiveEls(const int * matrix, const size_t & nRow, const size_t & nColumn)
{
  int answer = 0;
  int buf;
  for (size_t i = 0; i < nRow; ++i) {
    buf = areRepetElsInRow(matrix, nColumn * i, nColumn);
    if (MAX_INT - buf >= answer) {
      answer += buf;
    } else {
      throw std::runtime_error ("Answer is overflow");
    }
  }
  return answer;
}
int getMaxSubstringLengthInRow(const int * row, const size_t & nRow, const size_t & nColumn)
{
  int maxLength = 1;
  int buf = 1;
  for (size_t i = 1; i < nColumn; ++i) {
    if (row[i + nRow] != row[(i + nRow) - 1]) {
      maxLength = std::max(maxLength, buf);
      buf = 1;
    } else {
      if (MAX_INT - 1 >= buf) {
        buf++;
        maxLength = std::max(maxLength, buf);
      } else {
        throw std::runtime_error("Overflow");
      }
    }
  }
  return maxLength;
}
int chupina::getRowNumWithLongestSubstring(const int * matrix, const size_t & nRow, const size_t & nColumn)
{
  int length = 0;
  int rowNum, buf;
  for (size_t i = 0; i < nRow; ++i) {
    buf = getMaxSubstringLengthInRow(matrix, nColumn * i, nColumn);
    if (buf > length) {
      length = buf;
      rowNum = i + 1;
    }
  }
  return rowNum;
}
