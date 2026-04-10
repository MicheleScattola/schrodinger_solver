#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include <iostream>
#include <vector>
#include <cmath>
#include "VectorOperations.h"

//Classe astratta per la restituzione della derivata prima valutata nel punto x
class FunzioneVettorialeBase {

    public:

    virtual vector<double> Eval(double, const vector<double> &) const = 0;
};

class OscillatoreArmonico : public FunzioneVettorialeBase {

    public:

    OscillatoreArmonico(double) ;
    virtual vector<double> Eval(double, const vector<double> &) const;

    private:
    double m_omega0 ;
};

class Pendolo : public FunzioneVettorialeBase {

    public:

    Pendolo(double, double);
    virtual vector<double> Eval(double, const vector<double> &) const;

    private:
    double m_omega, m_L ;
    double g = 9.806 ;
};

class OscillatoreForzato : public FunzioneVettorialeBase {

    public:

    OscillatoreForzato(double, double, double) ;
    virtual vector<double> Eval(double, const vector<double> &) const;
    double GetA() const {return m_alpha;};
    void SetOmega(double omega) {m_omega = omega;};
    void SetOmega0(double omega0) {m_omega0 = omega0;};
    void SetAlpha(double alpha) {m_alpha = alpha;};

    private:
    double m_omega, m_omega0, m_alpha;
};

#endif // __FUNCTIONS__