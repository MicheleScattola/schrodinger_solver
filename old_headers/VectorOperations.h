
// ===============================================================================                                                                                               
//
// A library defining possible operations among std::vector 
//
// ===============================================================================                                                                                               

#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>  // se se vogliono usare algoritmi STL
#include <numeric>    // per inner_product

using namespace std;

// ===============================================================================                                                                                            
// somma di due vettori : somma componente per componente
// ===============================================================================                                                                                               

template <typename T> std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b) {
  
  // below different ways to check if vectors have the same size 

  // assert(a.size() == b.size());  
  //  if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;  
  if ( a.size() != b.size() ) { 
    cout << "Trying to sum vectors with different size, exiting" << endl ; 
    exit(-1); 
  } ; 
  
  std::vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] + b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //  std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::plus<T>()); 
  
  return result;
  
}

// ===============================================================================                                                                                                
// differenza di due vettori componente per componente
// [ preferisco re-implementarlo perche' si fanno meno operazioni rispetto result = a + (-1.*b) ]
// ===============================================================================                                                                                                
template <typename T> std::vector<T> operator-(const std::vector<T> &a, const std::vector<T> &b) {
  
  // below different ways to check if vectors have the same size                                                                                                             
  // assert(a.size() == b.size());                                                                                                                                           
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                             
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;

  std::vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] - b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), result.begin() , std::minus<T>()); 
  
  return result;
  
}

// ===============================================================================  
// prodotto scalare tra due vettori 
// ===============================================================================

template <typename T> T operator*(const std::vector<T> &a, const std::vector<T> &b) {

  // below different ways to check if vectors have the same size                                                                                                             
  // assert(a.size() == b.size());                                                                                                                                          
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to multiply vectors with different size, exiting" << endl ;
    exit(-1);
  } ;

  T sum = 0 ;
  for (int i = 0; i < static_cast<int>(a.size()); i++) sum += a[i] * b[i];  
  
  // Alternativamente si puo' usare l'algoritmo inner_product della STL
  //
  // sum = std::inner_product(std::begin(a), std::end(a), std::begin(b), 1.0);
  
  return sum;
  
}

// ===============================================================================
// prodotto tra uno scalare e un vettore
// ===============================================================================

template <typename T> std::vector<T> operator*( T c , const std::vector<T> &a) {
  
  std::vector<T> result(a.size());
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = c * a[i];  
  
  // Alternativamente si puo' usare l'algoritmo inner product
  //
  //     std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){ return x * c; } );
  
  return result;
  
}

// ===============================================================================
// prodotto tra un vettore e uno scalare 
// ===============================================================================

template <typename T> std::vector<T> operator*( const std::vector<T> &a , T c) {
  
  std::vector<T> result(a.size());
  
for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = c * a[i];  
  
  // oppure il ciclo for puo' essere sostituito da ( ~ stesso numero di operazioni con il
  // move constructor del vector altrimenti sarebbe meno efficiente )
  // 
  // result = c * a ;
  
  // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
  //    
  //    std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){ return x * c; } );
  
  return result;
  
}

// ===============================================================================
// divisione tra un vettore e uno scalare 
// ===============================================================================

template <typename T> std::vector<T> operator/( const std::vector<T> &a , T c) {
  
  std::vector<T> result(a.size());
  for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] / c ;  
  
  // oppure il ciclo for puo' essere sostituito da
  
  // double fact = 1./c
  // result = a * fact ;
  
  // Alternativamente si puo' usare l'algoritmo transform della STL con una lambda function
  //    
  //    std::transform(std::begin(a), std::end(a), std::begin(result), [&c](T x){ return x / c; } );
  
  return result;
  
}

// ===============================================================================
// somma ad a un vettore b e il risultato viene messo in a
// ===============================================================================

template <typename T> std::vector<T>& operator+=(std::vector<T>& a, const std::vector<T>& b) {

  // below different ways to check if vectors have the same size                                                                                                             
  // assert(a.size() == b.size());                                                                                                                                           
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] += b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::plus<T>()); 
  
  return a;
}

// ===============================================================================
// sottrai ad a un vettore b e il risultato viene messo in a
// ===============================================================================

template <typename T> std::vector<T>& operator-=(std::vector<T>& a, const std::vector<T>& b) {
  
  // below different ways to check if vectors have the same size                                                                                                             
  // assert(a.size() == b.size());                                                                                                                                           
  // if ( a.size() != b.size() ) throw "Trying to sum vectors with different size" ;                                                                                         
  if ( a.size() != b.size() ) {
    cout << "Trying to sum vectors with different size, exiting" << endl ;
    exit(-1);
  } ;
  
  for (int i = 0; i < static_cast<int>(a.size()); i++) a[i] -= b[i];    
  
  // Alternativamente si puo' usare l'algoritmo transform della STL
  //
  //    std::transform(a.begin(), a.end(), b.begin(), a.begin() , std::minus<T>()); 
  
  return a;
}

// ===============================================================================
// Possiamo usare funzioni generiche che agiscono sui vettori
// ===============================================================================
  
  // metodo comodo per stampare il vettore
  
template <typename T> void Print( const std::vector<T> &v ) {
  
  std::cout << "Printing vector" << std::endl;
  for ( auto it = v.begin() ; it != v.end() ; it++ ) std::cout << *it << " " ;
  std::cout << std::endl;
  std::cout << "End of printing vector" << std::endl;
  
};



/*
template <typename T> class linearVector : public std::vector<T> {
  
public :

  linearVector<T> ( ) : std::vector<T>(){} ;
  linearVector<T> ( int size ) : std::vector<T>(size){} ;  

  linearVector<T> operator+( const linearVector<T> &a ) {
    
    assert(a.size() == this->size());
    
    linearVector<T> result(a.size()) ;
    for (int i = 0; i < static_cast<int>(a.size()); i++) result[i] = a[i] + (*this)[i];
    
    return result;
    
  }
  
};
*/

//Le mie funzioni
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
//CORRELAZIONE
template <typename T> T Min(const T a, const T b){
	return a<b?a:b;
};

template <typename T> T CalcolaCorrelazione(const vector<T> a, const vector<T> b){
    T aMed = 0, a2Med = 0, bMed = 0, b2Med = 0, abMed = 0;
      
      for(int i = 0; i < a.size(); i++){
        aMed+= a[i];
        a2Med += pow(a[i], 2);
      };
      for(int i = 0; i < b.size(); i++){
        bMed+= b[i];
        b2Med+= pow(b[i], 2);
      };
      for(int i = 0; i<Min(a.size(),b.size()); i++){
        abMed+= a[i]*b[i];
      };
   
    aMed = aMed/a.size();
    bMed = bMed/b.size();
    a2Med = a2Med/a.size();
    b2Med = b2Med/b.size();
    abMed = abMed/Min(a.size(),b.size());

    T sigmaA = sqrt(a2Med - pow(aMed, 2));
    T sigmaB = sqrt(b2Med - pow(bMed, 2));
	return (abMed - aMed*bMed)/(sigmaA*sigmaB);

};

// =====================================================================