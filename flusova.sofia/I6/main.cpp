#include <iostream>
#include "outputDataWithTable.h"

int main() {
    int numberMax;
    std::cout << "Please, enter the start values: " << '\n';
    double leftEdge, rightEdge, absError, step;
    std::cin >> leftEdge >> rightEdge >> numberMax >> absError >> step;
    if (std::cin.fail())
    {
      std::cerr << "Incorrect data!" << '\n';
      return 1;
    }
    try {
      flusova::outputDataWithTable(rightEdge, leftEdge, numberMax, absError, step);
    } catch (...) {
      std::cout << "Error!" << '\n';
      return 1;
    }
    return 0;
}
