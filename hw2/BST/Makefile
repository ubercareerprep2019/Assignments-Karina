CXXFLAGS =-g -std=c++11

main: main.o BST.o TreeNode.o
	g++ $(CXXFLAGS) main.o BST.o TreeNode.o -o main

main.o: main.cpp BST.h TreeNode.h
	g++ $(CXXFLAGS) -c main.cpp 

TreeNode.o: TreeNode.cpp TreeNode.h
	g++ $(CXXFLAGS) -c TreeNode.cpp 

BST.o: BST.cpp BST.h TreeNode.h
	g++ $(CXXFLAGS) -c BST.cpp

clean: 
	rm main *.o 