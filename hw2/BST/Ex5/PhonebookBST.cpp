#include <iostream>
#include "PhonebookBST.h"
#include "TreeNode.cpp"


PhonebookBST::PhonebookBST(){
  this->root = nullptr;
  //std::cout << "Leaving constructor..." << std::endl;
}

void PhonebookBST::insert(std::pair<std::string, long> p){
  this->insertNode(this->root, p);
}


void PhonebookBST::insertNode(TreeNode<std::pair<std::string, long> >*& r, std::pair<std::string, long> p){
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




long PhonebookBST::find(std::string name){
  if (root == nullptr){
    std::cout << "here" << std::endl;
    return -1;
  }
  else {
    return findNode(root, name);
  }
}

long PhonebookBST::findNode(TreeNode<std::pair<std::string, long> >*& root, std::string name){
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


PhonebookBST::~PhonebookBST(){
  std::cout << "In the destructor: " << std::endl;
}



