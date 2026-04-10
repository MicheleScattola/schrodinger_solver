#ifndef __PRISMA_H__
#define __PRISMA_H__

#include "RandomGen.h"

class EsperimentoPrisma {

    public:

    EsperimentoPrisma();
    ~EsperimentoPrisma(){;};

    void Esegui();
    void Analizza();

    double getAmis(){ return m_A_misurato; };
	double getBmis() { return m_B_misurato; };      
	double getN1mis() { return m_n1_misurato; };
	double getN2mis() { return m_n2_misurato; };
	double getD1mis() { return m_dm1_misurato; };
	double getD2mis() { return m_dm2_misurato; };   
	double getTh0mis() { return m_th0_misurato; };
	double getTh1mis() { return m_th1_misurato; };   
	double getTh2mis() { return m_th2_misurato; };

	double getAinput() { return m_A_input; };
	double getBinput() { return m_B_input; };      
	double getN1input() { return m_n1_input; };
	double getN2input() { return m_n2_input; };
	double getD1input() { return m_dm1_input; };
	double getD2input() { return m_dm2_input; };   
	double getTh0input() { return m_th0_input; };
	double getTh1input() { return m_th1_input; };   
	double getTh2input() { return m_th2_input; };

	double getLambda1() { return m_lambda1; };
	double getLambda2() { return m_lambda2; };
	double getAlpha() { return m_alpha; };
	double getSigma() { return m_sigmat; };

	void setLambda1( double l1 ) { m_lambda1=l1; };
	void setLambda2( double l2 ) { m_lambda2=l2; };
	void setAlpha( double a ) { m_alpha=a; };
	void setSigma( double s ) { m_sigmat=s; };

    private:

    RandomGen m_rgen;

    double m_lambda1, m_lambda2, m_alpha, m_sigmat;

    double m_A_misurato, m_A_input;
    double m_B_misurato, m_B_input;
    double m_n1_misurato, m_n1_input;
    double m_n2_misurato, m_n2_input;
    double m_dm1_misurato, m_dm1_input;
    double m_dm2_misurato, m_dm2_input;
    double m_th0_misurato, m_th0_input;
    double m_th1_misurato, m_th1_input;
    double m_th2_misurato, m_th2_input;

};

#endif