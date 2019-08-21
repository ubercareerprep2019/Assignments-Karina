#include <iostream>
#include "PBST.h"
#include "TreeNode.cpp"


PBST::PBST(){
  this->root = nullptr;
  //std::cout << "Leaving constructor..." << std::endl;
}

void PBST::insert(std::pair<std::string, long> p){
  this->insertNode(this->root, p);
}


void PBST::insertNode(TreeNode<std::pair<std::string, long> >*& r, std::pair<std::string, long> p){
  if (r == nullptr){
    r = new TreeNode<std::pair<std::string, long> >(p);
  }

  else if (p.first[0] >= r->getData().first[0]){
    this->insertNode(r->right, p);
  }
  else{
    this->insertNode(r->left, p);
  }
}




long PBST::find(std::string name){
  if (root == nullptr){
    std::cout << "here" << std::endl;
    return -1;
  }
  else {
    return findNode(root, name);
  }
}

long PBST::findNode(TreeNode<std::pair<std::string, long> >*& root, std::string name){
  //we've passed a leaf
  if (root == nullptr){
    return -1;
  }
  std::pair<std::string, long> curr = root->getData();
  if (curr.first == name){
   return curr.second;
  }

  else if (name[0] >= curr.first[0]){
    return findNode(root->right, name);
  }
    
  else {
    return findNode(root->left, name);
  }
}


PBST::~PBST(){
  std::cout << "In the destructor: " << std::endl;
}

/*
int main(){

  PBST *bookTree = new PBST();
  
  person bob;
  bob.name="Bob";
  bob.number=12345;

  person steve;
  steve.name="Steve Jobs";
  steve.number = 156435;

  person ana;
  ana.name= "Anabeth Brown";
  ana.number=347656789;

  bookTree->insert(bob);
  bookTree->insert(steve);
  bookTree->insert(ana);
  std::cout << bookTree->find("Bob") <<std::endl; //12345
  std::cout << bookTree->find("Steve Jobs") <<std::endl; //156435
  std::cout << bookTree->find("Larry David") <<std::endl; //-1

}
*/
