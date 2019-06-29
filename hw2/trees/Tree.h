#include <iostream>
#include "TreeNode.h"

template <typename T> class Tree{
 private:
  TreeNode<T>* root;

 public:
  Tree<T> ();
  Tree<T> (TreeNode<T>* root);
  void print(TreeNode<T>* root);
};


