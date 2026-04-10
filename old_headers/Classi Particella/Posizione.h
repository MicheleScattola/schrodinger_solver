#ifndef __Posizione_h__
#define __Posizione_h__

class Posizione {

public:

  // costruttori
   Posizione();
   Posizione(double, double, double);
 
  // distruttore
   ~Posizione();
  
  // metodi
  double GetX() const; //coord. cartesiane
  double GetY() const;
  double GetZ() const;
  void SetX(double);
  void SetY(double);
  void SetZ(double);
  void PrintCartesiane(const Posizione&) const;
  double GetR() const; //coord sferiche
  double GetPhi() const;
  double GetTheta() const;
  double GetRho() const;
  double GetDistanza(const Posizione&) const; //distanza

  //operazioni
  Posizione operator+(Posizione) const;
  Posizione operator/(double) const;
 
private:

   double m_x , m_y , m_z;

};

#endif // __Posizione_h__
