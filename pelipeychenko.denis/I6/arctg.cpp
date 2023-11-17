#include "arctg.h"
#include <iostream>

pelipeychenko::ArctgCalculator::ArctgCalculator(const double absError, const int argsAmount, const double arg) :
  arg_(arg),
  absError_(absError),
  argsAmount_(argsAmount),
  degreeArg_(1.0 / arg),
  number_(-1),
  sign_(-1) {
  if (!(arg < 1 && arg > -1)) {
    throw std::out_of_range("arg must be double between -1 and 1");
  }
}

double pelipeychenko::ArctgCalculator::operator()() {
  sign_ *= -1;
  degreeArg_ *= arg_ * arg_;
  number_ += 2;
  return sign_ * degreeArg_ / number_;
}

double pelipeychenko::ArctgCalculator::calculateArctg() {
  double result = 0.0;
  for (int arg = 0; arg < argsAmount_; arg++) {
    result += operator()();
  }
  if (std::abs(operator()()) > absError_) {
    throw std::logic_error("can't reach accuracy");
  }
  return result;
}
