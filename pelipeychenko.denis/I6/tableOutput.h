#ifndef TEYLOR_COLS_TABLEOUTPUT_H
#define TEYLOR_COLS_TABLEOUTPUT_H

#include "arctg.h"

namespace pelipeychenko {
  void printLine(double arg, double absError, int argsAmount);

  void printTable(double absError, int argsAmount,
                  double leftEdge, double rightEdge, double step);
}

#endif
