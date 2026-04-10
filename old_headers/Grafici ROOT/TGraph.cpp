#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"

    TGraph * g = new TGraph();
    TCanvas * c1 = new TCanvas("Titolo","Titolo",600,600);

		c1->cd();

			g->SetTitle("titolo;asse x;asse y");
			g->GetXaxis()->CenterTitle();
			g->GetYaxis()->CenterTitle();
			g->SetPoint(0,valore in x, valore in y); //inizializzato a zero il primo setpoint
			g->SetLineWidth(2);
			g->SetLineColor(46);
			g->SetMarkerStyle(21);

			g->Draw("ALP");