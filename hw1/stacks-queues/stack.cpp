#include <iostream>
#include "stack.h"


//index 0 stores the int while index 1 stores info about the next min
stack::stack(){
  size = 0;
  t = -1;
}

bool stack::isEmpty(){
  return size==0;
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

void stack::debug_string(){
  std::cout << "size: " << size << std::endl;
  std::string s = "[ ";
  for (int i=0; i < size; i++){
    s += std::to_string(arr[i]) + ", ";
  }

  std::cout << s.substr(0, s.length() -2) << " ]" << std::endl;
}

