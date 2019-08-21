#include <iostream>
#include <map>
#include <vector>
#include "GraphNode.cpp"
#include <string>
#include <set>
#include <stack>
#include <queue>

class GraphWithAdjacencyList{

private:
  //adjNodes is a hashmap of GraphNodes and vectors of GraphNodes 
  std::map<GraphNode, std::vector<GraphNode > > adjNodes;

public:
  void addNode(int key);
  void removeNode(int key);
  void printList(int key);
  void addEdge(int node1, int node2);
  void removeEdge(int node1, int node2);
  std::vector<GraphNode> getAdjNodes(int key);
  void DFS(int key);
  void BFS(int key);
  int minNumberOfEdges(int node1, int node2);
};

void GraphWithAdjacencyList::addNode(int key){
  GraphNode newNode = GraphNode(key);
  if (adjNodes.find(newNode) != adjNodes.end()){
    std::cout << key << " already exists " << std::endl;
    return;
  }
  std::vector<GraphNode> newVec;
  adjNodes[newNode] = newVec;
  //std::cout << "size is " << adjNodes.size() << std::endl;
}

void GraphWithAdjacencyList::removeNode(int key){
  std::cout << "removing " << key << "..." <<  std::endl;
  if (adjNodes.empty()){
    std::cout << "can't remove from empty map" << std::endl;
    return;
  }
  GraphNode node = GraphNode(key);
  adjNodes.erase(node);
}

void GraphWithAdjacencyList::printList(int key){
  GraphNode node = GraphNode(key);
  if (adjNodes.find(node) == adjNodes.end()) {
    std::cout << key << " doesn't exist" << std::endl;
    return;
  }

  std::vector<GraphNode> print;
  
  print = getAdjNodes(key); 
  std::cout << "key: " << key << " ";
  std::cout << "{ ";
  for (int i=0; i< print.size(); i++){
    std::cout << print.at(i).data << ", ";
  }
  std::cout << " }" << std::endl;
}

void GraphWithAdjacencyList::addEdge(int node1, int node2){

  GraphNode n1 = GraphNode(node1);
  GraphNode n2 = GraphNode(node2);
  
  //one or both values are not in adjNodes
  if (adjNodes.find(n1) == adjNodes.end() || adjNodes.find(n1) == adjNodes.end()){
    std::cout << "make sure values exist" << std::endl;
    return;
  }

  
  //no repeating edges:
  //update value in existing map if it's not already in the vector
  if (std::find(adjNodes[n1].begin(), adjNodes[n1].end(), n2) == adjNodes[n1].end()){
    adjNodes[n1].push_back(n2);
  }

  if (std::find(adjNodes[n2].begin(), adjNodes[n2].end(), n1) == adjNodes[n2].end()){
    adjNodes[n2].push_back(n1);
  }
}

void GraphWithAdjacencyList::removeEdge(int node1, int node2){
  GraphNode n1 = GraphNode(node1);
  GraphNode n2 = GraphNode(node2);
  
  //one or both values are not in adjNodes
  if (adjNodes.find(n1) == adjNodes.end() || adjNodes.find(n1) == adjNodes.end()){
    std::cout << "make sure values exist" << std::endl;
    return;
  }

  //removing if exists in vector:

  if (std::find(adjNodes[n1].begin(), adjNodes[n1].end(), n2) != adjNodes[n1].end()){
    //std::vec.erase(remove(vec.begin(), vec.end(), value)) 
    //is known as the erase-remove idiom and is a removal by value method in c++
    adjNodes[n1].erase(std::remove(adjNodes[n1].begin(), adjNodes[n1].end(), n2));
  }

  if (std::find(adjNodes[n2].begin(), adjNodes[n2].end(), n1) != adjNodes[n2].end()){
    //erase-remove idiom
    adjNodes[n2].erase(std::remove(adjNodes[n2].begin(), adjNodes[n2].end(), n1));
  }

}

void GraphWithAdjacencyList::DFS(int key){
  
  if (adjNodes.empty()){
    std::cout<< "empty" << std::endl;
    return;
  }

  std::stack<GraphNode> s;
  GraphNode first = GraphNode(key);
  s.push(first);
  //tracking nodes we've already visited:
  std::set<GraphNode> visited;
  while(!s.empty()){
    GraphNode curr = s.top();
    s.pop();
    //std::cout << "not visited yet: " << (visited.find(curr) == visited.end()) << std::endl;
    //if we haven't visited it yet
    if (visited.find(curr) == visited.end()){
      std::cout << curr.data << " ";
      visited.insert(curr);
    }
  
    std::vector<GraphNode> currVecList = adjNodes[curr];
    for (int i=0; i < currVecList.size(); ++i){
      if(visited.find(currVecList.at(i)) == visited.end()){
	    s.push(currVecList.at(i));
	    //std::cout << "just pushed " << currVecList.at(i).data << std::endl;
      }
    }
  }
  std::cout << std::endl;
}


