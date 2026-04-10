#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"

    TApplication App("App", 0, 0);
    
    TH1F myHisto ("titolo", "titolo", nbins, xmin, xmax);

    myHisto.Fill(variabile);

    TH2F myHisto2 (nome, titolo, canali_x, xmin, xmax, canali_y, ymin, ymax);
    
    myHisto2.Fill(variabile x, variabile y);