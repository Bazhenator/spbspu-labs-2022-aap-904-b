#ifndef PRINT_VALUES_TABLE_H
#define PRINT_VALUES_TABLE_H
#include "exponent.h"

namespace chupina {
  void printValuesRow(const double & xValue, const double & absError, const unsigned & termsAmount);
  void printValuesTable(const double & begin, const double & end, const double & step,
                        const unsigned & termsAmount, const double & absError);
}

#endif
