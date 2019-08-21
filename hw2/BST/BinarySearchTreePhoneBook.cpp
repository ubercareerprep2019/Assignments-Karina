#include <iostream>
#include "BinarySearchTreePhoneBook.h"

BinarySearchTreePhoneBook::BinarySearchTreePhoneBook(){
  
  PBST *book = new PBST();
  s = 0;
}

int BinarySearchTreePhoneBook::size(){
  return s;
}


void BinarySearchTreePhoneBook::insert(std::string name, long phoneNumber){
  book->insert(std::make_pair(name, phoneNumber));
  s += 1;
}

long BinarySearchTreePhoneBook::find(std::string name){

  return book->find(name);
}


/*
int main(){
  BinarySearchTreePhoneBook *book1 = new BinarySearchTreePhoneBook();
  book1->insert("Steve Jobs", 123);
  book1->insert("Kar", 456);
  book1->insert("Jeff", 789);
  std::cout << book1->find("Jeff") << std::endl;
  }
*/

