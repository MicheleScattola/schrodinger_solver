#ifndef __FunzioneIntegrale_h__
#define __FunzioneIntegrale_h__

#include "Funzione.h"
#include "Integral.h"

class FunzioneIntegrale: public FunzioneBase {

	public:
	
	//costruttore con punto base x0
	FunzioneIntegrale(double x0);

	FunzioneIntegrale(double x0, double prec, FunzioneBase* f, Integral* i);

	//implemento metodo di calcolo della funzione nel punto
	virtual double Eval(double x) const;

	void SetX0(double x0) { m_x0=x0; };
	double GetX0() { return m_x0; };
	void SetP(double p){ m_prec=p; };
	
	private:
		double m_x0;
		double m_prec
		FunzioneBase* m_f;
		Integral* m_i;

};

#endif