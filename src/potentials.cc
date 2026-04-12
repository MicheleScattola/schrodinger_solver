#include "../include/potentials.h"

#include <cmath>
#include <iostream>
#include <vector>

// square well
SquareWell::SquareWell() {
  _width = 0.;
  _height = 0.;
}
SquareWell::SquareWell(double height, double width) {
  _height = height;
  _width = width;
}
double SquareWell::evaluate(const double &x) const {
  if (std::abs(x) > _width)
    return 0.0;
  else
    return _height;
}

// harmonic oscillator
HarmonicOscillator::HarmonicOscillator() { _omega = 0.; }
HarmonicOscillator::HarmonicOscillator(double omega) { _omega = omega; }
double HarmonicOscillator::evaluate(const double &x) const {
  return 0.5*_omega*_omega*x*x;
}

// Yukawa 

// WoodSaxon

// Morse
