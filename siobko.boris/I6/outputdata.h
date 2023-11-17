#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H
#include <iostream>
namespace siobko
{
  void outputAnswerLine(std::ostream& out, const double& x, const double& absError, const size_t& numbersAmount);
  void outputAnswerTable(std::ostream& out, const double& step, const double& begin, const double& end,
    const size_t& numbersAmount, const double& absError);
}
#endif
