#makefile per la cartella ../Classes
all: Posizione.o Particella.o CampoVettoriale.o PuntoMateriale.o

Posizione.o: Posizione.h Posizione.cpp
	g++ -c Posizione.cpp -o Posizione.o

Particella.o: Particella.h Particella.cpp
	g++ -c Particella.cpp -o Particella.o

CampoVettoriale.o: CampoVettoriale.h CampoVettoriale.cpp
	g++ -c CampoVettoriale.cpp -o CampoVettoriale.o

PuntoMateriale.o: PuntoMateriale.h PuntoMateriale.cpp
	g++ -c PuntoMateriale.cpp -o PuntoMateriale.o

clean: 
	rm Posizione.o
	rm Particella.o
	rm CampoVettoriale.o
	rm PuntoMateriale.o