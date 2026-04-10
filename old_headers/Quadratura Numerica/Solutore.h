#ifndef __Solutore_h__
#define __Solutore_h__

#include "FunzioneBase.h"

class Solutore {
    public:
    virtual ~Solutore() { };
    void SetMin(double a) {m_min = a;};
    void SetMax(double b) {m_max = b;};
    double GetMin() {return m_min;};
    double GetMax() {return m_max;};
    void SetPrecision(double prec) {m_prec = prec;};
    double GetPrecision() {return m_prec;};
    void SetNMax(double nmax) {m_nmax = nmax;};
    double GetNMax() {return m_nmax;};
    void SetNIterations(unsigned int niterations) {m_niterations = niterations;};
    double GetNIterations() {return m_niterations;};

    virtual double CercaZeri(double, double, const FunzioneBase& f,double,unsigned int)=0;
    virtual double CercaZeri(double, double, const FunzioneBase* f,double,unsigned int)=0;
    virtual bool Trovato()=0;
    virtual double Incertezza()=0;

    protected:

    double m_min, m_max;
    double m_prec;
    unsigned int m_nmax, m_niterations;
    bool m_trovato;
    double m_incertezza;

};

class Bisezione : public Solutore {
    public:
    Bisezione();
    ~Bisezione() { };
    
    virtual double CercaZeri(double,double,const FunzioneBase& f,double,unsigned int);
    virtual double CercaZeri(double,double,const FunzioneBase* f,double,unsigned int);

    virtual bool Trovato();
    virtual double Incertezza();

    private:

};

#endif