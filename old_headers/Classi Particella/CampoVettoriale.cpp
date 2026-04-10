#include "../Classes/CampoVettoriale.h"
#include <cmath>
#include <iostream>

    //Constructor (1): Posizione (r) , campo = 0
  CampoVettoriale::CampoVettoriale(const Posizione& r) : Posizione(r.GetX(),r.GetY(),r.GetZ()) {
      m_Fx = 0;
      m_Fy = 0;
      m_Fz = 0;
  };
    //Constructor (2): Posizione (r) , campo = (Fx,Fy,Fz)
  CampoVettoriale::CampoVettoriale(const Posizione& r, double Fx, double Fy, double Fz) : Posizione(r){
      m_Fx = Fx;
      m_Fy = Fy;
      m_Fz = Fz;
  };
  //Constructor (3): Posizione (x,y,z) , campo = (Fx,Fy,Fz)
  CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : Posizione(x,y,z) {
      m_Fx = Fx;
      m_Fy = Fy;
      m_Fz = Fz;
  };
    //Destuctor
  CampoVettoriale::~CampoVettoriale(){
  };

    //Metodi Get e Set
  double CampoVettoriale::GetFx() const {return m_Fx;} ;
  double CampoVettoriale::GetFy() const {return m_Fy;} ;
  double CampoVettoriale::GetFz() const {return m_Fz;} ;
  
  void CampoVettoriale::SetFx(double Fx) {m_Fx = Fx;} ;
  void CampoVettoriale::SetFy(double Fy) {m_Fy = Fy;} ;
  void CampoVettoriale::SetFz(double Fz) {m_Fz = Fz;} ;

  void CampoVettoriale::Print(){
	std::cout << "Campo = ( " << m_Fx << " , " << m_Fy << " , " << m_Fz << " )" << std::endl;
  return;
  };

    //Operatori =, += , +
  CampoVettoriale & CampoVettoriale::operator=(const CampoVettoriale &p){
	//Operatore di uguale per facilitare la definizione di operazioni tra elementi della classe
	SetX(p.GetX());
	SetY(p.GetY());
	SetZ(p.GetZ());
	m_Fx=p.GetFx();
	m_Fy=p.GetFy();
	m_Fz=p.GetFz();
	return *this;
};
  CampoVettoriale CampoVettoriale::operator+( const CampoVettoriale & v) {
      CampoVettoriale somma(v);
      somma.SetFx( v.GetFx() + GetFx() );
      somma.SetFy( v.GetFy() + GetFy() );
      somma.SetFz( v.GetFz() + GetFz() );
      return somma;
};
  CampoVettoriale & CampoVettoriale::operator+=( const CampoVettoriale & v) {
      return (*this) = (*this)+v;
};

  //Operazioni Modulo , / 
  double CampoVettoriale::Modulo() {
      return sqrt( pow(m_Fx,2) + pow(m_Fy,2) + pow(m_Fz,2) );
  };
  /*CampoVettoriale CampoVettoriale::operator/(double a) const {
    GetFx() = GetFx()/a;
    GetFy() = GetFy()/a;
    GetFz() = GetFz()/a;
    return;
    //oppure
    div.SetFx( GetFx()/a );
    div.SetFy( GetFy()/a );
    div.SetFz( GetFz()/a );
  }; */