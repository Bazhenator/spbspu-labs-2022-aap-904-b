#ifndef OUTPUT_DATA_WITH_TABLE_H
#define OUTPUT_DATA_WITH_TABLE_H

namespace flusova {
  void printCurrentLine(double taylorSeriesRes, double curArg);
  void outputDataWithTable(const double rightEdge, double leftEdge,
                           const int numberMax, const double absError, double step);
}

#endif
