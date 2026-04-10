#include "TF1.h"
#include "TLegend.h"

    TF1 *FitAVE = new TF1("FitAVE","[0]/sqrt(x)",0,100000);
	FitAVE->SetLineColor(8);
	FitAVE->SetLineWidth(2);
	ErrAVE->Fit(FitAVE); //ErrAVE é un TGraph
    TLegend *legAVE = new TLegend(0.6,0.65,0.85,0.85); 
    	legAVE->AddEntry(FitAVE,"Fit media","l");
		legAVE->AddEntry(ErrAVE,"Errore media","lp");
		legAVE->Draw();