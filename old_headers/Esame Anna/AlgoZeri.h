/*
Dichiarazione della classe astratta Solutore e delle classi figlie che vanno a codificare le funzioni per compiere una certa operazione su una data funzione
*/

#ifndef __AlgoZeri_h__
#define __Algozeri_h__

#include "Funzione.h"

using namespace std;

class Solutore{

public:
  
	//metodo virtuale puro per cercare zeri di una funzione
  virtual double CercaZeri(double xmin, double xmax, const 
	FunzioneBase* f, double prec)=0;

	//distruttore della classe madre
	virtual ~Solutore(){ 
		//cout << "Solutore destructor called" << endl;
	};

	//metodi per accedere e settare m_prec 
  void SetPrecision(double epsilon) {m_prec=epsilon;};
  double GetPrecision() const {return m_prec;};

protected:

  double m_min, m_max;
  double m_prec;
	const FunzioneBase *m_f;

};

class Bisezione: public Solutore {

public:

  //costruttore vuoto
	Bisezione();

	//distruttore
  virtual ~Bisezione(){
		//cout << "Bisezione destructor called" << endl;
	};

	//metodo che restituiscce lo zero della funzione utilizzando l'algortimo di bisezione
  virtual double CercaZeri(double xmin, double xmax, const FunzioneBase* f, double prec);

	//metodi per settare i data membri
	void SetNmax(unsigned int n){ m_nmax=n; };
	void SetNiterations(unsigned int n){ m_niterations=n; };

	//metodi per accedere ai data membri 
	unsigned int GetNiterations() const { return m_niterations; };
	unsigned int GetNmax() const { return m_nmax; };

private:

unsigned int m_nmax=200;
unsigned int m_niterations;

};


#endif