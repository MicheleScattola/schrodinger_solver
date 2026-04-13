#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include <iostream>
#include <vector>

const float HBAR = 6.582119569e-16; // [eV . s]
const float M_PROTON = 938.28e6; // [MeV / c^2]
const float M_NEUTRON = 939.57e6; // [MeV / c^2]
const float M_ELECTRON = 0.510998950e6; // [MeV / c^2]
const float SPEED_C = 299792458; // [m / s]

class genericFunction {

public:
  virtual ~genericFunction() = default;
  virtual float evaluate(const float &x) const = 0; 
};

class SquareWell : public genericFunction {

public:
  SquareWell();
  SquareWell(float h, float w);
  void setHeight(float h) { _height = h; }
  void setWidth(float w) { _width = w; }
  float evaluate(const float &x) const override;

private:
  float _width;
  float _height;
};

class HarmonicOscillator : public genericFunction {

public:
  HarmonicOscillator();
  HarmonicOscillator(float w);
  void setOmega(float w) { _omega = w; }
  float evaluate(const float &x) const override;

private:
  float _omega;
};

class Yukawa : public genericFunction {};

class WoodSaxon : public genericFunction {};

class Morse : public genericFunction {};

// kinetic functions
class FreeKinetic : public genericFunction {

  public:
  FreeKinetic();
  FreeKinetic(float mass) {_mass = mass;};
  void setMass(float mass) {_mass = mass;};
  float evaluate(const float &x) const override;

  private:
  float _mass;
};

#endif // POTENTIALS