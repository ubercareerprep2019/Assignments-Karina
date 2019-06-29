#include <iostream>
#include "TreeNode.h"
#include <string>

template <typename T> class Tree{
 private:
  TreeNode<T>* root;

 public:
  Tree<T> ();
  Tree<T> (TreeNode<T>* root);
  void print(TreeNode<T>* root);
  void printOneLineLevelByLevel(TreeNode<T>* root);
  void printLevelByLevel(TreeNode<T>* root);
};


