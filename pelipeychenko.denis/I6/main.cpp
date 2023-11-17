#include <iostream>
#include "tableOutput.h"

int main() {
  double absError, leftEdge, rightEdge, step;
  int argsAmount;
  std::cin >> absError >> argsAmount >> leftEdge >> rightEdge >> step;
  if (!std::cin || absError <= 0 || argsAmount <= 0 || leftEdge >= rightEdge || step <= 0) {
    std::cerr << "invalid input" << "\n";
    return 1;
  }

  try {
    pelipeychenko::printTable(absError, argsAmount, leftEdge, rightEdge, step);
  } catch (const std::exception &e) {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
