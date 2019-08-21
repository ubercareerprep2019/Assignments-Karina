#pragma once
#include "TreeNode.h"
template <typename T> class BST {

 private:
  TreeNode<T>* root;
  void insertNode(TreeNode<T> *root, T data);
  bool findNode(TreeNode<T> *root, T data);

 public:
  //constructors
  BST<T> ();
  BST<T> (TreeNode<T>* root);

  //destructor
  ~BST<T>();

  void insert(T data);
  bool find(T data);
  
};
