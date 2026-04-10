#ifndef __INTEGRALEMC_H__
#define __INTEGRALEMC_H__

#include <iostream>
#include <cmath>

#include "RandomGen.h"
#include "Funzione.h"

using namespace std;

class IntegraleMC {

	public:

		IntegraleMC(unsigned int seed=1);
		~IntegraleMC() { ; };

		double Media(const FunzioneBase& f, double a, double b, unsigned int N);
		double HitMiss(const FunzioneBase& f, double a, double b, double max, unsigned int N);

		void SetN(unsigned int N) { m_N=N; };
		void SetErrore(double err) { m_errore=err; };

		unsigned int GetN() { return m_N; };
		double GetErrore() { return m_errore; };

	private:

		unsigned int m_N;
		double m_errore;
		RandomGen m_gen;

};

#endif  //__INTEGRALEMC_H__