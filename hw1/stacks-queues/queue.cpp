#include <iostream>
#include "queue.h"

queue::queue(){
  std::cout<< "in the constructor" << std::endl;
  size = 0;
}

void queue::enqueue(int num){

  //if num is the first value, we can just push it to s1
  if (s1.isEmpty()) {
    s1.push(num);
    size += 1;
    return;

  }

  else {
  //otherwise push every value in s1 onto s2, and then push num
  while (!s1.isEmpty()){
    int popped = s1.top();
    s1.pop();
    s2.push(popped);
  }
  s2.push(num);
  
  int p;
  while (!s2.isEmpty()){
    p = s2.top();
    s2.pop();
    s1.push(p);
  }

  size += 1;
  return;
  }
}



int queue::dequeue(){

  if (size == 0){
    return -1;
  }

  else {
    int ret = s1.pop();
    size -=1; 
    return ret;
  }
}
