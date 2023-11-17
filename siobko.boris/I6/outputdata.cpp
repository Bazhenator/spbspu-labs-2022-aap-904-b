#include "outputdata.h"
#include <iomanip>
#include "sinx.h"

void siobko::outputAnswerLine(std::ostream& out, const double& x, const double& absError, const size_t& numbersAmount)
{
  out << std::setw(15) << x << std::setw(15) << siobko::calculateSinFunction(absError, x, numbersAmount)
    << std::setw(15) << std::sin(x) << '\n';
}
void siobko::outputAnswerTable(std::ostream& out, const double& step, const double& begin, const double& end,
  const size_t& numbersAmount, const double& absError)
{
  std::cout << std::setw(15) << 'x' << std::setw(15) << "My sinx" << std::setw(15) << "Default Sinx" << '\n';
  for (double x = begin + step; x < end; x += step)
  {
    siobko::outputAnswerLine(out, x, absError, numbersAmount);
  }
}
