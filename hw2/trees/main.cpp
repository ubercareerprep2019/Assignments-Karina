#include <iostream>
#include "Tree.cpp"
#include "TreeNode.cpp"
#include <string>

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
  std::cout << "\n\n";

  tree1->printLevelByLevel(n1);

  std::cout << "\n\n";

  TreeNode<std::string> *p1 = new TreeNode<std::string>("A");
   TreeNode<std::string> *p2 = new TreeNode<std::string>("B");
  TreeNode<std::string> *p3 = new TreeNode<std::string>("C");
  TreeNode<std::string> *p4 = new TreeNode<std::string>("I");
  TreeNode<std::string> *p5 = new TreeNode<std::string>("D");
  TreeNode<std::string> *p6 = new TreeNode<std::string>("E");
  TreeNode<std::string> *p7 = new TreeNode<std::string>("J");
  TreeNode<std::string> *p8 = new TreeNode<std::string>("F");
  TreeNode<std::string> *p9 = new TreeNode<std::string>("G");
  TreeNode<std::string> *p10 = new TreeNode<std::string>("H");
  TreeNode<std::string> *p11 = new TreeNode<std::string>("K");

  p1->setLeft(p2);
  p2->setLeft(p4);
  p4->setLeft(p7);
  p7->setLeft(p11);
  

  p1->setRight(p3);
  p3->setLeft(p5);
  p3->setRight(p6);
  p5->setLeft(p8);
  p5->setRight(p10);

  Tree<std::string> *tree2 = new Tree<std::string> (p1);
  tree2->printLevelByLevel(p1);
  std::cout << std::endl;

  tree2->printNumLevels(p1);

  return 0;
}
