CXXFLAGS =-g -std=c++11

List: Ex6-List.o 
	g++ $(CXXFLAGS) Ex6-List.o -o List

BST: Ex6-BST.o 
	g++ $(CXXFLAGS) Ex6-BST.o -o BST

Ex6-List.o: Ex6-List.cpp
	g++ $(CXXFLAGS) -c Ex6-List.cpp

Ex6-BST.o: Ex6-BST.cpp 
	g++ $(CXXFLAGS) -c Ex6-BST.cpp 

clean: 
	rm List BST *.o 