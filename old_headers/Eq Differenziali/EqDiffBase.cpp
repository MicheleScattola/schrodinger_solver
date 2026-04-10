#include "EqDiffBase.h"
#include "FunzioneVettoriale.h"

#include <vector>
#include <iostream>
#include <cmath>

vector<double> Eulero::Passo (double t, const vector<double> x, double h, FunzioneVettorialeBase &f) const {
	return x + h*f.Eval(t, x);
};

vector<double> Runge::Passo (double t, const vector<double> x, double h, FunzioneVettorialeBase &f) const {
	vector<double> k1 = f.Eval(t, x);
	vector<double> k2 = f.Eval(t, x + h/2. * k1 );
	vector<double> k3 = f.Eval(t, x + h/2. * k2 );
	vector<double> k4 = f.Eval(t, x + h * k3);

	return x + h/6 * ( k1 + 2. * k2 + 2. * k3 + k4 );
};