#include "funzioni.h"
#include <cmath>
#include <cassert>
#include <iomanip>

//LETTURA ELEMENTI DA FILE
Vettore Read(int N, const char* filename) {
  //dichiarazioni
  Vettore v(N);
  ifstream in(filename);
    //controllo con assert l'esistenza del file origine
    assert (in && "Il file di origine non esiste.");
    //controllo di apertura file + trasferimento dati su variabile 'valore' tramite funzione 'in' e 'SetComponent'
    if (!in) {
      cout << "Impossibile aprire il file." << endl;
      exit (11);
    } else {
      for (int i=0; i<N; i++) {
        double valore = 0;
        in >> valore;
        v.SetComponent(i,valore);
        //controllo fine lettura file con eof
        if ( in.eof() ) {
          cout << "Fine del file raggiunto, exiting..." << endl;
          exit (12);
        }
      }
    }
  return v;
}

//CALCOLO DELLA MEDIA
double CalcolaMedia( const Vettore & v ) {
  //dichiarazioni
  double accumulo = 0;
  //funzionamento funzione
  if ( v.GetN() == 0 ) return accumulo;

  for ( int k = 0 ; k < v.GetN() ; k++ ) { 
    accumulo += v.GetComponent(k) ;
  }
  
  return accumulo / double ( v.GetN() ) ;
  
}

//CALCOLO DELLA MEDIANA
double CalcolaMediana (Vettore v) {

  //copia del vettore V di dimensioni V.GetN
  Vettore vcopy;
  vcopy = v;
  
  selection_sort(vcopy);
  
  double mediana = 0;

  //calcolo della mediana
  if (vcopy.GetN() % 2 == 0){
  double a = vcopy.GetComponent(vcopy.GetN()/2 -1);
  double b = vcopy.GetComponent(vcopy.GetN()/2);
   mediana = (a+b)/2;
  } else {
    mediana = vcopy.GetComponent(vcopy.GetN()/2);
  }

  return mediana;
} 


//CALCOLO DELLA VARIANZA
double CalcolaVarianza( const Vettore & v ) {

    double varianza = 0;
    double quadrati = 0;
    if(v.GetN()==0) {return quadrati;
    } else { for ( int i = 0; i < v.GetN(); i++){  
      quadrati = quadrati + pow(v.GetComponent(i)-CalcolaMedia(v),2);
    }
  
    }
    varianza = quadrati / double (v.GetN()); 

  return varianza ;
  
}

//PRINT SU FILE
void Print (const Vettore & v, const char* filename){

  //dichiarazione funzione di output
  ofstream out(filename);
    cout << "-- STAMPA SU FILE " << filename << " --" << endl;
    //settaggio della precisione di output sul file
    out << fixed << setprecision(2);
  //stampa su file
  out << "Grandezza Vettore: " << v.GetN() << endl;
  out << "Media = " << CalcolaMedia(v) << endl;
  out << "Mediana = " << CalcolaMediana(v) << endl;
  out << "Varianza = " << CalcolaVarianza(v) << endl;
  out << "\n";
    //selection sort per stampa di dati riordinati
    Vettore vcopy;
    vcopy = v;
    selection_sort(vcopy);
out << "Stampa Vettore riordinato :\n";
for(int i=0;i<v.GetN();i++) out << "componente[" << i << "] = " << vcopy[i] << endl;

out.close();

}


//PRINT SU SCHERMO
void Print (const Vettore & v){
  cout << "-- visualizzazione --" << endl;
  for (int i=0; i<v.GetN(); i++) cout << "v["<< i << "] = " << v.GetComponent(i) << endl;
}


//SELECTION SORT
void selection_sort( Vettore & v ) {
    
    int imin = 0;
    double min = 0;

    for ( int j = 0; j < v.GetN() - 1 ; j++){
      imin = j;
      min = v[imin];
        for ( int i=j+1; i < v.GetN(); i++){
          if ( v[i] < min ){
            min = v[i];
            imin = i;
          }
        }
       v.Scambia(j,imin);
    }                 
}