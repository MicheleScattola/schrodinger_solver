#ifndef __EQDIFFBASE_H__
#define __EQDIFFBASE_H__

#include <iostream>
#include <cmath>
#include <vector>
#include "FunzioneVettoriale.h"

class EquazioneDifferenzialeBase {
	public:
		virtual vector<double> Passo (double, const vector<double>, double, FunzioneVettorialeBase& ) const = 0;
};

class Eulero : EquazioneDifferenzialeBase {
	public:
		virtual vector<double> Passo( double, const vector<double>, double, FunzioneVettorialeBase& ) const override;
};

class Runge : EquazioneDifferenzialeBase {
	public:
		virtual vector<double> Passo( double, const vector<double>, double, FunzioneVettorialeBase& ) const override;
};

#endif // __EQDIFFBASE_H__