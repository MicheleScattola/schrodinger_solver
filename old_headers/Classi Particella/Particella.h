#ifndef __Particella_h__
#define __Particella_h__

#include <string>
#include "../Classes/Posizione.h"


class Particella {

public:

  // costruttori
   Particella();
   Particella(double , double);
  // distruttore
   ~Particella(){};

  // metodi
   double GetMassa() const;
   double GetCarica() const;

   virtual void Print() const;

 protected:
   double m_massa;
   double m_carica;

};

// ========================================================

class Elettrone : public Particella {

public:

  // costruttore
   Elettrone();
  // distruttore
   ~Elettrone(){ };

   //metodi
   virtual void Print() const;
};

// ========================================================

class CorpoCeleste : public Particella {

public:

  // costruttore
  CorpoCeleste(std::string , double , double );
  // distruttore
  ~CorpoCeleste(){ };
  // metodi
  void SetNome(std::string);
  void SetMassa(double);
  void SetRaggio(double);
  void SetPosizione(const Posizione&);

  std::string GetNome() const;
  double GetRaggio() const;
  Posizione GetPosizione() const;

  void Print() const;
  
protected:
  std::string m_nome;
  double m_raggio;
  Posizione m_r;

};

#endif // __Particella_h__
