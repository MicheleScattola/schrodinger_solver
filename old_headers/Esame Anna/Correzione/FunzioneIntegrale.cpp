#include "FunzioneIntegrale.h"

FunzioneIntegrale::FunzioneIntegrale(double x0, double prec, FunzioneBase* f, Integral* i){
	m_x0=x0;
	m_prec=prec;
	m_f=f;
	m_i=i;

}

double FunzioneIntegrale::Eval(double x) const {

	return i->Integra(m_x0,x,m_f,m_prec);
	
}