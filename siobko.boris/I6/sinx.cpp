#include "sinx.h"

siobko::Sinx::Sinx(double x) : x(x), originalX(x)
{
  if (std::abs(x) >= 1)
  {
    throw std::runtime_error("Invalid input");
  }
}
long double siobko::Sinx::operator()()
{
  long double sinx = factorial / x;
  x *= originalX * originalX;
  factorial *= (it + 1u) * (it + 2u);
  it += 2u;
  return sinx;
}
bool siobko::checkAccuracy(long double sinx, const double& absError)
{
  return sinx > absError;
}
long double siobko::calculateSinFunction(const double& absError, const double& x, const size_t& numberAmount)
{
  siobko::Sinx sin(x);
  long double sinFunction = 0.0, temp;
  for (size_t i = 0u; i < numberAmount - 1u; ++i)
  {
    temp = (i % 2u == 0u ? 1 : -1) * sin();
    if (siobko::checkAccuracy(temp, absError))
    {
      throw std::runtime_error("The accuracy of the calculation has not been achieved.");
    }
    sinFunction += temp;
  }
  return sinFunction;
}
