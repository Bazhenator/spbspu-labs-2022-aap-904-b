#include <iostream>
#include <cstring>
#include "logic.h"

int main(int argc, char * argv[])
{
  if (argc != 4) {
    std::cerr << "Incorrect amount of CML args\n";
    return 2;
  }
  std::ifstream fin(argv[2]);
  size_t nRow, nColumn;
  fin >> nRow >> nColumn;
  if (!fin) {
    std::cerr << "Incorrect data";
    return 1;
  }
  const char doStatic[] = "1";
  const char doDynamic[] = "2";
  size_t answer = 0;
  if (!strcmp(doStatic, argv[1])) {
    if (nRow * nColumn > 1000) {
      std::cerr << "Incorrect size";
      return 1;
    }
    int matrix[nRow*nColumn];
    try {
      chupina::fillMatrix(fin, matrix, nRow, nColumn);
      answer = chupina::countRowsWithRepetitiveEls(matrix, nRow, nColumn);
    } catch (const std::runtime_error & e) {
      std::cout << e.what() << '\n';
      return 1;
    }
  } else if (!strcmp(doDynamic, argv[1])) {
    int * matrix = nullptr;
    if (nRow * nColumn != 0) {
      try {
        matrix = new int[nRow * nColumn];
        chupina::fillMatrix(fin, matrix, nRow, nColumn);
        answer = chupina::getRowNumWithLongestSubstring(matrix, nRow, nColumn);
      } catch (const std::bad_alloc & e) {
        std::cout << e.what() << '\n';
        return 1;
      } catch (const std::runtime_error & e) {
        std::cout << e.what() << '\n';
        delete [] matrix;
        return 1;
      }
    }
    delete [] matrix;
  }
  std::ofstream fout(argv[3]);
  fout << answer;
  return 0;
}
