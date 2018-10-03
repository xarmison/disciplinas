all: main.o Matrix.o
	g++ main.o Matrix.o -o output.out

main.o: main.cpp
	g++ -c main.cpp

Matrix.o: Matrix.cpp Matrix.hpp
	g++ -c Matrix.cpp

clean: 
	rm *.o output.out