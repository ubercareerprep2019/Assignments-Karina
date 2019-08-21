#include <iostream>
#include "ListPhoneBook.cpp"
#include <fstream>
#include "BinarySearchTreePhoneBook.cpp"
#include <chrono>

int main(){
  ListPhoneBook listBook = ListPhoneBook();
  BinarySearchTreePhoneBook *binaryTreeBook = new BinarySearchTreePhoneBook();
  std::string fileName = "data.csv";
  std::ifstream file(fileName);
  std::string line;
  char delim = ',';
  

  auto begin = std::chrono::high_resolution_clock::now();

  while (std::getline(file, line)){
    int pos = line.find(delim);
    std::string name = line.substr(0, pos);
    //stoll converts string to long
    long num = std::stoll(line.substr(pos+1));
    listBook.insert(name, num);
  };


  auto end = std::chrono::high_resolution_clock::now();    
  auto dur = end - begin;
  auto ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();


  std::cout << "Insert took  " << ms1 << " milliseconds." << std::endl;   
  std::cout << "The size of the PhoneBook is " << listBook.size() << "." << std::endl; 
  

  std::ifstream file2("search.txt");
  int findCtr = 0;

  //setting up new chrono object
  auto begin2 = std::chrono::high_resolution_clock::now();


  while (std::getline(file2, line)){

    listBook.find(line);
    findCtr += 1;
   }
 
  auto end2 = std::chrono::high_resolution_clock::now();    
  auto dur2 = end2 - begin2;
  auto ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(dur2).count();
  std::cout << "find() was called " << findCtr << " times." << std::endl;
  std::cout << "Search took " << ms2 << " milliseconds." << std::endl;
  
} //end main
