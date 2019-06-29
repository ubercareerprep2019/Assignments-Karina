#pragma once
template <typename T> class TreeNode{

 private: 
  T data; 
  TreeNode<T> *left;
  TreeNode<T> *right;

 public:
  //constructors
  TreeNode<T>();
  TreeNode<T>(T data);
  TreeNode<T>(T data, TreeNode<T>* left, TreeNode<T>* right);

  //mutators
  void setLeft(TreeNode<T>* left);
  void setRight(TreeNode<T>* right);
  void setData(T data);
  
  //accessors
  T getData();
  TreeNode<T>* getLeft();
  TreeNode<T>* getRight();
};
