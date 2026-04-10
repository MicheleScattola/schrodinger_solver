#include <vector>
#include <algorithm>

using namespace std;

//MEDIA
template <typename T> double CalcolaMedia( const vector<T> & v) {

  T accumulo = 0;
  if ( v.size() == 0 ) return accumulo;
  for ( int i = 0 ; i < v.size() ; i++ ) { 
    accumulo += v[i] ;
  }
  
  return accumulo / double ( v.size() ) ; 
};

//MEDIANA
template <typename T> double CalcolaMediana( vector<T> v ) {

    vector<T> vcopy;
    vcopy = v; 
	  sort( vcopy.begin(), vcopy.end() ) ;

  double mediana = 0;
  //calcolo della mediana
  if (vcopy.size() % 2 == 0){
    mediana =(vcopy[vcopy.size()/2 -1] + vcopy[vcopy.size()/2])/2;
  } else {
    mediana = vcopy[vcopy.size()/2];
  }

  return mediana;  
};

//VARIANZA
template <typename T> double CalcolaVarianza( const vector<T> & v) {

    T varianza = 0;
    T quadrati = 0;
    if(v.size()==0) {return quadrati;
    } else { for ( int i = 0; i < v.size(); i++){  
      quadrati = quadrati + pow(v[i]-CalcolaMedia(v),2);
    }
  
    }
    varianza = quadrati / double (v.size()); 

  return varianza ;
};

// =====================================================================

//LETTURA DA FILE
template <typename T> vector<T> Read( const char* filename ) {
  //dichiarazioni
  vector<T> v;
  ifstream in(filename);
    //controllo con assert l'esistenza del file origine
    assert (in && "Il file di origine non esiste.");
    //controllo di apertura file + trasferimento dati su variabile 'valore' tramite funzione 'in' e 'push_back'
    if (!in) {
      cout << "Impossibile aprire il file " << filename << " ." << endl;
      exit (-11);
    } else {
      while ( !in.eof() ) {
        T valore = 0;
        in >> valore;
        v.push_back(valore);
      };
    };
  return v;  
};

//STAMPA A SCHERMO
template <typename T> void Print( const vector<T> & v ) {
  for (int i=0; i<v.size(); i++) cout << "v[" << i << "] = " << v[i] << endl;  
  return;
};

//STAMPA SU FILE
template <typename T> void Print( const vector<T> & v  , const char* filename ) {
  //dichiarazione funzione di output
  ofstream out(filename);
    //test apertura
    if (!out) {
      cerr << "Impossibile creare il file " << filename << endl;
      return;
    }
    cout << "-- STAMPA SU FILE " << filename << " --" << endl;
    //settaggio della precisione di output sul file
    out << fixed << setprecision(2);
  out << "Grandezza Vettore: " << v.size() << endl;
  out << "Media = " << CalcolaMedia(v) << endl;
  out << "Mediana = " << CalcolaMediana(v) << endl;
  out << "Varianza = " << CalcolaVarianza(v) << endl;
  out << "\n";
    //selection sort della STL
    vector<T> vcopy;
    vcopy = v;
    sort(vcopy.begin(),vcopy.end());
out << "Stampa Vettore riordinato :\n";
for(int i=0;i<vcopy.size();i++) out << "v[" << i << "] = " << vcopy[i] << endl;

out.close();
};

// =====================================================================
