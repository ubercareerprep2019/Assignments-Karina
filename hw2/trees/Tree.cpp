#include "Tree.h"

template <typename T>
Tree<T>::Tree(){
  this->root = nullptr;
}


template <typename T>
Tree<T>::Tree(TreeNode<T>* root){
  this->root = root;
}

template <typename T>
void Tree<T>::print(TreeNode<T>* root){
  //std::cout <<"ROOT: " << root->getData() << std::endl;
  if (root == nullptr) {
    return;
  }
    std::cout << root->getData() << " ";
    if (root->getLeft() != nullptr){
      this->print(root->getLeft());
    }
    if (root->getRight() != nullptr){
      this->print(root->getRight());
    }
    
}




