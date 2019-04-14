output: main.o OrderedSequentialList.o OrderedLinkedList.o LinkedList.o
	g++ -g3 -fsanitize=address \
		main.o \
		OrderedSequentialList.o \
		OrderedLinkedList.o \
		LinkedList.o \
		-o exe.out

main.o: main.cpp
	g++ -c main.cpp 

OrderedSequentialList.o: OrderedSequentialList.cpp OrderedSequentialList.hpp 
	g++ -c OrderedSequentialList.cpp 

OrderedLinkedList.o: OrderedLinkedList.cpp OrderedLinkedList.hpp
	g++ -c OrderedLinkedList.cpp 

LinkedList.o: LinkedList.cpp LinkedList.hpp
	g++ -c LinkedList.cpp

clean:
	rm *.o exe.out