#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include "FunzioneBase.h"
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TGraph.h"

#include <iostream>

using namespace std;

// Generic integrator

class Integral {

 public:
  
  Integral (double , double );
  virtual ~Integral() {;} ;

  virtual double Integra(unsigned int nstep, FunzioneBase& f) = 0;
  virtual double Integra(double prec, FunzioneBase& f) = 0;
  virtual double Error( unsigned int nstep, FunzioneBase& f) = 0;
  virtual void Error_Graph(FunzioneBase&) = 0;

 protected:

  void checkInterval (double a, double b){
		m_a = min(a,b);
		m_b = max(a,b);
		if ( a>b ) m_sign = -1;
		else m_sign = 1;
  }

  unsigned int m_nstep;
  double m_a, m_b;
  double m_sum, m_integral, m_h;
  int m_sign;
};

// Midpoint method

class Midpoint : public Integral {

 public:

  Midpoint (double a, double b) : Integral (a,b){;};
  ~Midpoint() {;} ;

  virtual double Integra(unsigned int , FunzioneBase&) override;
  virtual double Integra(double prec, FunzioneBase& f) override;

  virtual double Error(unsigned int, FunzioneBase&);
  
  virtual void Error_Graph(FunzioneBase&);

};

// Simpson method

class Simpson : public Integral {

  public:

  Simpson (double a, double b) : Integral (a,b){;};
  ~Simpson(){;} ;

  virtual double Integra(unsigned int, FunzioneBase&) override;
  virtual double Integra(double prec, FunzioneBase& f) override;

  virtual double Error(unsigned int, FunzioneBase&);

  virtual void Error_Graph(FunzioneBase&);
};


// Metodi trapezoidi

class Trapezi : public Integral {

  public:

  Trapezi (double a, double b) : Integral (a,b){;};
  ~Trapezi(){;} ;

  virtual double Integra(double, FunzioneBase&) override ;
  virtual double Integra(unsigned int nstep, FunzioneBase& f) override;
  virtual double Error(unsigned int nstep, FunzioneBase& f);
  virtual void Error_Graph(FunzioneBase& f);
};

#endif // __INTEGRAL_H__
