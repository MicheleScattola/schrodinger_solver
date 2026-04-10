#include <iostream>
#include <cmath>

#include "RandomGen.h"

using namespace std;

double Gaussiana(double x, double mean, double sigma){

	return 1/(sigma*sqrt(2*M_PI))*exp(-0.5*(x-mean)*(x-mean)/(sigma*sigma));
	
};

RandomGen::RandomGen(unsigned int s){

	m_a=1664525;
	m_c=1013904223;
	m_m=1<<31;
	m_s=s;
	m_soriginal=s;
	
};

double RandomGen::Rand(){

	double x_i=(m_a*m_s+m_c)%(m_m);
	m_s=x_i;
	return x_i/double(m_m);
	
};

double RandomGen::Unif(double xmin, double xmax){

	if(xmin>xmax){
		double t=xmin;
		xmin=xmax;
		xmax=t;
	}
	
	return xmin+(xmax-xmin)*Rand();

};

double RandomGen::Exp(double mean){

	return -1/mean*log(1-Rand());

};

double RandomGen::Gauss(double mean, double sigma){
		
	double s=Rand();
	double t=Rand();
	double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
		
	return mean+sigma*x;

};

double RandomGen::GaussAR(double mean, double sigma){
			
	double a=mean-5.*sigma;
	double b=mean+5.*sigma;
	double max=Gaussiana(mean,mean,sigma);
	double s=Rand();
	double t=Rand();
	double x=a+(b-a)*s;
	double y=max*t;

	while(y >= Gaussiana(x, mean, sigma)){
		x=Unif(a,b);
		y=Unif(0,max);
	};
			
	return x;
		
};