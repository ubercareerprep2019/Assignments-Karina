#include <iostream>
#include "stack.h"

stack::stack(){
  size = 0;
  t = -1;
}

bool stack::isEmpty(){
  return size==0;
}

void stack::push(int n){
  if (size < capacity){
    arr[size-1] = n;
    t = n;
    size += 1;
    std::cout << "just pushed " << n << std::endl;
    std::cout << "size is: " << size << std::endl;
    return;
  }

  else {
    std::cout << "at capacity" << std::endl;
    return;
  }

}

int stack::top(){
  
  return t;
  
}


int stack::pop(){

  if (!isEmpty()){
    int ret = t;
      size--;
      if (size == 0){
	t = -1;
      }
      else {
	t = arr[size-1];
      }
      return ret;
    }

  else {
    std::cout << "Empty" << std::endl;
    return -1;
  }


}


