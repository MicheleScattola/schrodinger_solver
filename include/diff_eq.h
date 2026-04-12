#ifndef __DIFF_EQ__
#define __DIFF_EQ_

#include "potentials.h"
#include <vector>

class differentialEquation {
public:
  virtual vector<double> Step() const = 0;
};

class RungeKutta : public differentialEquation {};

class Numerov : public differentialEquation {};

#endif __DIFF_EQ__
