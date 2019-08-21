#pragma once
#include <vector>
#include <string>

class ListPhoneBook{
 // book = [ <string, long> ]
 private:
  std::vector<std::pair<std::string, long> > book;

  int s;

 public:
  
  ListPhoneBook();
  int size();
  void insert(std::string name, long phoneNumber);
  long find(std::string name);
  std::string toString();

};
