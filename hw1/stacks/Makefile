CXXFLAGS=-std=c++11

main: main.o stack.o 
	g++ $(CXXFLAGS) -o main main.o stack.o 

main.o: main.cpp stack.h

stack.o: stack.cpp stack.h

clean:
	rm stack.o main.o  