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
#include "FunzioneIntegrale.h"
#include "VectorAlgebra.h"

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

	//punto 1
	FunzioneBase * f = new Funzione(1., -0.4, 1., 1., 0.);
	Solutore * B = new Bisezione();
	double prec=0.01;
	int cifre_significative = -log10(prec);
	B->SetPrecision(prec);

	cout << setprecision(cifre_significative);
	double x1=B->CercaZeri(1, 2, f, prec);
	double x2=B->CercaZeri(4, 5, f, prec);
	double x3=B->CercaZeri(7, 8, f, prec);

	cout << endl << "Zero della funzione f(x) nell'intervallo [1,2] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x1 << endl;

	cout << endl << "Zero della funzione f(x) nell'intervallo [4,5] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x2 << endl;

	cout << endl << "Zero della funzione f(x) nell'intervallo [7,8] stimato con precisione " << prec << ":\n " << endl;
	cout << fixed;
	cout << x3 << endl << endl;

  //punto 2 e 3 con stima runtime dell'errore
	Trapezio myInt(x1,x2);
	Funzione myF(1., -0.4, 1., 1., 0.);
	unsigned int passi=10;

  double I=myInt.Integra(passi, myF);
	double I2N=myInt.Integra(2*passi, myF);
	double myErr=(4./3.)*abs(I-I2N);

  cout << setprecision(3);
	cout << "Il valore dell'integrale sull'intervallo di integrazione [x1,x2] calcolato con il metodo dei trapezoidi con numero di intervalli " << passi << " è:\n" << endl;
	cout << I << endl << endl;
	cout << "L'errore commesso in tale stima è:\n" << endl;
	cout << myErr << endl << endl;

	//punto 4 
	double prec2=0.001;
	double h0=abs(x1-x2)/passi;
  double k=myErr/pow(h0,2);
	double h=sqrt(prec2/k);

	cout << "Il numero di passi richiesto per avere una precisione di " << prec2 << " è almeno:\n" << endl;
	cout << int(abs(x2-x1)/h+0.5) << endl << endl;
	
	//punto 5
	IntegraleMC myInt2(1);
	unsigned int nstep=1000;
	
	double I3=myInt2.Media(myF,x1,x2,nstep);

	cout << "L'integrale della funzione sull'intervallo [x1,x2] calcolato con il metodo della media è:\n" << endl;
	cout << I3 << endl << endl;

	vector<double> x;
	unsigned int Nprova=1000; //calcolo integrale con il metodo della media fissando il numero di passi ad N=1000

	//calcolo l'integrale M volte ponendo M=10000
	for(int i=0; i<10000; i++){
		double IntMC=myInt2.Media(myF,x1,x2,Nprova);
		x.push_back(IntMC);
	}

	//calcolo la deviazione standard così da trovare k=dev*sqrt(Nprova) 
	//che uso girando la formula per trovare N che mi serve se fisso dev=prec2
	double dev=devstd(x);
	double k1=dev*sqrt(Nprova);
	double N2=pow(k1,2)/pow(prec2,2);

	cout << "Con il metodo della media se si vuole una precisione di " << prec2 << " serve un numero di punti pari ad almeno:\n" << endl;
	cout << int(N2+0.5) << endl;

	//punto 6
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

	//punto 7
	FunzioneBase * f = new Funzione(1., -0.4, 1., 1., 0.);
	Integral* i= new Trapezio(x1,)..
	double prec=0.001;

	FunzioneIntegrale myF1(x1,prec,f,i);

	double x4=B->CercaZeri(6, 7, &myF1, prec);
	
	cout << setprecision(cifre_significative2);
	cout << endl << "Zero della funzione F(x) nell'intervallo [6,7] stimato con precisione " << prec2 << ":\n " << endl;
	cout << x4 << endl;

	app.Run();
	 
	return 0;
	
} 