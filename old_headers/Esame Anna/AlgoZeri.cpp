#include "AlgoZeri.h"

using namespace std;

double sign(double x) {
	return (x==0.?0.:(x>0?1.:-1.));
};

Bisezione::Bisezione(){
	m_min=0;
	m_max=0;
	m_prec=0;	
	m_niterations=0;
};

double Bisezione::CercaZeri(double xmin, double xmax, const FunzioneBase* f, double prec){

	m_niterations=0;
	m_prec=prec;
	double a=0;
	double b=0;

	if( xmin<xmax ){

		a=xmin;
		b=xmax;

	} else if(xmin>xmax){

		a=xmax;
		b=xmin;

	} else {

		cout << "Intervallo non valido" << endl;
		exit(-1);

	}

	double fa=f->Eval(a);
	double fb=f->Eval(b);

	while( abs(b-a)>m_prec ){

		double c=0.5*(b+a);
		double fc=f->Eval(c);

		if( m_niterations>m_nmax ) break;

		m_niterations++;

		if( sign(fa)*sign(fc) <=0 ){

			b=c;
			fb=fc;

		} else {

			a=c;
			fa=fc;

		} 

	}

	return 0.5*(b+a);

};

