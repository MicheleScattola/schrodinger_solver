#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

// Classe astratta generica

class FunzioneBase {
public:
    virtual ~FunzioneBase(){};
    virtual double Eval(double x) const = 0;
};

// Sottoclasse parabola
class Parabola : public FunzioneBase {
        
public:
    Parabola(){ };
    Parabola(double, double, double);
    ~Parabola(){ };

    virtual double Eval(double) const ;
    
    void SetA(double);
    void SetB(double);
    void SetC(double);
    double GetA() const;
    double GetB() const;
    double GetC() const;

    void PrintVertice() const;
    
private:
    double m_a, m_b, m_c;
};

// Sottoclasse segno
class Segno : public FunzioneBase {
    public:
    Segno () {;} ;
    ~Segno() {;} ;
    virtual double Eval(double x) const {
        return (x==0. ?0.:(x>0?1.:-1));
    }
};

class Sin : public FunzioneBase{
	public:
	Sin();
	Sin(double, double);
	
	void SetA(double);
	void SetW(double);
	double GetA() const { return a;};
	double GetW() const { return w;};
	virtual double Eval(double) const;
	
	private:
	double a, w;
};

class Cos : public FunzioneBase{
	public:
	Cos();
	Cos(double, double);

	void SetA(double);
	void SetW(double);
	double GetA() const { return a;};
	double GetW() const { return w;};
	virtual double Eval(double) const;

	private:
	double a, w;
};

class SinX_XCosX : public FunzioneBase {
	public:
	SinX_XCosX();
	SinX_XCosX(double, double, double, double);

	void SetA (double);
	void SetB (double);
	void SetWa(double);
	void SetWb(double);
	double GetA()  const { return a; };
	double GetB()  const { return b; };
	double GetWa() const { return wa;};
	double GetWb() const { return wb;};
	virtual double Eval(double) const;

	private:
	double a, b, wa, wb;
};


#endif