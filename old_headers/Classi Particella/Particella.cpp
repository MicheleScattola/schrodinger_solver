#include "../Classes/Particella.h"
#include <iostream>

//PARTICELLA

    //Constructor
Particella::Particella(double massa, double carica) {
    m_massa = massa;
    m_carica = carica;
};

    //Metodi Get
double Particella::GetMassa() const { return m_massa; };
double Particella::GetCarica() const { return m_carica; };
    //Metodo Print
void Particella::Print() const {
    std::cout << "Particella: m = " << m_massa << " , q = " << m_carica << std::endl;
};

// ========================================================
//ELETTRONE

    //Constructor definito dai valori dell'elettrone
Elettrone::Elettrone() : Particella(9.1093826E-31, -1.60217653E-19) { };

/*Elettrone::~Elettrone(); NON POSSO DICHIARARLO?? */

    //Metodo Print elettrone
void Elettrone::Print() const {
    std::cout << "Elettrone: m = " << m_massa << " , q = " << m_carica << std::endl;
};

// ========================================================
//CORPO CELESTE

    //Constructor (nome,massa,raggio)  | massa = 0
CorpoCeleste::CorpoCeleste(std::string nome, double massa, double raggio) : Particella(massa,0) {
    m_nome = nome;
    m_massa = massa;
    m_raggio = raggio;
};

    //Metodi Set e Get
void CorpoCeleste::SetNome(std::string nome) { m_nome = nome; };
void CorpoCeleste::SetMassa(double massa) { m_massa = massa; };
void CorpoCeleste::SetRaggio(double raggio) { m_raggio = raggio; };
void CorpoCeleste::SetPosizione(const Posizione& r) {m_r = r;};

std::string CorpoCeleste::GetNome() const { return m_nome;};
double CorpoCeleste::GetRaggio() const {return m_raggio;};
Posizione CorpoCeleste::GetPosizione() const {return m_r;};

    //Metodo Print CorpoCeleste
void CorpoCeleste::Print() const {
    std::cout << "Corpo celeste  : " << m_nome << " , m = " << m_massa << " , r = " << m_raggio << std::endl;
};
