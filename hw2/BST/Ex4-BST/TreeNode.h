#pragma once
template <typename T> class TreeNode {

 private:
  T data;

  
 public:
  
  //moving here to optimize tree operations
  TreeNode<T> *left; 
  TreeNode<T> *right;
  //constructors
  TreeNode<T>();
  TreeNode<T>(T data);
  
  //mutators
  void setLeft(TreeNode<T> *left);
  void setRight(TreeNode<T> *right);
  void set(TreeNode<T>* Node);
  void setData(T data);

  //accessors
  T getData();
  TreeNode<T>* getRight();
  TreeNode<T>* getLeft();


};
