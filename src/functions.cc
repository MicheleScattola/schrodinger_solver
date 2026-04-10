#include "FunzioneVettoriale.h"

#include <iostream>
#include <vector>
#include <cmath>

//OSCILLATORE ARMONICO
OscillatoreArmonico::OscillatoreArmonico(double omega0) {
    m_omega0 = omega0 ;
};

vector<double> OscillatoreArmonico::Eval(double t, const vector<double> &x) const {
    
    vector<double> dxdt{ x[1], -pow(m_omega0,2)*x[0] };
	return dxdt;
};

//PENDOLO SEMPLICE
Pendolo::Pendolo(double L, double omega) {
    m_L = L ;
    m_omega = omega ;
};

vector<double> Pendolo::Eval(double t, const vector<double> &x) const {

    vector<double> dxdt{ x[1], - g/m_L * sin(m_omega * x[0]) } ;
    return dxdt ;
};

//OSCILLATORE FORZATO
OscillatoreForzato::OscillatoreForzato(double omega, double omega0, double alpha) {
    m_omega = omega ;
    m_omega0 = omega0 ;
    m_alpha = alpha ;
};

vector<double> OscillatoreForzato::Eval(double t, const vector<double> &x) const {

    vector<double> dxdt{ x[1], -pow(m_omega0,2) * x[0] - m_alpha * x[1] + sin(m_omega * t) } ;
    return dxdt;
};