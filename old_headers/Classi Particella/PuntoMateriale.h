#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "../Classes/Particella.h"
#include "../Classes/Posizione.h"

#include "../Classes/CampoVettoriale.h"

class PuntoMateriale : public Particella, public Posizione {

public:

  //Constructor
  PuntoMateriale(double massa, double carica, const Posizione&);
  PuntoMateriale(double massa, double carica, double x, double y, double z);
  //Destructor
  ~PuntoMateriale();

  //Metodi CampoElettrico e CampoGravitazionale
  CampoVettoriale CampoElettrico(const Posizione&) const ;
  CampoVettoriale CampoGravitazionale(const Posizione&) const;

};

#endif // __PuntoMateriale_h__


