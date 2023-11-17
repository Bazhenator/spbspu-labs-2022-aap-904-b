#ifndef TEYLOR_COLS_ARCTG_H
#define TEYLOR_COLS_ARCTG_H

namespace pelipeychenko {
  class ArctgCalculator {
  public:
    ArctgCalculator(double absError, int argsAmount, double arg);

    double operator()();

    double calculateArctg();

  private:
    double arg_;
    double absError_;
    int argsAmount_;
    double degreeArg_;
    int number_;
    double sign_;
  };
}

#endif
