#include <iostream>
#include "Tree.cpp"
#include "TreeNode.cpp"

int main() {
  TreeNode<int> *n1 = new TreeNode<int> (1);
  TreeNode<int> *n2 = new TreeNode<int> (7);
  TreeNode<int> *n3 = new TreeNode<int> (17);
  n1->setLeft(n2);
  n1->setRight(n3);
  TreeNode<int> *n4 = new TreeNode<int> (6);
  TreeNode<int> *n5 = new TreeNode<int> (3);
  n3->setLeft(n4);
  n3->setRight(n5);
  Tree<int> *tree1 = new Tree<int> (n1);

  tree1->print(n1); // 1 7 17 6 3
  std::cout << "\n";

  return 0;
}
