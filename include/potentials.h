#ifndef __POTENTIALS__
#define __POTENTIALS__

#include <iostream>
#include <vector>

class genericPotential {

public:
  virtual ~genericPotential() = default;
  virtual double evaluate(const double &x) const = 0; 
};

class SquareWell : public genericPotential {

public:
  SquareWell();
  SquareWell(double h, double w);
  void setHeight(double h) { _height = h; }
  void setWidth(double w) { _width = w; }
  double evaluate(const double &x) const override;

private:
  double _width;
  double _height;
};

class HarmonicOscillator : public genericPotential {

public:
  HarmonicOscillator();
  HarmonicOscillator(double w);
  void setOmega(double w) { _omega = w; }
  double evaluate(const double &x) const override;

private:
  double _omega;
};

class Yukawa : public genericPotential {};

class WoodSaxon : public genericPotential {};

class Morse : public genericPotential {};

#endif // POTENTIALS
