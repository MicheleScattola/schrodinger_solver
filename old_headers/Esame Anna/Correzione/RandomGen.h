#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

#include <cmath>
#include <iostream>

using namespace std;

class RandomGen{

  public:
	
    RandomGen(unsigned int s);

    void SetA(unsigned int a) {m_a = a;};
    void SetC(unsigned int c) {m_c = c;};
    void SetM(unsigned int m) {m_m = m;};
		void SetS(unsigned int s) {m_s = s;};

		unsigned int GetA() {return m_a;};
    unsigned int GetC() {return m_c;};
		unsigned int GetM() {return m_m;};
		unsigned int GetS() {return m_s;};
		unsigned int GetSoriginal() {return m_soriginal;};

    double Rand();
    double Unif(double xmin, double xmax);
    double Exp(double mean);
    double Gauss(double mean, double sigma);
    double GaussAR(double mean, double sigma);

  private:
    unsigned int m_a, m_c, m_m;
    unsigned int m_s;
		unsigned int m_soriginal;
		
};

#endif
