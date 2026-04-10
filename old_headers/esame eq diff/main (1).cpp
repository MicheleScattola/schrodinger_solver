
#include <iostream>

#include "EquazioniDifferenziali.h"
#include "Funzioni.h"
#include "Statistica.h"
#include "RandomGen.h"

#include "TApplication.h"
#include "TCanvas.h" 
#include "TH1F.h"
#include "TAxis.h"

int main() {
 
// punto 1 ===============
/*
Integrare l’equazione differenziale con il metodo di Runge-Kutta effettuando un singolo passo di lunghezza h (ossia, integrare fino a t=h) e si determini l’errore (locale) commesso rispetto alla soluzione esatta xexact(t). Si ripeta il calcolo per valori di h pari a 0.5, 0.1, 0.05, 0.01, 0.005, 0.001. Costruire un grafico o una tabella dell’errore in funzione del passo h.
*/

	RungeKutta myRK;

	int rip = 6;
	double t = 0.;

	vector<double> h {0.5, 0.1, 0.05, 0.01, 0.005, 0.001};
	vector<double> x {1., 0.};
	vector<double> err (rip);

	Fun * myFun = new Fun();
	OscillatoreSmorzato * osc = new OscillatoreSmorzato();
	
	cout << "Punto 1 :" << endl;

// grafico oppure tabella
	for (int i=0; i<rip; i++) {

		t = h[i];
		x = myRK.Passo(t, x, h[i], osc);
		err[i] = fabs(x[0] - myFun->Eval(h[i]));

		cout << "Passo h = " << h[i] << "	errore = " << err[i] << endl;
		
		//condizioni iniziali
		x[0] = 1.;
		x[1] = 0.;
	}

// punto 2 ===============
/*
Assumendo per i risultati ottenuti nel punto 1) un andamento del tipo k1*h^k2 fornire una stima delle due costanti k1 e k2.
*/

	double k2 = 0.;
	double k1 = 0.;

	cout << endl;
/*	cout << "err-1: " << err[rip - 2] << endl;
	cout << "err: " << err[rip - 1] << endl;
	cout << "h-1: " << h[rip - 2] << endl;
	cout << "h: " << h[rip - 1] << endl;
*/
	k2 = log(err[2] / err[rip - 1]) / log(h[2]/h[rip - 1]);
	k1 = err[rip - 1] / pow(h[rip - 1], k2);

	cout << "Punto 2 : errore ( singolo step ) = " << k1 << " * h ^ " << k2 << endl;



// punto 3 ===============
/*
Integrare l’equazione differenziale fino a t=1 con un passo h = 0.01. Indicare il valore di x ottenuto e l’errore (globale) rispetto alla soluzione esatta Xexact(1).
*/
	double tempo = 1.;
	t = 0.;
	double errore = 0.;
	int k = 3;
	//condizioni iniziali
	x[0] = 1.;
	x[1] = 0.;

	while (t < tempo) {
        x = myRK.Passo(t, x, h[k], osc);
		errore = fabs(x[0] - myFun->Eval(tempo));
        t = t + h[k];
    }

	cout << endl;
	cout << "Punto 3 : x(t = 1) = " << x[0] << " +/- " << errore << endl;


// punto 4 ===============
/*
Stimare l’errore che si commette integrando con il metodo di Runge-Kutta fino a t=1 utilizzando un passo h=0.01 senza fare uso della soluzione esatta Xexact(t). Confrontare il numero stimato con l’equivalente per h=0.01 calcolato nel punto 3)
*/

	double appo = 0.;
	//condizioni iniziali
	x[0] = 1.;
	x[1] = 0.;
	t = 0.;

	//x con passo h
	while (t < tempo) {
        x = myRK.Passo(t, x, h[k], osc);
        t = t + h[k];
    }
	appo = x[0];




	
	//condizioni iniziali
	x[0] = 1.;
	x[1] = 0.;
	t = 0.;

	//x con passo h/2
	while (t < tempo) {
        x = myRK.Passo(t, x, h[k]/2., osc);
        t = t + h[k]/2.;
    }
	double err_rt = fabs(appo - x[0]);

	cout << endl;
	cout << "Punto 4 : stima errore runtime su x(t=1) " << err_rt << endl;


// punto 5 ===============
/*
Integrare l’equazione differenziale fino a t=1 utilizzando con il metodo di Runge-Kutta con un passo h e si determini l’errore (globale) commesso rispetto alla soluzione esatta Xexact(1) indicata sopra. Si effettui il calcolo per valori di h pari a 0.5, 0.1, 0.05, 0.01, 0.005, 0.001. Costruire un grafico o una tabella dell’errore in funzione del passo h.
*/

	cout << endl << "Punto 5 : " << endl;
	
	// grafico oppure tabella
	for (int i=0; i<rip; i++) {
		//condizioni iniziali
		x[0] = 1.;
		x[1] = 0.;
		t = 0.;

		while (t < tempo) {
	        x = myRK.Passo(t, x, h[i], osc);
        	t = t + h[i];
    	}
		err[i] = fabs(x[0] - myFun->Eval(t));
		
		cout << "Passo h = " << h[i] << "	errore = " << err[i] << endl;
	}
	

// punto 6 ===============
/*
Assumendo per i risultati del punto 5 un andamento del tipo k1*h^k2 fornire una stima delle due costanti k1 e k2
*/

	k2 = log(err[1] / err[rip - 1]) / log(h[1]/h[rip - 1]);
	k1 = err[rip - 1] / pow(h[rip - 1], k2);

	cout << endl;
	cout << "Punto 6 : errore ( globale ) = " << k1 << " * h ^ " << k2 << endl;


// punto 7 ===============
/*
Assumendo di conoscere la condizione iniziale sulla posizione x(0)=1 con una
incertezza assoluta pari a 0.001 stimare l’incertezza sul valore di x(t=1): 

per questa stima si eseguano un migliaio di integrazioni variando la condizione iniziale su x secondo una densita’ di probabilita’ gaussiana centrata in 1 e di larghezza 0.001: 

la deviazione standard della distribuzione degli x(t=1) rappresenta l’incertezza che stiamo cercando (si puo’ costruire un istogramma). [ Suggerimento : per questa stima usare un passo di integrazione h indicativamente compreso tra 0.001 e 0.01 ]
*/

	int n = 1000;
	double H = 0.001;
	vector<double> PosFin (n);
	double sigma = 0.001;

	//preparo root
	TApplication myApp("myApp", 0, 0);
	TH1F histo("Istogramma PosizioniFinali", "Istogramma PosizioniFinali", sqrt(n), 0.3, 0.0301);

	for (int i=0; i<n; i++) {

		//condizioni iniziali
		RandomGen myGen(2);
		x[0] = myGen.Gauss(1., sigma);
		x[1] = 0.;
		t = 0.;

		while (t < tempo) {
	        x = myRK.Passo(t, x, H, osc);
        	t = t + H;
    	}

		PosFin[i] = x[0];
		histo.Fill(PosFin[i]);
	}

	TCanvas c1("PosizioniFinali", "PosizioniFinali");
    c1.cd();
    histo.GetXaxis()->SetTitle("x [m]");
    histo.GetYaxis()->SetTitle("N");
    histo.Draw();
	
	cout << endl;
	cout << "Punto 7 : errore su x(t=1) = " << sqrt(CalcolaVarianza<double>(PosFin)) << endl;
	c1.SaveAs("PosFin.png");


// punto 8 ===============
/*
Assumendo che l’errore calcolato nel punto 7) non dipenda dal passo h scelto, stimare il passo h massimo affinche’ l’errore di integrazione calcolato nel punto 6) sia pari a un centesimo dell’incertezza introdotta dalla conoscenza della condizione iniziale.
*/
	
	double h_nec = pow((0.01 * sigma / k1), (1./k2));

	cout << endl;
	cout << "Punto 8 : passo necessario = " << h_nec << " per una incertezza " << 0.01 * sigma << endl;



	myApp.Run();

	return 0;

}