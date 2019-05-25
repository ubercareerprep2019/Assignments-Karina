#pragma once
#define capacity 10

class stack {

 private:
  int arr[capacity];
  int size;
  int t; //tracking top
 public:
  //default size is 10
  stack();
  int pop();
  void push(int n);
  int top();
  bool isEmpty();
};
