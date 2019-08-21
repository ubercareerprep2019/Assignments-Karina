#include <iostream>
//temporarily including entire file bc of linker error
#include "TreeNode.cpp"
#include "BST.cpp"

int main(){

  std::cout << "1 " << std::endl;
  TreeNode<int> *root = new TreeNode<int> (10);
  std::cout << "2 " << std::endl;
  BST<int> *tree1 = new BST<int> (root);
  std::cout << "3 " << std::endl;
  tree1->insert(16);
  tree1->insert(21);
  tree1->insert(13);
  
  std::cout << tree1->find(13) << std::endl; //T or 1
  std::cout << tree1->find(9) << std::endl; //F or 0
  

  return 0;
}
