#include "FunzioneBase.h"
#include <iostream>
#include <cmath>

//PARABOLA
//costruttore con i 3 parametri
Parabola::Parabola(double a, double b, double c) {
    m_a = a;
    m_b = b;
    m_c = c;
};
//metodo virtual di eval della parabola
double Parabola::Eval(double x) const {
    return m_a*x*x + m_b*x + m_c;
};
void Parabola::SetA(double a) { m_a = a; };
void Parabola::SetB(double b) { m_b = b; };
void Parabola::SetC(double c) { m_c = c; };
double Parabola::GetA() const { return m_a; };
double Parabola::GetB() const { return m_b; };
double Parabola::GetC() const { return m_c; };

void Parabola::PrintVertice() const {
    Parabola P;
    double Xv = - (m_b)/(2*m_a);
    double Yv = P.Eval(Xv);
    std::cout << "Xvertice = " << Xv << " , Yvertice = " << Yv << std::endl;
    return;
};

//SENO
Sin::Sin(){
	a = 0;
	w = 0;
};
Sin::Sin(double A, double W){
	a = A;
	w = W;
};
void Sin::SetA(double A){
	a = A;
};
void Sin::SetW(double W){
	w = W;
};
double Sin::Eval(double x) const{
	return a*sin(w*x);
};

//COSENO
Cos::Cos(){
	a = 0;
	w = 0;
};
Cos::Cos(double A, double W){
	a = A;
	w = W;
};
void Cos::SetA(double A){
	a = A;
};
void Cos::SetW(double W){
	w = W;
};
double Cos::Eval(double x) const{
	return a*cos(w*x);
};

//SenX - X cosX
SinX_XCosX::SinX_XCosX(){
	a = 0;
	wa = 0;
	wb = 0;
};
SinX_XCosX::SinX_XCosX (double A, double B, double Wa, double Wb){
	a  = A;
	b  = B;
	wa = Wa;
	wb = Wb;
};
void SinX_XCosX::SetA(double A){
	a  = A;
};
void SinX_XCosX::SetB(double B){
	b  = B;
};
void SinX_XCosX::SetWa(double Wa){
	wa = Wa;
};
void SinX_XCosX::SetWb(double Wb){
	wb = Wb;
};
double SinX_XCosX::Eval(double x) const{
	return a*sin(wa*x)-b*x*cos(wb*x);
};
