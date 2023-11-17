#ifndef MATRIXPROJ_MATRIX_H
#define MATRIXPROJ_MATRIX_H

#include <cstddef>

namespace pelipeychenko {
  struct dynamicMatrix {
    dynamicMatrix();

    ~dynamicMatrix();

    void fillMatrixFromFile(const char *argc[]);

    bool checkIfLess(size_t row, size_t col, size_t compareRow, size_t compareCol) const;

    bool checkIfLocalMin(size_t row, size_t col) const;

    int countLocalMins() const;

    size_t rows_;
    size_t cols_;
    int *data_;
  };

  void fillFromFileStaticMatrix(int *matrix, size_t &rows,
                                size_t &cols, const char *argc[]);

  int countRowsWithNull(const int *matrix, size_t rows, size_t cols);

  void writeOutput(int result, const char *argc[]);
}

#endif
