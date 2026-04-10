#include "Integral.h"

double Trapezio::Integra(unsigned int nstep, FunzioneBase& f){
		if (nstep==0) {
			cout << "Errore: <nstep> negativo!";
			exit(-1);
		}

		m_nstep=nstep;
		m_h=(m_b-m_a)/(m_nstep);

		double fa=f.Eval(m_a);
		double fb=f.Eval(m_b);

		m_sum=1./2.*m_h*(fa+fb);

		for(int i=1;i<nstep;i++) {

			double x_i=m_a+i*m_h;
			double f_i=f.Eval(x_i);

			m_sum=m_sum+f_i*m_h;

		}

		m_integral=m_sign*m_sum;

		return m_integral;

  };

	double Trapezio::Integra(double prec, FunzioneBase& f) {
		if (prec<=0) {
			cout << "Errore: <prec> negativo!";
			exit(-1);
		}
	
	double N=10E7; //numero massimo di passi
		
	double fa=f.Eval(m_a);
	double fb=f.Eval(m_b);

	double sum0=(fa+fb)/2.;
	double I0=sum0*(m_b-m_a);
	double sum1=sum0+f.Eval((m_a+m_b)/2);
	double I1=sum1*(m_b-m_a)/2;

	for(int i=2; i<N; i++){
		
		for(int j=1; j<=pow(2,i); j=j+2){
			sum1=sum1+f.Eval(m_a+j*(m_b+m_a)/pow(2,i));
		};

		I0=I1;
		I1 = sum1 * (m_b-m_a) / pow(2,i);

		if (4./3.*(abs(I1 - I0)) <= prec) {
			return m_sign*I1;
		};

		m_nstep=pow(2,i);
		
	};

	return m_sign*I1;
	
	};


	