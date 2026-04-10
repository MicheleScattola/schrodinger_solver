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

double mod(double x){

	if(x<0){
		return x*(-1.);
	} else {
		return x;
	}

};

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
	
	//metodo virtuale per la visualizzazione dell'errore commesso
	//virtual void ErrGraph(double real, double nstep, FunzioneBase& f) = 0;

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
 * Dichiarazione della classe figlia Midpoint in cui viene implementato
 * il metodo Integra che restitusice il valore dell'integrale
 * secondo la formula composta di Newton-Cotes del Midpoint 
 ***********************************************************************/

class Midpoint : public Integral {

 public:

  //costruttore di un oggetto della classe Midpoint
	Midpoint (double a, double b) : Integral (a, b){;};

  //implementazione del metodo Integra secondo Midpoint
	double Integra(unsigned int nstep, FunzioneBase& f) override {
		if (nstep==0) {
			cout << "Errore: <nstep> negativo!";
			exit(-1);
		}

		m_nstep=nstep;
		m_h=(m_b-m_a)/(m_nstep);

		m_sum=0.;

		for(int i=0;i<=(nstep-1);i++) {
			double x_i=m_a+(i+0.5)*m_h;
			double f_i=f.Eval(x_i);

			m_sum=m_sum+f_i*m_h;

		}

		m_integral=m_sign*m_sum;

		return m_integral;

  };

	//implementazione metodo per visualizzazione dell'errore commesso se si conosce il valore reale
	/*virtual void ErrGraph(double real, double nstep, FunzioneBase& f){

		TApplication app(0,0,0);
	  TCanvas can1;
  	can1.cd();
	  can1.SetLogy(1);

	  TGraph errore;

	  double Ir=real;
		double nmax_step=nstep;
	  int counter = 0;

    for(int i=1; i<=nmax_step; i++){
			errore.SetPoint(counter, i, abs(Integra(i,f)-Ir));
		  counter ++;
	  };

		errore.GetXaxis()->SetTitle("Numero di passi");
		errore.GetYaxis()->SetTitle("Errore");
		errore.SetTitle("Errore del metodo Midpoint al variare di nstep");
		errore.SetMarkerStyle(20);

		errore.Draw("ALP");
		app.Run();
		
  };*/

};

/***********************************************************************
 * Dichiarazione della classe figlia Simpson in cui viene implementato
 * il metodo Integra che restitusice il valore dell'integrale
 * secondo la formula composta di Newton-Cotes di Simpson 
 ***********************************************************************/

class Simpson : public Integral {

 public:

  //costruttore di un oggettod ella classe Simpson
	Simpson (double a, double b) : Integral (a, b){ ; };

  //implementazione del metodo Integra secondo Simpson
	double Integra(unsigned int nstep, FunzioneBase& f) override {

		if (nstep==0) {
			cout << "Errore: <nstep> negativo!";
			exit(-1);
		}

		if (nstep%2!=0) {

			cout << "Errore: <nstep> dispari non consentito con metodo di Simpson!" << endl;

			exit(-1);

		}

		m_nstep=nstep;
		m_h=(m_b-m_a)/(m_nstep);

		double fa=f.Eval(m_a);
		double fb=f.Eval(m_b);

		m_sum=1./3.*m_h*(fa+fb);

		for(int i=1; i<nstep;i++) {

			double x_i=m_a+i*m_h;
			double f_i=f.Eval(x_i);

			if(i%2==0) {
			  m_sum=m_sum+(2./3.)*m_h*f_i;
			} else {
				m_sum=m_sum+(4./3.)*m_h*f_i;
			}

		}

		m_integral=m_sign*m_sum;

		return m_integral;

  };

	//implementazione metodo per la visualizzazione dell'errore commesso se si conosce valore reale
	/*virtual void ErrGraph(double real, double nstep, FunzioneBase& f){

		TApplication app(0,0,0);
	  TCanvas can1;
  	can1.cd();
	  can1.SetLogy(1);

	  TGraph errore;

	  double Ir=real;
		double nmax_step=nstep;
	  int counter = 0;

    for(int i=2; i<=nmax_step; i=i+2){
			errore.SetPoint(counter, i, abs(Integra(i,f)-Ir));
		  counter ++;
	  };

		errore.GetXaxis()->SetTitle("Numero di passi");
		errore.GetYaxis()->SetTitle("Errore");
		errore.SetTitle("Errore del metodo Simpson al variare di nstep");
		errore.SetMarkerStyle(20);

		errore.Draw("ALP");
		app.Run();
		
  };*/
	
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
	virtual double Integra(unsigned int nstep, FunzioneBase& f) override {
		if (nstep==0) {
			cout << "Errore: <nstep> negativo!";
			exit(-1);
		}

		m_nstep=nstep;
		m_h=(m_b-m_a)/(m_nstep);

		double fa=f.Eval(m_a);
		double fb=f.Eval(m_b);

		m_sum=1./2.*m_h*(fa+fb);

		for(int i=1;i<nstep;i++) {

			double x_i=m_a+i*m_h;
			double f_i=f.Eval(x_i);

			m_sum=m_sum+f_i*m_h;

		}

		m_integral=m_sign*m_sum;

		return m_integral;

  };

	//implememtazione metodo per calcolo integrale secondo formula dei trapezoidi data la precisione
  double Integra(double prec, FunzioneBase& f) {
		if (prec<=0) {
			cout << "Errore: <prec> negativo!";
			exit(-1);
		}
	
	double N=10E7; //numero massimo di passi
		
	double fa=f.Eval(m_a);
	double fb=f.Eval(m_b);

	double sum0=(fa+fb)/2.;
	double I0=sum0*(m_b-m_a);
	double sum1=sum0+f.Eval((m_a+m_b)/2);
	double I1=sum1*(m_b-m_a)/2;

	for(int i=2; i<N; i++){
		
		for(int j=1; j<=pow(2,i); j=j+2){
			sum1=sum1+f.Eval(m_a+j*(m_b+m_a)/pow(2,i));
		};

		I0=I1;
		I1 = sum1 * (m_b-m_a) / pow(2,i);

		if (4./3.*(mod(I1 - I0)) <= prec) {
			return m_sign*I1;
		};

		m_nstep=pow(2,i);
		
	};

	return m_sign*I1;
	};

	/*virtual void ErrGraph(double real, double nstep, FunzioneBase& f){ 
		TApplication app(0,0,0);
	  TCanvas can1;
  	can1.cd();
	  can1.SetLogy(1);

	  TGraph errore;

	  double Ir=real;
		double nmax_step=nstep;
	  int counter = 0;

    for(unsigned int i=1; i<=nmax_step; i++){
			errore.SetPoint(counter, i, abs(Integra(i,f)-Ir));
		  counter ++;
	  };

		errore.GetXaxis()->SetTitle("Numero di passi");
		errore.GetYaxis()->SetTitle("Errore");
		errore.SetTitle("Errore del metodo Midpoint al variare di nstep");
		errore.SetMarkerStyle(20);

		errore.Draw("ALP");
		app.Run();

	};*/

};



#endif // __INTEGRAL_H__
