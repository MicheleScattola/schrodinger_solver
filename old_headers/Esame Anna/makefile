myLIBS=Funzione.o AlgoZeri.o IntegraleMC.o RandomGen.o

RFLAGS:=`root-config --libs` `root-config --cflags`

compito: compito.cpp Integral.h ${myLIBS}
	g++ -o $@ $^ ${RFLAGS}
%.o: %.cpp %.h Integral.h
	g++ -c $< ${RFLAGS}

clean: 
	rm *.o
	rm compito