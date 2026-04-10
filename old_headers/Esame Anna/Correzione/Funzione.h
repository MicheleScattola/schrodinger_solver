#ifndef __Funzioni_h__
#define __Funzioni_h__

#include <iostream>
#include <cmath>
#include <iomanip>

class FunzioneBase{

public:

  virtual double Eval(double x) const = 0;

};

class Funzione: public FunzioneBase {

	public:

	Funzione(double c1,double c2, double a, double w, double f);

	~Funzione(){;};
		
	virtual double Eval(double x) const;

	double GetA() { return m_a; };
	double GetW() { return m_w; };
	double GetF() { return m_f; };
	double GetC1() { return m_c1; };
	double GetC2() { return m_c2; };

	void SetA(double a) { m_a=a; };
	void SetW(double w) { m_w=w; };
	void SetF(double f) { m_f=f; };
	void SetC1(double c1) { m_c1=c1; };
	void SetC2(double c2) { m_c2=c2; };

	private:
	double m_c1;
	double m_c2;
	double m_a;
	double m_f;
	double m_w;

};

#endif