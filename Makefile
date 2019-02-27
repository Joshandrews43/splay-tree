make: prog2

SplayTree.o: SplayTree.cpp
	g++ -std=c++0x -c SplayTree.cpp

prog2: SplayTree.o main.o
	g++ -std=c++0x -o prog2 SplayTree.o main.o

prog2.o: main.cpp
	g++ -std=c++0x -c main.cpp


clean:
	rm -f prog1A prog1B *.o
