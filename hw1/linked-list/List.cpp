#include <iostream>

#include <string>
#include "List.h"

List::List(){
    head = nullptr;
    _size = 0;
}

List::~List(){
    std::cout << "In the destructor\n";
    if (head != nullptr){
        Node *t,*t2;

        t=head->getNext();
        while (t!=nullptr){
            t2=t;
            t=t->getNext();
            delete t2;
        }
        delete head;
    }


}

bool List::empty() {
    return _size == 0;
}

int List::size() {
    return _size;
}

void List::pushBack(int data){
  return insert(_size, data);
}

void List::insert(int index, int data){
    Node *n = new Node(data);
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

    Node *t, *t2;
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
void List::erase(int index){

    if (head == nullptr){
      std::cout<<"cannot remove"<<std::endl;
        return;
    }

    if (index == 0){
        Node *p = head;
        p = p->getNext();
        head = p;
        _size -=1;
        return;
    }

    Node *t, *t2;
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

// get value from 
int List::elementAt(int index){

    Node *t = head;
    int ctr=0;
    if (index >=0 && index < _size){
        while (ctr != index && t!=nullptr){
            t = t->getNext();
            ctr +=1;
        }

        return t->getData();
    }

    return -1;
}



std::string List::getDebugString(){
    std::string s = "";
    Node *t = head;
    while (t != nullptr){
        std::string data = std::to_string(t->getData());
        s = s + data +"->";
        t=t->getNext();
    }
    s=s+" NULL\n";
    s= "TOP-> " + s;
    return s;
}



