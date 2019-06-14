#include <iostream>
#include "stack.h"
#include <exception>

//index 0 stores the int while index 1 stores info about the next min
stack::stack(){
  size = 0;
  t = -1;
}

minStack::minStack(){
}

bool stack::isEmpty(){
  return size==0;
}

bool minStack::isEmpty(){
  return m.isEmpty();
}

void stack::push(int n){
  
  if (isEmpty()){
    arr[0] = n;
    t = n;
    size += 1;
    return;
  }
  
  if (size < cap){
    arr[size] = n;
    t = n;
    size += 1;
    return;
  }

  else {
    std::cout << "at cap " << std::endl;
    return;
  }
}


void minStack::push(int n){

  //first element is min element
  if (s.isEmpty()){
    s.push(n);
    m.push(n);
  }
  
  else {
    s.push(n);
    if (n < m.top()){
      m.push(n);
    }
  }
}


int stack::top(){
  return t;
}

int minStack::top(){
  return s.top();
}

int stack::pop(){
  if (!isEmpty()){
    int ret = t;
      if (size == 1){
	t = -1;
	size -= 1;
	return ret;
      }

      else {
	t = arr[size-2];
	size -=1;
	return ret;
      }
  }

  else {
    std::cout << "Empty" << std::endl;
    return -1;
  }
}

int minStack::pop(){
  if (!(s.isEmpty())){
      if (m.top() == s.top()){
	m.pop();
      }
    }
  int ret = s.top();
  s.pop();
  return ret;
}

int minStack::minVal(){
  if (!(s.isEmpty())){
    return m.top();
  }

  else {
    throw "empty!";
      }
}

std::string stack::debugString(){
  std::cout << "size: " << size << std::endl;
  std::string s;
  for (int i=0; i < size; i++){
    s = std::to_string(arr[i]) + "->" + s;
  }

  s = "TOP->" + s.substr(0, s.length()-2);
  return s;
}

std::string minStack::debugString(){
  return s.debugString();
}
