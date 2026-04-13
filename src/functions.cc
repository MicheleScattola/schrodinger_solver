#include "../include/functions.h"

#include <cmath>
#include <iostream>
#include <vector>

// square well
SquareWell::SquareWell() {
  _width = 0.;
  _height = 0.;
}
SquareWell::SquareWell(float height, float width) {
  _height = height;
  _width = width;
}
float SquareWell::evaluate(const float &x) const {
  if (std::abs(x) > _width)
    return 0.0;
  else
    return _height;
}

// harmonic oscillator
HarmonicOscillator::HarmonicOscillator() { _omega = 0.; }
HarmonicOscillator::HarmonicOscillator(float omega) { _omega = omega; }
float HarmonicOscillator::evaluate(const float &x) const {
  return 0.5*_omega*_omega*x*x;
}

// Yukawa 

// WoodSaxon

// Morse

// kinetic functions
float FreeKinetic::evaluate(const float &x) const {
  return -HBAR*HBAR/(2.0*_mass);
}
