#include "Tree.h"
#include <queue>

template <typename T>
Tree<T>::Tree(){
  this->root = nullptr;
}


template <typename T>
Tree<T>::Tree(TreeNode<T>* root){
  this->root = root;
}

//[Trees - Ex1]
//prints the values of the data in all the TreeNodes 
template <typename T>
void Tree<T>::print(TreeNode<T>* root){
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

//Prints tree level by level on one line
template <typename T>
void Tree<T>::printOneLineLevelByLevel(TreeNode<T>* root){
  if (root == nullptr){
    return;
  }

  std::queue<TreeNode<T>*> q;
  q.push(root);

  while(!q.empty()){
    TreeNode<T>* curr = q.front();
    std::cout << curr->getData() << " ";
    if (curr->getLeft() != nullptr){
      q.push(curr->getLeft());
    }

    if (curr->getRight() != nullptr){
      q.push(curr->getRight());
    }

    q.pop();

  }

}

//[Trees - Ex2]
//Prints Tree level by level on separate lines
//Unlike printOneLineLevelByLevel, this uses two queues
template <typename T>
void Tree<T>::printLevelByLevel(TreeNode<T>* root){
  if (root==nullptr){
    return;
  }

  std::queue<TreeNode<T>*> q1;
  std::queue<TreeNode<T>*> q2;
  
  q1.push(root);

  while(!(q1.empty() && q2.empty())){
    if(q1.empty()){
      while(!q2.empty()){
	TreeNode<T>* curr = q2.front();
	q2.pop();
	if (curr->getLeft() != nullptr){
	  q1.push(curr->getLeft());
	}
	if (curr->getRight() != nullptr){
	  q1.push(curr->getRight());
	}
	std::cout << curr->getData() << " ";
      }
      std::cout << "\n";
  }
    else {
      while(!q1.empty()){
	TreeNode<T>* curr = q1.front();
	q1.pop();
	if (curr->getLeft() != nullptr){
	  q2.push(curr->getLeft());
	}
	if (curr->getRight() != nullptr){
	  q2.push(curr->getRight());
	}
	std::cout << curr->getData() << " ";
      }
      std::cout << "\n";
    }
  }
}


//[Trees - Ex3]
//Uses similar logic to printLevelByLevel for counting levels
template <typename T>
void Tree<T>::printNumLevels(TreeNode<T>* root){
  std::queue<TreeNode<T>*> q1; 
  std::queue<TreeNode<T>*> q2; 
  int level_counter = 0;
  if (root == nullptr){
    std::cout << 0 << std::endl;
    return;
  }

  q1.push(root);

  while(!(q1.empty() && q2.empty())){

    if (!(q1.empty())){
	while(!(q1.empty())){
	  TreeNode<T>* curr = q1.front();

	  if (curr->getLeft() != nullptr){
	    q2.push(curr->getLeft());
	  }
	  if (curr->getRight() != nullptr){
	    q2.push(curr->getRight());
	  }
	  q1.pop();
	}
	  level_counter += 1;
      }
      else {
	while(!(q2.empty())){
	  TreeNode<T>* curr = q2.front();

	  if (curr->getLeft() != nullptr){
	    q1.push(curr->getLeft());
	  }
	  if (curr->getRight() != nullptr){
	    q1.push(curr->getRight());
	  }
	  q2.pop();
	}
       level_counter += 1;
      }
  }
  std::cout << "num levels: " << std::endl;
 std::cout << level_counter << std::endl;
}
	
	

	
	  
