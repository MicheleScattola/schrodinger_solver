#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "VectorOperations.h"
#include <cmath>

using namespace std;

// ===============================================================
// Classe astratta, restituisce la derivata nel punto x al tempo t
// ===============================================================

class FunzioneVettorialeBase {

public:
  virtual vector<double> Eval(double t, const vector<double> & x) const = 0;
};

// ===============================================================
// Caso fisico concreto
// ===============================================================

class OscillatoreArmonico : public FunzioneVettorialeBase {

public:

  OscillatoreArmonico(double omega0) { m_omega0 = omega0; };

  virtual vector<double> Eval(double t, const vector<double> &x) const {

    vector<double> dxdt {x[1], - (m_omega0*m_omega0*x[0])};

    return dxdt;
    };
    double GetOmega0 () {return m_omega0;};

		void SetOmega0 (double a) { m_omega0 = a;};
  

private:
  double m_omega0;
};


//pendolo
class PendoloReale : public FunzioneVettorialeBase{
  public:

	PendoloReale() {
		m_L = 1.;
	};
	PendoloReale(double L) {
		m_L = L;
	};
 
 
	virtual vector<double> Eval(double t, const vector<double> &x) const {
    
		double g = 9.80665;
		vector<double> dxdt { x[1], -(g/m_L)*sin(x[0]) };
		return dxdt;
	};
  
	double GetL () {
		return m_L;
	};
	void SetL (double a) {
		m_L = a;
	};

private:
 
  double m_L;

  
};

class OscillatoreForzato : public FunzioneVettorialeBase {
  public:

  OscillatoreForzato(double omega0, double alpha, double A, double omega){
    m_omega0 = omega0;
    m_alpha = alpha;
    m_omega = omega;
    m_A = A;
  };

  double GetOmega0 () {
		return m_omega0;
	};
	void SetOmega0 (double a) {
		m_omega0 = a;
	};
  double GetAlpha () {
		return m_alpha;
	};
	void SetAlpha (double a) {
		m_alpha= a;
	};
  double GetOmega(){
		return m_omega;
	};
	void SetOmega (double a) {
		m_omega= a;
	};
  double GetA () {
		return m_A;
	};
	void SetA (double a) {
		m_omega= a;
	};



  virtual vector<double> Eval(double t, const vector<double> &x) const {
    
		vector<double> dxdt { x[1], -(m_omega0*m_omega0)*x[0]-m_alpha*x[1]-sin(m_omega*t) };
		return dxdt;
	};

  private:
 
  double m_omega0;
  double m_alpha;
  double m_omega;
  double m_A;

};

///////////////////////////////////////////////////////////////////////////////
//esame
class OscillatoreSmorzato : public FunzioneVettorialeBase {
  public:

  OscillatoreSmorzato() {
    m_a = 1.;
    m_b = 5.;
    m_c = 6.;
  };

  OscillatoreSmorzato(double a, double b, double c) {
    m_a = a;
    m_b = b;
    m_c = c;
  };

  double GetA () {
		return m_a;
	};
	void SetA (double a) {
		m_a = a;
	};
  double GetB () {
		return m_b;
	};
	void SetB (double a) {
		m_b = a;
	};
  double GetC(){
		return m_c;
	};
	void SetC (double a) {
		m_c = a;
	};



  virtual vector<double> Eval(double t, const vector<double> &x) const {
    
		vector<double> dxdt { x[1], -m_c*x[0] - m_b*x[1] };
		return dxdt;
	};

  private:
 
  double m_a;
  double m_b;
  double m_c;

};



// ===============================================================
// Classe astratta per un integratore di equazioni differenziali
// ===============================================================

class EquazioneDifferenzialeBase {
public:
   virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const = 0;
};

// ===============================================================
// Integratore concreto, metodo di Eulero
// ===============================================================

class Eulero : public EquazioneDifferenzialeBase {
public:

  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const {

    return x+(f->Eval(t,x))*h;

  };
};


class RungeKutta : public EquazioneDifferenzialeBase {
public:

  vector<double> Passo(double t, const vector<double> &x, double h, FunzioneVettorialeBase *f) const {

   vector<double> k1 = f->Eval(t, x);
   vector<double> k2 = f->Eval(t+h/2., x+k1*h/2.);
   vector<double> k3 = f->Eval(t+h/2., x+k2*h/2.); 
   vector<double> k4 = f->Eval(t+h, x+k3*h);
   return x + (k1+2.*k2+2.*k3+k4)*(h/6);
    
    
  };
};

#endif // __EquazioniDifferenziali_h__
