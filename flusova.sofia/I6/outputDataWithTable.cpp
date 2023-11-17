#include "outputDataWithTable.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include "taylorSeriesSinH.h"

void flusova::printCurrentLine(double taylorSeriesRes, double curArg) {
  std::cout << taylorSeriesRes << std::setw(30) << std::sinh(curArg) <<
    std::right << std::setw(40)<< taylorSeriesRes - std::sinh(curArg) << std::right << '\n';
}
void flusova::outputDataWithTable(const double rightEdge, double leftEdge, const int numberMax,
  const double absError, double step) {
  std::cout << "TS res:" << std::setw(35) << "sinh(x) res:" <<  std::setw(35) << "Difference:" << '\n';
  for (; leftEdge <= rightEdge; leftEdge += step) {
    printCurrentLine(calculateSinHLine(numberMax, absError, leftEdge), leftEdge);
  }
}
