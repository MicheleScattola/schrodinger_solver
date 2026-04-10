#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

class RandomGen {

    public:

    RandomGen(unsigned int);

    void SetA(unsigned int a) {m_a = a;};
    void SetC(unsigned int c) {m_c = c;};
    void SetM(unsigned int m) {m_m = m;};

    double Rand();                             //distrib. uniforme in [0,1)
    double Unif(double, double);               //distrib. uniforme in intervallo xmin - xmax
    double Exp(double);                        //distrib. exp
    double Gauss(double mean, double sigma);   //distrib. Gaussiana (Box-Muller)
    double GaussAR(double mean, double sigma); //distrib. Gaussiana (Accept-Reject)
    double Gaussiana(double, double, double);  //valutazione Gaussiana nel punto x
    private:

    unsigned int m_a, m_c, m_m ;
    unsigned int m_seed ;

};

#endif