//===================================================================
// RICERCA ZERI DI FUNZIONE
void RicercaZeri(){
#include "../Classes/FunzioneBase.h"
#include "../Classes/Solutore.h"

    //Dichiarazione funzione f(x)
    FunzioneBase *f = new func(1);
    //CercaZeri per puntatore
    Solutore *b = new Bisezione();
    double zero = b->CercaZeri(xmin,xmax, f, prec, nmax 100 o 200);
        //NB ricordo b->Trovato == true è condizione di zero esistente
        //NB ricordo b->GetNIterations() ritorna il n. di iterazioni
        
        //Cifre Significative a schermo
        int cifre_significative = -log10(prec);
        cout << fixed;
        cout << setprecision(cifre_significative) << endl;

            // tabella a schermo -- da adattare
                cout << scientific  << setw(15) << left << setfill(' ') << "Precisione:"  <<
                    fixed << setw(20) << left << setfill(' ') << "Integrale:" <<
                    fixed << setw(20) << left << setfill(' ') << "Errore: " <<  endl;
            for (unsigned int i=1; i<=10; i++) {
            double prec_i = 1 / pow(10,i);
            double I_t = myInt_t.Integra( prec_i, f ); 
            double Err = abs(I_t - esatto);

            cout << setprecision(2) << scientific  << setw(15) << left << setfill(' ') << prec_i  <<
                    fixed << setprecision(i+1) << setw(20) << left << setfill(' ') << I_t <<
                    fixed << setprecision(i+1) << setw(20) << left << setfill(' ') << Err <<  endl;
            }
}


//===================================================================
// INTEGRAZIONE EQ. DIFF.
void IntEqDiff(){
#include "../Classes/EqDiffBase.h"  
#include "../Classes/FunzioneVettoriale.h"
    //passo noto
    FunzioneBase oppure direttamente Sin f(1,1); //per esempio
    Runge myRunge;
	Eulero myEuler;
    OscillatoreArmonico osc(omega0); //eq diff base

    vector<double> x {0. , 1.} ; //condizioni iniziali
	double t = 0. ;
    // serve definire anche nstep per avere precisione sulla fine della integrazione

    for (int step=0; step<nstep; step++) {
		x = myRunge.Passo(t,x,h,osc) ;	  // valx, valy, passo, eq diff base
		g->SetPoint(step,t,x[0]) ;
        double errore = fabs(x[0] - f.Eval(t))
		t = t + h ;
    } 

    //trovare passi per prec. richiesta
    // ricordo che per RK4 err = ( x_npassi - x_2npassi ) * 16/15


    //stima errore run-time senza soluzione esatta -- Attenzione ad errore locale o globale
    //ricordo che per RK4 basta fare la differenza delle soluzioni a passo h e h/2
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

}

//===================================================================
// INTEGRAZIONE DI UNA EQUAZ.
void Integr(){
#include "../Classes/FunzioneBase.h"
#include "../Classes/Integrale.h"

    Sin f(1,1);
    Simpson myInt_s(a,b);  //bisogna definire gli estremi a e b
    Midpoint myInt_m(a,b);

    cout  << setprecision(10) << "\nMETODO SIMPSON:\n\nIntegrale della funzione f(x) = sin(x) tra [0, pi] con " <<
    nstep << " passi: \nIntegrale = " << myInt_s.Integra(nstep,f) << " |  errore: " <<
    abs(myInt_s.Integra(nstep,f) - esatto) << endl;

            // Integrazione e incertezza in base al numero di passi + grafico per ROOT
            cout << scientific  << setw(15) << left << setfill(' ') << "Precisione:"  <<
                    fixed << setw(20) << left << setfill(' ') << "Integrale:" <<
                    fixed << setw(20) << left << setfill(' ') << "Errore: " <<  endl;

            for (unsigned int i=1; i<=10; i++) {
            double I_s = myInt_s.Integra( 2*i, f ); 
            double Err = abs(I_s - 2.);

            cout << fixed << setprecision(2) << setw(15) << left << setfill(' ') << 2*i <<
                    setprecision(10) << setw(20) << left << setfill(' ') << I_s <<
                    setprecision(10) << setw(20) << left << setfill(' ') << Err <<  endl;
            }
        
        // Grafico ROOT
        unsigned int step = 4. ;
        for (int k=0; k<20; k++) {
            h = fabs(b-a)/step;
            gSimpson.SetPoint(k, h, fabs(myInt_s.Integra(step,f)-esatto)) ;
            gMidpoint.SetPoint(k, h, fabs(myInt_m.Integra(step,f)-esatto)) ;
            step*=2 ;
        }

    //n. di step per precisione richiesta
    //OK: basta usare le funzioni di error per simpson e midpoint e fare un ciclo fino a che l'errore è minore della prec richiesta

}

//===================================================================
// ERRORE RK4
void ErrRK4(){
    epsilon = k * h^4 = Delta_N * 16/15 //con Delta_N = xN - x2N
    //calcolo k tramite Delta_N e il passo h usato

    h_segn = rad4( 15/16 * h^4/Delta_N * epsilon_segnato )
    //ricavo h_segn con epsilon_segnato = errore richiesto
}

// ERRORI INTEGRALI
    trapezi: e = k * h^2 = 4/3 * (I_h - H_h/2)
    simpson: e = k