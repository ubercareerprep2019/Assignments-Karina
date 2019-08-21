#include <iostream>
#include <string>

class GraphNode{

public:

  int data;
  GraphNode(int data);


  //hashmap requires operator for GraphNode type
  //write about this!
  bool operator<(const GraphNode& node) const
  {
     //Return true if this is less than loc2
    return data < node.data;
  }

  //comparison operator later used in hashmap
  bool operator==(const GraphNode& node) const
  {
    return data == node.data;
  }

};

GraphNode::GraphNode(int data){
  this->data = data;
};

