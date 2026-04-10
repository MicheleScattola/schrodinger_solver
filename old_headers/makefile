INCS:=`root-config --cflags`
LIBS:=`root-config --libs`

main: main.o Prisma.o RandomGen.o VectorOperations.h
	g++ -o main main.o Prisma.o RandomGen.o ${INCS} ${LIBS}

main.o: main.cpp Prisma.o RandomGen.o VectorOperations.h
	g++ -c -o main.o main.cpp ${INCS} ${LIBS}

FunzioneVettoriale.o: FunzioneVettoriale.h FunzioneVettoriale.cpp VectorOperations.h
	g++ -c -Wall FunzioneVettoriale.cpp -o FunzioneVettoriale.o

EqDiffBase.o: EqDiffBase.h EqDiffBase.cpp FunzioneVettoriale.h
	g++ -c -Wall EqDiffBase.cpp -o EqDiffBase.o 

clean:
	rm *.o
	rm main