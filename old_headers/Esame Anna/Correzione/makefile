myLIBS=Funzione.o AlgoZeri.o IntegraleMC.o RandomGen.o Integral.o FunzioneIntegrale.o

RFLAGS:=`root-config --libs` `root-config --cflags`

compito: compito.cpp ${myLIBS}
	g++ -o $@ $^ ${RFLAGS}
%.o: %.cpp %.h 
	g++ -c $< ${RFLAGS}

clean: 
	rm *.o
	rm compito