#include <iostream>
#include "BST.h"

template <typename T>
BST<T>::BST(){
  
  this->root = nullptr;
  std::cout << "Leaving constructor..." << std::endl;
}


template <typename T>
BST<T>::BST(TreeNode<T>* root){
  this->root = root;
  std::cout << "Leaving constructor..." << std::endl;
}

template <typename T>
void BST<T>::insert(T data){
  std::cout << "TYPE IS: " << typeid(data) << std::endl;
  if (this->root == nullptr){
    TreeNode<T> *root = new TreeNode<T>(data);
    this-> root = root;
    return;
  }
  std::cout << "Running insertNode(root, data)" << std::endl;
  return insertNode(root, data);
}

template <typename T>
void BST<T>::insertNode(TreeNode<T> *root, T data){
  std::cout << "root is: " << root->getData() << std::endl;
  std::cout << "data: " << data << std::endl;
  //vall is greater or equal to root, belongs on the right
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

template <typename T>
bool BST<T>::find(T data){
  if (root == nullptr){
    return false;
  }
  else {
    return findNode(root, data);
  }
}

template <typename T>
bool BST<T>::findNode(TreeNode<T> *root, T data){
  //we've passed a leaf
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
