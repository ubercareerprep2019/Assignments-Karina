#pragma once
#include "stack.h"

class queue {

 private:
  stack s1 = stack(); //will contain the real values
  stack s2 = stack(); //will be a placeholder for operations like enqueue and dequeue
  int size;

 public:
  //default size is 10
  queue();
  void enqueue(int num);
  int dequeue();
  std::string debug_string();
};
