#include "RandomGen.h"
#include <cmath>

RandomGen::RandomGen(unsigned int seed) {
    m_a = 1664525. ;
    m_c = 1013904223. ;
    m_m = 1<<31 ;
    m_seed = seed ;
};

double RandomGen::Rand() {
    double x_i = (m_a * m_seed + m_c)%m_m ;
    m_seed = x_i ;
    double x = x_i / double(m_m) ;
    return x;
};

double RandomGen::Unif(double xmin, double xmax) {
    double u = Rand() ;
    double d = xmin + (xmax - xmin) * u ;
    return d;
};

double RandomGen::Exp(double lambda) {
    return - 1/lambda * log(1 - Rand()) ;
};

double RandomGen::Gauss(double mean, double sigma) {
    double s=Rand();
    double t=Rand();
    double x=sqrt(-2. * log(1.-s)) * cos(2. * M_PI * t);
    return mean + x * sigma ;
};

double RandomGen::Gaussiana(double x, double mean, double sigma) {
    return 1 / (sigma*sqrt(2*M_PI)) * exp(pow((x-mean)/sigma, 2)*(-0.5));
};

double RandomGen::GaussAR(double mean, double sigma) {
    double max = Gaussiana(mean, mean, sigma);
    double a = mean - 4.*sigma ;
    double b = mean + 4.*sigma ;
    double x = 0. ;
    double y = max ;

    while(y >= Gaussiana(x,mean,sigma)) {
        double s=Rand();
        double t=Rand();
        x = a + (b-a)*s ; // x = Unif(a,b)
        y = max * t ;
    }
    return x;
};