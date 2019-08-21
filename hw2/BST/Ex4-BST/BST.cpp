#include <iostream>
#include "BST.h"

template <typename T>
BST<T>::BST(){
  this->root = nullptr;
}


template <typename T>
BST<T>::BST(TreeNode<T>* root){
  this->root = root;
}

//[Trees - Ex4]
//public insert method
template <typename T>
void BST<T>::insert(T data){
  if (this->root == nullptr){
    TreeNode<T> *root = new TreeNode<T>(data);
    this-> root = root;
    return;
  }
  return insertNode(root, data);
}

//private insert helper method 
template <typename T>
void BST<T>::insertNode(TreeNode<T> *root, T data){
  std::cout << "root is: " << root->getData() << std::endl;
  std::cout << "data: " << data << std::endl;
  //data is greater or equal to root, belongs on the right
  if (data >= root->getData()){
    //reached a leaf, setting to the right of the leaf
    if (root->getRight() == nullptr){
      TreeNode<T> *newNode = new TreeNode<T>(data);
      root->setRight(newNode);
      return;
    }
    else {
      return insertNode(root->getRight(), data);
    }
  }
  if (root->getLeft() == nullptr){
  TreeNode<T> *newNode = new TreeNode<T>(data);
    root->setLeft(newNode);
    return;
  }
  else {
    return insertNode(root->getLeft(), data);
  }
}

//[Trees - Ex4]
template <typename T>
bool BST<T>::find(T data){
  if (root == nullptr){
    return false;
  }
  else {
    return findNode(root, data);
  }
}

//private find helper method
template <typename T>
bool BST<T>::findNode(TreeNode<T> *root, T data){
  if (root == nullptr){
    return false;
  }
  T curr = root->getData();
  if (curr == data){
    return true;
  }

  else if (data >= curr){
    return findNode(root->getRight(), data);
  }
    
  else {
    return findNode(root->getLeft(), data);
  }
}

template <typename T>
BST<T>::~BST(){
  std::cout << "In the destructor: " << std::endl;
}
