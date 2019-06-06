CXXFLAGS=-std=c++11

main: main.o stack.o queue.o
	g++ $(CXXFLAGS) -o main main.o stack.o queue.o

main.o: main.cpp stack.h queue.o

stack.o: stack.cpp stack.h 

queue.o: queue.cpp queue.h 

clean:
	rm stack.o main.o queue.o 