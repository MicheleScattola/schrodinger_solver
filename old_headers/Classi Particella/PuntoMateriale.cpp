#include "../Classes/PuntoMateriale.h"
#include "../Classes/Particella.h"
#include "../Classes/Posizione.h"
#include "../Classes/CampoVettoriale.h"

#include <cmath>

    //Constructor (1): Particella(massa,carica) , Posizone(r)
  PuntoMateriale::PuntoMateriale(double massa, double carica, const Posizione& r) :
  Particella(massa, carica) , Posizione(r) { };
    //Constructor (2): Particella(massa,carica) , Posizione(x,y,z)
  PuntoMateriale::PuntoMateriale(double massa, double carica, double x, double y, double z) :
  Particella(massa , carica) , Posizione(x, y, z) { };

    //Destructor
  PuntoMateriale::~PuntoMateriale(){};

    //Metodo CampoElettrico
  CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& r) const {
      double const PI = 3.14159;
      double const epsilon_0 = 8.85418E-12;
      double const k = 1 / (4 * PI * epsilon_0);  // [k] = [ N m^2 C^-2 ]

      double Ex = GetCarica() * k * ( (r.GetX()-GetX() ) / pow( GetDistanza(r) , 3 ) );
      double Ey = GetCarica() * k * ( (r.GetY()-GetY() ) / pow( GetDistanza(r) , 3 ) );
      double Ez = GetCarica() * k * ( (r.GetZ()-GetZ() ) / pow( GetDistanza(r) , 3 ) );

      return CampoVettoriale(r,Ex,Ey,Ez);
  };

      //Metodo CampoGravitazionale
  CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& r) const {
      double const G = 6.67430E-11;  // [G] = [ (N m^2) / Kg^2]

      double Gx =  -G * m_massa * ( (r.GetX()-GetX() ) / pow( GetDistanza(r) , 3 ) );
      double Gy =  -G * m_massa * ( (r.GetY()-GetY() ) / pow( GetDistanza(r) , 3 ) );
      double Gz =  -G * m_massa * ( (r.GetZ()-GetZ() ) / pow( GetDistanza(r) , 3 ) );
      
      return CampoVettoriale(r.GetX(),r.GetY(),r.GetZ(),Gx,Gy,Gz);
  };