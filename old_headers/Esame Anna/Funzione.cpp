#include "Funzione.h"

Funzione::Funzione(double c1,double c2, double a, double w, double f){
	m_c1=c1;
	m_c2=c2;
	m_a=a;
	m_w=w;
	m_f=f;
}

double Funzione::Eval(double x) const {

	double a=m_c1*exp(m_c2*x);
	double b=pow(x,3);
	double c=m_a*cos(m_w*x+m_f);
	
	return (a*b*c)/(x+1); 
}