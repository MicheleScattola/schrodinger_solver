#ifndef __INTEGRALMC_H__
#define __INTEGRALMC_H__

#include "RandomGen.h"
#include "FunzioneBase.h"
#include <cmath>

class IntegralMC {

	public:

		IntegralMC(unsigned int seed=1);
		~IntegralMC() { ; };

		double IntegralAVE(const FunzioneBase& f, double a, double b, unsigned int N);
		double IntegralHoM(const FunzioneBase& f, double a, double b, double max, unsigned int N);

		void SetN(unsigned int N) { m_N=N; };
		void SetErrore(double err) { m_errore=err; };

		unsigned int GetN() { return m_N; };
		double GetErrore() { return m_errore; };

	private:

		unsigned int m_N;
		double m_errore;
		RandomGen m_gen;

};

#endif // __INTEGRALMC_H__