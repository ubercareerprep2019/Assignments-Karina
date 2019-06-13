#pragma once
#define cap 10

class stack {

 private:
  int arr[cap];
  int size;
  int t; //tracking top
  int min0;
  int min1;
 public:
  //default size is 10
  stack();
  int pop();
  void push(int n);
  int top();
  bool isEmpty();
  std::string debug_string();
};
