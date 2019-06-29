CXXFLAGS =-g -std=c++11

main: main.o Tree.o TreeNode.o 
	g++ $(CXXFLAGS) -o main main.o Tree.o TreeNode.o 

main.o: main.cpp Tree.h TreeNode.h
	g++ $(CXXFLAGS) -c main.cpp

Tree.o: Tree.cpp Tree.h TreeNode.h
	g++ $(CXXFLAGS) -c Tree.cpp

TreeNode.o: TreeNode.cpp TreeNode.h
	g++ $(CXXFLAGS) -c TreeNode.cpp 

clean:
	rm main *.o 