#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

#include "Funzione.h"
#include "AlgoZeri.h"
#include "Integral.h"
#include "RandomGen.h"
#include "IntegraleMC.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TAxis.h"
#include "TGraph.h"

using namespace std;

int main() {

	TApplication app("app", 0, 0);

	FunzioneBase * f = new Funzione(1., -0.4, 1., 1., 0.);
	Solutore * B = new Bisezione();
	double prec=0.01;
	int cifre_significative = -log10(prec);
	B->SetPrecision(prec);

	cout << setprecision(cifre_significative);
	double x1=B->CercaZeri(1, 2, f, prec);
	double x2=B->CercaZeri(4, 5, f, 0.01);
	double x3=B->CercaZeri(7, 8, f, 0.01);

	cout << endl << "Zero della funzione f(x) nell'intervallo [1,2] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x1 << endl;

	cout << endl << "Zero della funzione f(x) nell'intervallo [4,5] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x2 << endl;

	cout << endl << "Zero della funzione f(x) nell'intervallo [7,8] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x3 << endl << endl;

  Trapezio myInt(x1,x2);
	Funzione myF(1., -0.4, 1., 1., 0.);
	unsigned int passi=10;

  double I=myInt.Integra(passi, myF);

  cout << setprecision(6);
	cout << "Il valore dell'integrale sull'intervallo di integrazione [x1,x2] calcolato con il metodo dei trapezoidi con numero di intervalli " << passi << " è:\n" << endl;
	cout << I << endl << endl;
	cout << "La precisione di tale stima è al più pari a:\n" << endl;
	cout << mod(myInt.GetA()-myInt.GetB())/passi << endl << endl;

	double prec2=0.001;
  double I2=myInt.Integra(prec, myF);

	cout << "Il numero di passi richiesto per avere una precisione di " << prec2 << " è:\n" << endl;
	cout << myInt.GetNstep() << endl << endl;
	
	IntegraleMC myInt2(1);
	unsigned int nstep=1000;
	
	double I3=myInt2.Media(myF,x1,x2,nstep);

	cout << "L'integrale della funzione sull'intervallo [x1,x2] calcolato con il metodo della media è:\n" << endl;
	cout << I3 << endl << endl;

	vector<double> x;

	for(int i=0;i<10000;i++){
		double Int=myInt2.Media(myF,x1,x2,nstep);
		x.push_back(Int);
	}

	double dev=devstd(x);
	double k1=dev*sqrt(nstep);
	double N2=pow(k1,2)/pow(prec2,2);

	cout << "Con il metodo della media se si vuole una precisione di " << prec2 << " serve un numero di punti pari a:\n" << endl;
	cout << int(N2+0.5) << endl;

	TGraph * g = new TGraph();
	unsigned int counter=0;

  for (double i = 0; i < x3; i+=0.1){   
		Trapezio myInt(x1,i);
		double x=myInt.Integra(passi,myF);
    g->SetPoint(counter, i , x);
		counter++;
  };
              
  // Titolo + nome assi
  g->SetTitle("Andamento funzione integrale con passo 0.1");
  g->GetXaxis()->SetTitle("Tempo [t]");
  g->GetYaxis()->SetTitle("Valore Integrale");


  // colore + grandezza linea del grafico
  g->SetLineWidth(3);
  g->SetLineColor(kRed);
	g->SetMarkerStyle(7); //segna i punti con il punto di media grandezza
  g->Draw("ALP"); 

	app.Run();
	 
	return 0;
	
} 