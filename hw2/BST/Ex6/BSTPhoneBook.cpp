#include <iostream>
#include "BSTPhoneBook.h"

BSTPhoneBook::BSTPhoneBook(){
  
  PhonebookBST *book = new PhonebookBST();
  s = 0;
}

int BSTPhoneBook::size(){
  return s;
}


void BSTPhoneBook::insert(std::string name, long phoneNumber){
  book->insert(std::make_pair(name, phoneNumber));
  s += 1;
}

long BSTPhoneBook::find(std::string name){

  return book->find(name);
}


