#include "../Classes/Posizione.h"
#include <cmath>
#include <iostream>

using namespace std;
    //Constructor (1): vuoto
Posizione::Posizione(){
      m_x = 0;
      m_y = 0;
      m_z = 0;
} ;
    //Constructor (2): Posizione(x,y,z)
Posizione::Posizione(double x, double y, double z){
      m_x = x;
      m_y = y;
      m_z = z;
};

    //Destructor
Posizione::~Posizione(){
};

    //Coordinate Cartesiane: metodi Get e Set + metodo Print
double Posizione::GetX() const { return m_x; };
double Posizione::GetY() const { return m_y; };
double Posizione::GetZ() const { return m_z; };
void Posizione::SetX(double x) { m_x = x; };
void Posizione::SetY(double y) { m_y = y; };
void Posizione::SetZ(double z) { m_z = z; };
void Posizione::PrintCartesiane(const Posizione& r) const {
    //std::cout << "Coordinate della posizione  :" << std::endl;
    std::cout << "x = " << m_x << "\ny = " << m_y << "\nz = " << m_z << std::endl;
            return;
};

    //Coordinate Sferiche
double Posizione::GetR() const {
    return sqrt( pow(m_x,2) + pow(m_y,2) + pow(m_z,2) );
};
double Posizione::GetPhi() const {
    return atan2(m_y,m_x);
};
double Posizione::GetTheta() const {
    return acos(m_z/GetR());
};

    //Coordinate Cilindriche
double Posizione::GetRho() const {
    return sqrt( pow(m_x,2) + pow(m_y,2) );
};

    //Metodo Distanza
double Posizione::GetDistanza(const Posizione& p) const {
    return sqrt(  pow(m_x-p.GetX(),2) + pow(m_y-p.GetY(),2) + pow(m_z-p.GetZ(),2)  );
};

    //Operator + , /
Posizione Posizione::operator+(Posizione p) const {
    Posizione somma(p);
    somma.SetX( GetX() + p.GetX() );
    somma.SetY( GetY() + p.GetY() );
    somma.SetZ( GetZ() + p.GetZ() );
    return somma;
};
Posizione Posizione::operator/(double d) const {
    Posizione div;
    div.SetX( GetX()/d );
    div.SetY( GetY()/d );
    div.SetZ( GetZ()/d );
    return div;
};
    
