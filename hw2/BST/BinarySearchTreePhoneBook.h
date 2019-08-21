#pragma once
#include "PBST.cpp"
#include <string>

class BinarySearchTreePhoneBook{

 private:

  //tree has names
  PBST *book = new PBST();
  int s;

 public:
  
  BinarySearchTreePhoneBook();
  int size();
  void insert(std::string name, long phoneNumber);
  long find(std::string name);
  std::string toString();

};
