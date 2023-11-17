#ifndef TAYLORS_ROW_H
#define TAYLORS_ROW_H

#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iomanip>

namespace ponomarev {
  double calculateTaylorsRow(double x, const double absError, std::size_t numberMax);
  template <class Type>
  void outputRow(std::initializer_list<Type> list)
  {
    for (Type elem: list) {
      std::cout << std::left << std::setw(25) << elem;
    }
    std::cout << std::setw(0) << std::endl;
  }
}

#endif
