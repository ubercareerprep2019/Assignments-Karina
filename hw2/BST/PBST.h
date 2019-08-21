#pragma once
#include "TreeNode.h"

class PBST {
 private:
  TreeNode<std::pair<std::string, long> >* root = new TreeNode<std::pair<std::string, long> >();
  void insertNode(TreeNode<std::pair<std::string, long> >*& r, std::pair<std::string, long> p);
  long findNode(TreeNode<std::pair<std::string, long> >*& root, std::string name);

 public:
  //constructors
  PBST ();

  //destructor
  ~PBST();

  void insert(std::pair<std::string, long> p);
  long find(std::string name);
  
};
