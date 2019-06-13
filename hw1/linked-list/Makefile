CXXFLAGS=-g -std=c++11
main: ListTest.o 
	g++ $(CXXFLAGS) -o main ListTest.o 

ListTest.o: List.h Node.h


test: test.o 
	g++ $(CXXFLAGS) -o test test.o 

test.o: test.cpp List.h Node.h

clean:
	rm -f *.o main main.exe
	rm -f *.o test test.exe