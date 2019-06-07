CXXFLAGS=-g -std=c++11
main: ListTest.o List.o Node.o
	g++ -g -o main ListTest.o List.o Node.o
ListTest.o: ListTest.cpp List.h Node.h
List.o: List.cpp List.h Node.h
Node.o: Node.cpp Node.h
clean:
	rm -f *.o main main.exe