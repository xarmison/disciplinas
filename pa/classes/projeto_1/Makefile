output: main.o Point.o Polygon.o Rectangle.o
	g++ -std=c++11 main.o Point.o Polygon.o Rectangle.o -o output.out

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Point.o: Point.cpp Point.hpp
	g++ -std=c++11 -c Point.cpp

Polygon.o: Polygon.cpp Polygon.hpp
	g++ -std=c++11 -c Polygon.cpp

Rectangle.o: Rectangle.cpp Rectangle.hpp
	g++ -std=c++11 -c Rectangle.cpp

clean:
	rm *.o output.out