#pragma once
#include <iostream>
#include <string>
#include "Node.h"

class List{
	private:
	Node *head;
	int _size;
	public:
	List();
	~List();
    bool empty();
    int size();
	void pushBack(int data);
	void insert(int index, int data);
	std::string getDebugString();
	void erase(int index);
	int elementAt(int index);
};


