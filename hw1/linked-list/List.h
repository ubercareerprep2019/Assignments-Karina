#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include<unordered_set>
template <typename T> class List{
	private:
	Node<T> *head;
	int _size;
	public:
	List();
	List(Node<T> *n);
	~List();
    bool empty();
    int size();
	void pushBack(T data);
	void insert(int index, T data);
	T popback();
	std::string getDebugString();
	void erase(int index);
	T elementAt(int index);
	bool hasCycle();
	bool isPalindrome(List<T> *l);
};

template <typename T>
List<T>::List(){
    head = nullptr;
    _size = 0;
}

template <typename T>
List<T>::List(Node<T> *n){
    head = n;
    int ctr = 0;
    Node<T> *p = head;
    while (p->getNext() != nullptr){
      p = p->getNext();
      ctr += 1;
    }
    _size = ctr;
}




template <typename T>
List<T>::~List(){
    std::cout << "In the destructor\n";
    if (head != nullptr){
      Node<int> *t,*t2;

        t=head->getNext();
        while (t!=nullptr){
            t2=t;
            t=t->getNext();
            delete t2;
        }
        delete head;
    }


}
template <typename T>
bool List<T>::empty() {
    return _size == 0;
}
template <typename T>
int List<T>::size() {
    return _size;
}

template <typename T>
void List<T>::pushBack(T data){
  return insert(_size, data);
}
template <typename T>
void List<T>::insert(int index, T data){
  Node<T> *n = new Node<T>(data);
    //inserting at the front
    if (index == 0){
      if (head==nullptr){
	head = n;
	_size += 1;
	return;
      }
      
      else {
	n->setNext(head);
	head = n;
	_size +=1;
	return;
      }
    }

    Node<T> *t, *t2;
    // t follows t2
    // t -> data -> t2
    t2 = head;
    int ctr = 0;
    while (ctr != index){
        t = t2;
        t2 = t2->getNext();
        ctr += 1;
    }
    //  std::cout << "here" << std::endl;
    //std::cout << t2->getData() << std::endl;

    t->setNext(n);
    n->setNext(t2);
    _size += 1;
    return;
}

// remove from at location
template <typename T>
void List<T>::erase(int index){

  if (head == nullptr || index > _size - 1 ){
      std::cout<<"cannot remove"<<std::endl;
      throw "can't do dis";
    }

    if (index == 0){
      Node<T> *p = head;
        p = p->getNext();
        head = p;
        _size -=1;
        return;
    }

    Node<T> *t, *t2;
    t2 = head;

    int ctr = 0;

    while (ctr != index){
        t = t2;
        t2 = t2->getNext();
        ctr += 1;
    }

    //now t2 is the node we want to remove
    //setting t's Next to t2's Next
    t->setNext(t2->getNext());
    t2 = nullptr;
    _size-=1;
}


template <typename T>
T List<T>::popback(){
  if (head == nullptr){
    throw "can't do dis";
  }

  else{
    Node<T> *t1, *t2;
    t1 = head;
    int ctr = 0;
    while (ctr != _size - 1){
      t2 = t1;
      t1 = t1->getNext();
      ctr += 1;
    }

    t2 -> setNext(nullptr);
    _size -= 1;
    return t1->getData();
  }

}

// get value from 
template <typename T>
T List<T>::elementAt(int index){

  Node<T> *t = head;
    int ctr=0;
    if (index >=0 && index < _size){
        while (ctr != index && t!=nullptr){
            t = t->getNext();
            ctr +=1;
        }

        return t->getData();
    }

    throw "can't do dis";
}


template <typename T>
std::string List<T>::getDebugString(){
    std::string s = "";
    Node<T> *t = head;
    while (t != nullptr){
        std::string data = std::to_string(t->getData());
        s = s + data +"->";
        t=t->getNext();
    }
    s=s+" NULL\n";
    s= "TOP-> " + s;
    return s;
}

//stores node memory addresses in a set and returns true once a repeat appears
template <typename T>
bool List<T>::hasCycle(){
  if (head == nullptr){
    return false;
  }

  else{
  std::unordered_set<std::string> visited;
    Node<T> *p = head;
    while (head != nullptr){
      if (visited.find(&p) != visited.end()){
	return true;
      }
      else {
      visited.insert(&p);
      }
    }
    return false;
  }
}

template <typename T>
bool List<T>::isPalindrome(List<T> *l){

  Node<T> *p = head;
  std::string thisString = "";
  while(p != nullptr){
    thisString += p->getData();
    p=p->getNext();
  }

  int c = 0;
  std::string otherString = "";
  while ( c < l->size()){
    //reversing the appending order
    otherString = l->elementAt(c) + otherString;
    c += 1;
  }
  
  std::cout << "thisString: " << thisString << "\notherString: " << otherString << "\n";

  return thisString == otherString;
}
  
  
