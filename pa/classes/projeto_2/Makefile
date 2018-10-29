output: main.o Screen.o Line.o Rectangle.o Circle.o
	g++ -std=c++11 main.cpp Screen.o Line.o Rectangle.o Circle.o -o output.out

Main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Screen.o: Screen.cpp Screen.hpp
	g++ -std=c++11 -c Screen.cpp

Line.o: Line.cpp Line.hpp
	g++ -std=c++11 -c Line.cpp

Rectangle.o: Rectangle.cpp Rectangle.hpp
	g++ -std=c++11 -c Rectangle.cpp

Circle.o: Circle.cpp Circle.hpp
	g++ -std=c++11 -c Circle.cpp

clean:
	rm *.o output.out