void GraphWithAdjacencyList::BFS(int key){

  if (adjNodes.empty()){
    std::cout<< "empty" << std::endl;
    return;
  }

  std::queue<GraphNode> q;
  GraphNode first = GraphNode(key);
  q.push(first);
  //tracking nodes we've already visited:                                                 
  std::set<GraphNode> visited;

  while(!q.empty()){
    GraphNode curr = q.front();
    q.pop();

  if (visited.find(curr) == visited.end()){
    std::cout << curr.data << " ";
    visited.insert(curr);
  }

    std::vector<GraphNode> currVecList = adjNodes[curr];
    for (int i=0; i < currVecList.size(); ++i){
      if(visited.find(currVecList.at(i)) == visited.end()){
	q.push(currVecList.at(i));
	//std::cout << "just pushed " << currVecList.at(i).data << " ";         
      }
    }
  }
  std::cout << std::endl;
}

int GraphWithAdjacencyList::minNumberOfEdges(int node1, int node2){

  if (adjNodes.empty()){
    std::cout<< "empty" << std::endl;
    return -1;
  }

  std::queue<GraphNode> q;
  GraphNode first = GraphNode(node1);
  q.push(first);

  //tracking nodes we've already visited:                                                 
  std::set<GraphNode> visited;
  std::map<GraphNode, int> numEdges;
  numEdges[first] = 0; 
  while(!q.empty()){
    GraphNode curr = q.front();
    q.pop();
    

  if (visited.find(curr) == visited.end()){
    // std::cout << curr.data << " ";
    visited.insert(curr);
  }

    std::vector<GraphNode> currVecList = adjNodes[curr];
    for (int i=0; i < currVecList.size(); ++i){
      if(visited.find(currVecList.at(i)) == visited.end()){
	q.push(currVecList.at(i));
	if (currVecList.at(i).data == node1){
	  return numEdges[curr] + 1;
	}
	numEdges[currVecList.at(i)] = numEdges[curr] + 1;
	//std::cout << "just pushed " << currVecList.at(i).data << " ";         
      }
    }
  }
  return numEdges[node2];
}





std::vector<GraphNode> GraphWithAdjacencyList::getAdjNodes(int key){
  GraphNode node = GraphNode(key);
  std::vector<GraphNode> ret;
  if (adjNodes.find(node) == adjNodes.end()) {
    std::cout << key << " doesn't exist" << std::endl;
    return ret;
  }
  ret = adjNodes[node];
  return ret;
}

int main(){

  GraphWithAdjacencyList myMap = GraphWithAdjacencyList();
  /*
  myMap.addNode(5);
  myMap.printList(5);
  myMap.addNode(5);
  myMap.removeNode(5);
  myMap.printList(4);

  myMap.addNode(5);
  myMap.addNode(15);

  myMap.addEdge(5, 15);
  myMap.addEdge(15,5);

  myMap.printList(5);
  myMap.printList(15);

  myMap.removeEdge(15, 5);
  myMap.printList(5);


  myMap.addNode(38);
  myMap.addNode(47);
  myMap.addEdge(5, 15);
  myMap.addEdge(5, 38);
  myMap.addEdge(38, 47);
  myMap.addEdge(5, 47);
  std::cout << std::endl;
  
  std::cout << "testing DFS..." << std::endl;
  myMap.printList(5); //15, 18 woot
  myMap.printList(15);
  myMap.printList(38);
  myMap.printList(47);
  myMap.DFS(5);
  */
  GraphWithAdjacencyList g = GraphWithAdjacencyList();

  g.addNode(1);
  g.addNode(2);
  g.addNode(3);
  g.addNode(4);
  g.addNode(5);
  
  g.addEdge(1, 3); 
  g.addEdge(1, 2); 
  g.addEdge(2, 4); 
  g.addEdge(2, 5); 
  
  std::cout << "Following is Depth First Traversal\n"; 
  g.DFS(1); 
  g.BFS(1); 
  std::cout << g.minNumberOfEdges(3, 5) << std::endl; //3
  std::cout << g.minNumberOfEdges(2, 4) << std::endl; //1
  std::cout << g.minNumberOfEdges(1, 5) << std::endl; //2
}
