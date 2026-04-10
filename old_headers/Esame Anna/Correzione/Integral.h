#ifndef __INTEGRAL_H__
#define __INTEGRAL_H__

#include <iostream>
#include <cmath>

#include "Funzione.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TAxis.h"

using namespace std;

/*******************************************************************
 * Classe astratta per un generico solutore di intergrali Integral
 * definisce metodi che ogni algoritmo per risoluzione di integrali
 * deve implementare e delle funzioni di utilizzo generale.
 *******************************************************************/

class Integral {

 public:
  
  //costruttore che chiede in input estremi di intergazione e controlla il segno dell'integrale
	Integral (double a, double b){
		checkInterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral =0;
  }
	
	//distruttore
	~Integral(){ ; };

	//metodi per settare data membri protected
	void SetNstep(unsigned int x){ m_nstep=x; };
	void SetA(double x){ m_a=x; };
	void SetB(double x){ m_b=x; };
	void SetSum(double x){ m_sum=x; };
	void SetIntegral(double x){ m_integral=x; };
	void SetH(double x){ m_h=x; };
	void SetSign(int x){ m_sign=x; };

	//metodi per accedere ai data membri protected
	unsigned int GetNstep(){  return m_nstep; };
	double GetA(){ return m_a; };
	double GetB(){ return m_b; };
	double GetSum(){ return m_sum; };
	double GetIntegral(){ return m_integral; };
	double GetH(){ return m_h; };
	int GetSign(){ return m_sign; };

  //metodo virtuale puro che resituisce il valore dell'integrale di f
	virtual double Integra(unsigned int nstep, FunzioneBase& f) = 0;

 protected:

  //metodo per cattuarer il segno dell'integrale
	void checkInterval (double a, double b){
	  m_a=min(a,b);
		m_b=max(a,b);
		if(a>b) m_sign=-1;
		else m_sign=1;
  }

  unsigned int m_nstep; //numero sub intervalli 
  double m_a, m_b; //estremi dell'intervallo di integrazione
  double m_sum; //somma degli intergrali dei sottointervalli
	double m_integral; //valore dell'integrale
	double m_h; //passo
  int m_sign; //segno dell'integrale
};

/***********************************************************************
 * Dichiarazione della classe figlia Trapezoidi in cui viene implementato
 * il metodo Integra che restitusice il valore dell'integrale
 * secondo la formula composta di Newton-Cotes dei trapezoidi
 ***********************************************************************/

class Trapezio : public Integral {

 public:

  //costruttore oggetto della classe Trapezio
	Trapezio (double a, double b) : Integral (a, b){ ; };

	//implementazione metodo per calcolo integrale secondo algoritmo dei trapezoidi dato il numero di passi
	virtual double Integra(unsigned int nstep, FunzioneBase& f);

	//implememtazione metodo per calcolo integrale secondo formula dei trapezoidi data la precisione
  double Integra(double prec, FunzioneBase& f);

};

#endif // __INTEGRAL_H__
