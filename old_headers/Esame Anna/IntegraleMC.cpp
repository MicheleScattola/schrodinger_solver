#include "IntegraleMC.h"

using namespace std;

IntegraleMC::IntegraleMC(unsigned int seed):m_gen(seed), m_errore(0.)
{};

double IntegraleMC::Media(const FunzioneBase& f, double a, double b, unsigned int N){

	m_N=N;
	double yi=0.;
	double somma=0.;

	for(int i=0;i<N;i++){

		yi=f.Eval(m_gen.Unif(a,b)); 
		somma=somma+yi;

	}

	return somma*(b-a)/double(N);

};

double IntegraleMC::HitMiss(const FunzioneBase& f, double a, double b, double max, unsigned int N){

	m_N=N;
	double x=0.;
	double y=0.;
	unsigned int Nhit;
	
	for(int i=0;i<N;i++){

		double x=m_gen.Unif(a,b);
		double y=m_gen.Unif(0,max);

		if(y<f.Eval(x)) Nhit++;

	}
				
	return (b-a)*max*double(Nhit)/double(N);

};


	