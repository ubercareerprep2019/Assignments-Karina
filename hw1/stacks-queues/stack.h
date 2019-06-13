#pragma once
#define cap 10

class stack {

 private:
  int arr[cap];
  int size;
  int t; //tracking top

 public:
  //default size is 10
  stack();
  int pop();
  void push(int n);
  int top();
  bool isEmpty();
  std::string debugString();
};


class minStack {

 private:
  stack m = stack();
  stack s = stack();

 public:
  
  minStack();
  int pop();
  void push(int n);
  int top();
  bool isEmpty();
  std::string debugString();
  int minVal();

};
