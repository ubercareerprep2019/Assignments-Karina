#include <iostream>
#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(){
  setLeft(nullptr);
  setRight(nullptr);
}

template <typename T>
TreeNode<T>::TreeNode(T data){
  setData(data);
  setLeft(nullptr);
  setRight(nullptr);
}

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode<T>* left, TreeNode<T>* right){
  setLeft(left);
  setRight(right);
}

template <typename T>
void TreeNode<T>::setData(T data){
  this->data = data;
}

template <typename T>
T TreeNode<T>::getData(){
  return this->data;
}

template <typename T>
void TreeNode<T>::setLeft(TreeNode<T>* left){
  this->left = left;
}

template <typename T>
void TreeNode<T>::setRight(TreeNode<T>* right){
  this->right = right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::getRight(){
  return this->right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::getLeft(){
  return this->left;
}




