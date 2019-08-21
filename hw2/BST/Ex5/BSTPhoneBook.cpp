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


int main(){
  BSTPhoneBook *book1 = new BSTPhoneBook();
  book1->insert("Steve Jobs", 123);
  book1->insert("Kar", 456);
  book1->insert("Jeff", 789);
  std::cout << book1->find("Jeff") << std::endl;
  std::cout << book1->find("Kar") << std::endl;
  std::cout << book1->find("Steve Jobs") << std::endl;
  std::cout << book1->find("Jeve Stobs") << std::endl;

  }


