
#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "../Classes/Posizione.h"

class CampoVettoriale : public Posizione {

public:

  CampoVettoriale(const Posizione&);
  CampoVettoriale(const Posizione&, double Fx, double Fy, double Fz);
  CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz);
  ~CampoVettoriale();
  
  double GetFx() const;
  double GetFy() const;
  double GetFz() const;
  void SetFx(double);
  void SetFy(double);
  void SetFz(double);
  void Print() ;

  //Operazioni
  double Modulo();
  CampoVettoriale & operator=(const CampoVettoriale&) ;
  CampoVettoriale & operator+=( const CampoVettoriale & ) ;
  CampoVettoriale operator+( const CampoVettoriale & ) ;
  /*CampoVettoriale operator/(double) const;*/

private:

  double m_Fx, m_Fy, m_Fz;

};

#endif // __CampoVettoriale_h__ 