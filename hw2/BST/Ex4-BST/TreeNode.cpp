#include <iostream>
#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(){
  this->setLeft(nullptr);
  this->setRight(nullptr);
}

template <typename T>
TreeNode<T>::TreeNode(T data){
  this->data = data;
  this->left = nullptr;
  this->right =nullptr;
}


template <typename T>
void TreeNode<T>::setData(T data){
  this->data = data;
}

template <typename T>
T TreeNode<T>::getData(){
  return this->data;
}


template<typename T>
void TreeNode<T>::setLeft(TreeNode<T>* left){
  this->left = left;
}

template<typename T>
void TreeNode<T>::setRight(TreeNode<T>* right){
  this->right = right;
}

template<typename T>
void TreeNode<T>::set(TreeNode<T>* Node){
  this->setData(Node->getData());
  this->setRight(Node->getRight());
  this->setLeft(Node->getLeft());
}


template<typename T>
TreeNode<T>* TreeNode<T>::getLeft(){
  return this->left;
}


template<typename T>
TreeNode<T>* TreeNode<T>::getRight(){
  return this->right;
}
