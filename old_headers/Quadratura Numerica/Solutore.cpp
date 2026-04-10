#include "Solutore.h"
#include <iostream>

using namespace std;

//SOLUTORE

// BISEZIONE
Bisezione::Bisezione() {
    m_min = 0;
    m_max = 0;
    m_prec = 0;
    m_nmax = 0;
};

//CercaZeri Reference
double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase& f, double prec = 0.001, unsigned int nmax = 100) {
    Segno sign;
    SetNIterations(0);
    SetPrecision(prec);
    SetNMax(nmax);

    // set di xmin e xmax iniziali
    if (xmin < xmax) {
        SetMin(xmin); SetMax(xmax);
    } else {
        SetMin(xmax); SetMax(xmin);
    }
    //ciclo principale con arresto sulla precisione
    double fa = f.Eval(GetMin());
    double fb = f.Eval(GetMax());
    m_trovato = true;
    while ( abs(GetMax()-GetMin()) > GetPrecision() ) {
        double c = 0.5*(GetMin()+GetMax());
        double fc = f.Eval(c);
        if ( GetNIterations() > GetNMax() ) {
            m_trovato = false;
            break; }
        m_niterations++ ;
        if ( sign.Eval(fa)*sign.Eval(fc) <= 0 ) {
            SetMax(c); fb=fc;
        } else if ( sign.Eval(fb)*sign.Eval(fc) <= 0 ) {
            SetMin(c); fa=fc;
        } else return 0.;
    }

    m_incertezza = abs(GetMin()-GetMax());

    return 0.5*(GetMin()+GetMax());
};
//CercaZeri Pointer
double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase* f, double prec = 0.001, unsigned int nmax = 100) {
    Segno sign;
    SetNIterations(0);
    SetPrecision(prec);
    SetNMax(nmax);

    // set di xmin e xmax iniziali
    if (xmin < xmax) {
        SetMin(xmin); SetMax(xmax);
    } else if (xmin > xmax) {
        SetMin(xmax); SetMax(xmin);
    } else { cout << "Intervallo non valido" << endl; exit(-1);
        };
    //ciclo principale con arresto sulla precisione
    double fa = f->Eval(GetMin());
    double fb = f->Eval(GetMax());
    m_trovato = true;

    while ( abs(GetMax()-GetMin()) > GetPrecision() ) {
        if ( GetNIterations() > GetNMax() ) {
            m_trovato = false;
            break;
        }
        m_niterations++ ;
        double c = 0.5*(GetMin()+GetMax());
        double fc = f->Eval(c);
        if ( sign.Eval(fa)*sign.Eval(fc) <= 0 ) {
            SetMax(c); fb=fc;
        } else if ( sign.Eval(fb)*sign.Eval(fc) <= 0 ) {
            SetMin(c); fa=fc;
        } else return 0.;
    }

    m_incertezza = abs(GetMin()-GetMax());

    return 0.5*(GetMin()+GetMax());
};

//virtual bool trovato e double incertezza

bool Bisezione::Trovato() { return m_trovato;};

double Bisezione::Incertezza() { return m_incertezza;};
