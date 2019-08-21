CXXFLAGS =-g -std=c++11

numIslands: Ex5.o
	g++ $(CXXFLAGS) Ex5.o -o numIslands

Ex5.o: Ex5.cpp 
	g++ $(CXXFLAGS) -c Ex5.cpp 

clean: 
	rm numIslands *.o 