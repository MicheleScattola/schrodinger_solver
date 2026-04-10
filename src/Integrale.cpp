#include "FunzioneBase.h"
#include "Integrale.h"
#include <iostream>

using namespace std;

// Generic integrator

Integral::Integral (double a, double b){
    checkInterval (a,b);
    m_nstep = 0;
    m_h = 0; 
    m_sum = 0;
    m_integral =0;
  };

// ==========================================================================================
// MIDPOINT

double Midpoint::Integra(double prec, FunzioneBase& f) { return 0; };

double Midpoint::Integra(unsigned int nstep, FunzioneBase& f) {
		if (nstep==0) { cout << "Error, number of step is negative" << endl; exit(-1); };
		m_nstep = nstep;
		m_h = (m_b - m_a)/m_nstep;

		m_sum = 0;
		for (unsigned int i=1; i<m_nstep; i++) {
			m_sum += f.Eval( m_a + (i+0.5)*m_h ); //errore in (i+0.5*m_h) ?
		}
		
		m_integral = m_sign*m_sum*m_h ;
		
		return m_integral;
  };

double Midpoint::Error(unsigned int nstep, FunzioneBase& f) {

  return 4.*abs(Integra(2.*nstep,f)-Integra(nstep,f))/3. ;
};

void Midpoint::Error_Graph(FunzioneBase& f){
	TApplication app(0,0,0);
	TCanvas can1;
	can1.cd();
	can1.SetLogy(1);
	can1.SetLogx(1);
	TGraph errore;

	for(int i=1; i<=8; i++){
		errore.SetPoint( i-1, pow(10,i), Error( pow(10,i), f ) );
	};
	errore.SetTitle("Precisione del metodo di Midpoint; Passo h; Errore");
    errore.GetXaxis()->CenterTitle();
    errore.GetYaxis()->CenterTitle();
	errore.SetLineWidth(2);
    errore.SetLineColor(kRed);
	errore.SetMarkerStyle(kFullSquare);
	errore.Draw("ALP");
	app.Run();
};


// ==========================================================================================
// SIMPSON

double Simpson::Integra(double prec, FunzioneBase& f) { return 0; };

double Simpson::Integra(unsigned int nstep, FunzioneBase& f) {
 	//Controllo che il numero di passi richiesto sia pari
	if (nstep%2 != 0){
		cout << "N. of steps must be even for Simpson method" << endl;
		return 0;
	};
	m_nstep = nstep;
	m_h = (m_b - m_a)/m_nstep;
 

	double m_sum = 1./3. *  f.Eval(m_a);
	for (unsigned int i = 1; i < nstep; i++){
		if( i%2 !=0 )
			m_sum += 4./3. * f.Eval(m_a + i * m_h);
		else if( i%2 == 0 )
			m_sum += 2./3. * f.Eval(m_a + i * m_h);
	};
	 m_integral = ( m_sum + 1./3. * f.Eval(m_b) ) * m_h;

   return m_integral;
};

double Simpson::Error(unsigned int nstep, FunzioneBase& f) {

  return 16.*abs(Integra(2*nstep,f)-Integra(nstep,f))/15. ;
};

void Simpson::Error_Graph(FunzioneBase& f){
	TApplication app(0,0,0);
	TCanvas can2;
	can2.cd();
	can2.SetLogy(1);
	can2.SetLogx(1);
	TGraph errore;

	for(int i=1; i<=8; i++){
		errore.SetPoint( i-1, pow(10,i), Error( pow(10,i), f ) );
	};
	errore.SetTitle("Precisione del metodo di Simpson; Numero di passi; Errore");
    errore.GetXaxis()->CenterTitle();
    errore.GetYaxis()->CenterTitle();
	errore.SetLineWidth(2);
    errore.SetLineColor(kBlue);
	errore.SetMarkerStyle(kFullSquare);
	errore.Draw("ALP");
	app.Run();
};


// ==========================================================================================
// TRAPEZI
double Trapezi::Integra(unsigned int nstep, FunzioneBase& f) { return 0; };

double Trapezi::Integra(double prec, FunzioneBase& f) {

	double N = 10000.; // mumero massimo di passi, il ciclo non conitnua all'infinito

	double sum_0 = 0.5 * ( f.Eval(m_a) + f.Eval(m_b) );
	double I_0 = sum_0 * (m_b - m_a);
	double sum_1 = sum_0 + f.Eval( 0.5 * (m_a + m_b) );
	double m_integral = sum_1 * (m_b - m_a) * 0.5;

	for (int i=2; i<N; i++) {
		for(int k=1; k<=pow(2,i); k+=2) {
			sum_1 += f.Eval( m_a + k*(m_b + m_a)/pow(2.,i) );
		};
		I_0 = m_integral;
		m_integral = sum_1 * (m_b - m_a) / pow(2.,i);
		if ( abs(m_integral - I_0) <= prec ) {return m_sign * m_integral;} ;

	};

	return m_sign * m_integral;
};

double Trapezi::Error(unsigned int nstep, FunzioneBase& f) {return 0 ;} ;
void Trapezi::Error_Graph(FunzioneBase& f) {;} ;