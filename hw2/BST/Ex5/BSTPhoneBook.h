#pragma once
#include "PhonebookBST.cpp"
#include <string>

class BSTPhoneBook{

 private:

  //tree has names
  PhonebookBST *book = new PhonebookBST();
  int s;

 public:
  
  BSTPhoneBook();
  int size();
  void insert(std::string name, long phoneNumber);
  long find(std::string name);
  std::string toString();

};
