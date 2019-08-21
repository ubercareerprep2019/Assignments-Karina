#include <iostream>
#include "ListPhoneBook.h"
#include <string>

ListPhoneBook::ListPhoneBook(){
  s = 0;
}

int ListPhoneBook::size(){
  return s;
}


void ListPhoneBook::insert(std::string name, long phoneNumber){
  
  std::pair<std::string, long> toAdd = std::make_pair(name, phoneNumber);

  book.push_back(toAdd);

  s += 1;

  //std::cout << "pushed" << std::endl;
}

std::string ListPhoneBook::toString(){

  std::string ret="";

  for(int i=0; i<s; i++){
    ret += "{ name: ";
    ret += book.at(i).first;
    ret += ", phoneNumber: ";
    //std::cout << "NUM: " << book.at(i).second << std::endl;
    ret += std::to_string(book.at(i).second);
    ret +=" }";
    ret += "\n";
  }

  return ret;
}

long ListPhoneBook::find(std::string name){

  if (s==0){
    return -1;
  }

  for(int i=0; i<s; i++){
    if (name == book.at(i).first){
      return book.at(i).second;
    }
  }
    
    return -1;

}


int main() {

  ListPhoneBook book1 = ListPhoneBook();
  
  book1.insert("Steve Jobs" , 12345678);
  book1.insert("Marie Curie" , 3333333);

  std::cout << book1.toString() << std::endl;
  std::cout << book1.size() << std::endl;

  std::cout << std::to_string(book1.find("Marie Curie")) << std::endl; //333333
  std::cout << book1.find("George Washington") << std::endl; //-1

}

