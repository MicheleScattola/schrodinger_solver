#include "funzioni.h"

// legge <size> elementi da <Filename> e restituisce un array

double * ReadDataFromFile ( const char* filename , int size  ) {

  double * data = new double[size];
  
  ifstream ReadDataFromFile(filename);

    //test per apertura
    if( !ReadDataFromFile ) {
      cout << "error opening file " << filename << endl;
      exit(0);
    } else {
      for(int k=0; k < size; k++){
        ReadDataFromFile >> data[k] ;
        //fine caricamento dati
        if (ReadDataFromFile.eof()) {
          cout << "End of file reached, exiting..." << endl;
          exit(0);
        }
      }
    }
    ReadDataFromFile.close();

  return data;
}
//Print su file
void Print ( const char* Filename, double * data, int size ) {
ofstream fout(Filename);
  //set della precisione di scrittura
  fout << fixed;
  fout << setprecision(2);


fout << "Numero dati: " << size << endl;
fout << "Media = " << CalcolaMedia(data,size) << endl;
fout << "Mediana = " << CalcolaMediana(data,size) << endl;
fout << "Varianza = " << CalcolaVarianza(data,size) << endl;
fout << "\n";
    //selection sort per stampa di dati riordinati
    double * vcopy = new double[size];
    for(int i=0; i<size ; i++) vcopy[i] = data[i];
    selection_sort(vcopy,size);
fout << "Stampa dati riordinati :\n";
for(int i=0;i<size;i++) fout << "data[" << i << "] = " << vcopy[i] << endl;

fout.close();
}
//Print a schermo
void Print(double *  data, int  ndata){
for(int i=0;i<ndata;i++) cout << data[i] << endl;
}

// calcola la media di <size> elementi dell'array <data>

double CalcolaMedia( double * data , int size ) {

    double accumulo = 0;
    double media = 0;
    for ( int i = 0; i < size; i++){
      accumulo += data[i];
    }
    media = accumulo / double (size);

  return media ;
  
}

// calcola la varianza di <size> elementi dell'array <data>

double CalcolaVarianza( double * data , int size ) {

    double media = CalcolaMedia(data , size);
    double varianza = 0;
    double var = 0;
    for ( int i = 0; i < size; i++){  
      var += pow(( data[i] - media ) , 2.0);
    }
    varianza = var / double (size); 

  return varianza ;
  
}

// funzioni per scambiare di posto due elementi, utile per il riordinamento

void scambiaByValue(double a, double b) {

  double c = a;
  a = b;
  b = c;

}

void scambiaByRef(double &a, double &b) {

  double c = a;
  a = b;
  b = c;

}

void scambiaByPointer(double *a, double *b) {

double c = *a;
*a = *b;
*b = c;

}

// algoritmo di riordinamento di un array ( selection_sort ) 

void selection_sort( double * vec , int size) {

    for ( int j = 0; j < size - 1 ; j++){
      int imin = j;
      double min = vec[imin];
        for ( int i=j+1; i < size; i++){
          if ( vec[i] < min ){
            min = vec[i];
            imin = i;
          }
        }
        scambiaByRef(vec[j],vec[imin]);
    }                 
}

// Calcolo della mediana di un array <vec> di dimensione <size>. Prima si crea
// una copia dell'array, lo riordina e calcola la mediana

double CalcolaMediana ( double vec[] , int size ) {


  double * vcopy = new double[size];
  for(int i=0; i<size ; i++) vcopy[i] = vec[i];
  
  selection_sort(vcopy,size);
  
  double mediana = 0;

    //calcolo della mediana
  if (size % 2 == 0){
    mediana = ( vcopy[size/2 -1] + vcopy[size/2 + 1]) / 2;
  } else {
    mediana = vcopy[size/2];
  }

  delete [] vcopy;
  return mediana;
} 

