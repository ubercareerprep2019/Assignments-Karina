CXXFLAGS=-std=c++11

main: main.o stack.o queue.o
	g++ $(CXXFLAGS) -o main main.o stack.o queue.o

main.o: main.cpp stack.h queue.o

stack.o: stack.cpp stack.h 

queue.o: queue.cpp queue.h 

test: test.o stack.o queue.o 
	g++ $(CXXFLAGS) -o test test.o queue.o stack.o

test.o: test.cpp stack.h queue.h  

clean:
	rm stack.o main.o queue.o test.o main test