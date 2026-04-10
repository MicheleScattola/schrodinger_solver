#include "IntegralMC.h"
#include "RandomGen.h"
#include "FunzioneBase.h"

IntegralMC::IntegralMC(unsigned int seed):m_gen(seed), m_errore(0.)
{};

double IntegralMC::IntegralAVE(const FunzioneBase& f, double xmin, double xmax, unsigned int N){

	m_N=N;
	double sum=0.;

	for(int i=0;i<N;i++){

		sum+=f.Eval(m_gen.Unif(xmin,xmax)); 

	}

	return sum*(xmax-xmin)/double(N);

};

double IntegralMC::IntegralHoM(const FunzioneBase& f, double xmin, double xmax, double fmax, unsigned int N){

	double x=0.;
	double y=0.;
	unsigned int Nhit=0.;
	
	for(int i=0;i<N;i++){
		
	    x=m_gen.Unif(xmin,xmax);
	    y=m_gen.Unif(0,fmax);

		if(y<f.Eval(x)) Nhit++;

	}
				
	return (xmax-xmin)*fmax*Nhit/N;

};