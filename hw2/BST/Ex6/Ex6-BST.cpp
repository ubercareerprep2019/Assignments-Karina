#include <iostream>
#include <fstream>
#include "BSTPhoneBook.cpp"
#include <chrono>

int main(){

  BSTPhoneBook *binaryTreeBook = new BSTPhoneBook();
  std::string fileName = "data.csv";
  std::ifstream file(fileName);
  std::string line;
  char delim = ',';
  int ctr1 = 0;

  auto begin = std::chrono::high_resolution_clock::now();
  while (std::getline(file, line) && ctr1 < 25000){
    //getting arguments
    int pos = line.find(delim);
    std::string name = line.substr(0, pos);
    long num = std::stoll(line.substr(pos+1));

    binaryTreeBook->insert(name, num);
    ctr1 += 1;
  };

  auto end = std::chrono::high_resolution_clock::now();    
  auto dur = end - begin;
  auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();


  std::cout << "Insert took  " << ms1 << " milliseconds." << std::endl;
  std::cout << "The size of the PhoneBook is " << binaryTreeBook->size() << "." << std::endl;


  std::ifstream file2("search.txt");
  int findCtr = 0;

  auto begin2 = std::chrono::high_resolution_clock::now();
  while (std::getline(file2, line)){
  binaryTreeBook->find(line);
  findCtr += 1;
 }

  auto end2 = std::chrono::high_resolution_clock::now();    
  auto dur2 = end2 - begin2;
  auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(dur2).count();

  std::cout << "find() was called " << findCtr << " times." << std::endl;
  std::cout << "Search took " << ms2 << " milliseconds." << std::endl;
  
} //end main

