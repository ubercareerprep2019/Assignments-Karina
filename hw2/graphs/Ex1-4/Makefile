CXXFLAGS =-g -std=c++11

graph: GraphWithAdjacencyList.o
	g++ $(CXXFLAGS) GraphWithAdjacencyList.o -o graph

GraphWithAdjacencyList.o: GraphWithAdjacencyList.cpp 
	g++ $(CXXFLAGS) -c GraphWithAdjacencyList.cpp 

clean: 
	rm graph *.o 