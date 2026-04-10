#ifndef __VectorAlgebra_h__
#define __VectorAlgebra_h__
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Somma di vettori componente per componente
template <typename T> vector<T> operator+(const vector<T> &a, const vector<T> &b){
	vector<T> sum;
	if(a.size() != b.size()){
		cout << "Vector sizes don't match" << endl;
		exit(1);
	};
	for(int i=0; i<a.size(); i++){
		sum.push_back(a[i]+b[i]);
	};
	return sum;
	//transform(a.begin(), a.end(), b.begin(). sum.begin(), plus<T>());
};

//Differenza di vettori componente per componente
template <typename T> vector<T> operator-(const vector<T> &a, const vector<T> &b){
	vector<T> diff;
	if(a.size() != b.size()){
		cout << "Vector sizes don't match" << endl;
		exit(1);
	};
	for(int i=0; i<a.size(); i++){
		diff.push_back(a[i]-b[i]);
	};
	return diff;
	//transform(a.begin(), a.end(), b.begin(). diff.begin(), minus<T>());
};

//Prodotto scalare di vettori
template <typename T> T operator*(const vector<T> &a, const vector<T> &b ){
	T scalar=0;
	if(a.size() != b.size()){
		cout << "Vector sizes don't match" << endl;
		exit(1);
	};
	for(int i=0; i<a.size(); i++) scalar += a[i]*b[i];
	return scalar;
};

//Prodotto tra uno scalare ed un vettore
template <typename T> vector<T> operator*( T c, const vector<T> &a ){
	vector<T> prod;
	for(int i =0; i< a.size(); i++) prod.push_back(c*a[i]);
	return prod;
};
//Prodotto tra uno scalare ed un vettore, invertendo gli argomenti
template <typename T> vector<T> operator*( const vector<T> &a, T c){
	vector<T> prod;
	for(int i =0; i< a.size(); i++) prod.push_back(c*a[i]);
	return prod;
};

//Divisione tra vettore e scalare
template <typename T> vector<T> operator/ (T c, const vector<T> &a){
	vector<T> frac;
	for (int i=0; i< a.size(); i++) frac.push_back(a[i]/c);
	return frac;
};

//L'operatore +=
template <typename T> vector<T> operator+=( vector<T> &a, const vector<T> &b){
	if(a.size() != b.size()){
		cout << "Vector sizes don't match" << endl;
		exit(1);
	};
	std::transform (a.begin(), a.end(), b.begin(), a.begin(), plus<T>() );
	return a;
};

//L'operatore -=
template <typename T> vector<T> operator-=(vector<T> &a, const vector<T> &b){
	if(a.size() != b.size()){
		cout << "Vector sizes don't match" << endl;
		exit(1);
	};
	std::transform (a.begin(), a.end(), b.begin(), a.begin(), minus<T>() );
	return a;
};

template <typename T> T media(vector<T> v){
	T sum = 0;
	for ( int i = 0; i < v.size(); i++ ) sum+=v[i];
	return sum/v.size();
};

template <typename T> T devstd(vector<T> v){
	T med = media(v);
	T sum = 0;
	for ( int i = 0; i < v.size(); i++ ) sum+=pow(v[i]-med, 2);
	return sqrt(sum/(v.size()-1));
};

#endif
