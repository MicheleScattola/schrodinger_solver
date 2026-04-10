#ifndef __POTENTIALS__
#define __POTENTIALS__

#include <vector>
#include <iostream>

// commento

class genericPotential {

    public:

    virtual std::vector<double> evalute(const std::vector<double> &x);
};

class SquareWell : public genericPotential{

};

class WoodSaxon : public genericPotential{


};

class Adiabatic : public genericPotential {

};

#endif //POTENTIALS