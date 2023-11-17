#include "tableOutput.h"
#include <iostream>
#include <iomanip>
#include <cmath>

void pelipeychenko::printLine(const double arg, const double absError, const int argsAmount) {
  pelipeychenko::ArctgCalculator arctg(absError, argsAmount, arg);
  std::cout << std::left << std::setw(13) << arg << std::setw(15) << arctg.calculateArctg()
            << std::setw(15) << std::atan(arg) << "\n";
}

void pelipeychenko::printTable(const double absError, const int argsAmount,
                               const double leftEdge, const double rightEdge, const double step) {
  std::cout << std::left << std::setw(13) << "Arg" << std::setw(15) << "custom Atan"
            << std::setw(13) << "cmath Atan" << "\n";
  for (double arg = leftEdge + step; arg < rightEdge - step; arg += step) {
    printLine(arg, absError, argsAmount);
  }
}
