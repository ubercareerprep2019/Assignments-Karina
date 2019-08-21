#include <iostream>
#include <vector>

//TO DO: ADD MAKEFILE BECAUSE MAIN REQUIRES -STD=C++11 FLAG

int dfs(std::vector<std::vector<bool> > &islandMap, int r, int c){

  if (r < 0 || r >= islandMap.size() || c >= islandMap.at(0).size() || c < 0 || islandMap.at(r).at(c) == 0){
      return 0;
  }

  //std::cout << "here" << "r= " << r << " c=" << c << std::endl;
  islandMap.at(r).at(c) = false;
  dfs(islandMap, r+1, c);
  dfs(islandMap, r, c+1);
  dfs(islandMap, r-1, c);
  dfs(islandMap, r, c-1);
  return 1;

}


int nmOfIslands(std::vector<std::vector<bool> > &islandMap){

  if (islandMap.size() == 0 || islandMap.at(0).size() == 0){
    return -1;
  }

  int numIslands = 0;

  for (int r = 0; r < islandMap.size(); r++){
    for (int c = 0; c < islandMap.at(0).size(); c++){
      if (islandMap[r][c]){
	//std::cout << "Returning dfs(islandMap, " << r << ", " << c << ")" << std::endl; 
	numIslands += dfs(islandMap, r, c);
      }
    }
  }

  return numIslands;

}


int main(){

  // 1 1 0 0
  // 1 1 0 1
  // 0 0 0 0
  // 1 1 1 1

  //3 islands

  std::vector<std::vector<bool> > myMap(4);
  std::vector<bool> row1 {1,1,0,0};
  std::vector<bool> row2 {1,1,0,1};
  std::vector<bool> row3 {0,0,0,0};
  std::vector<bool> row4 {1,1,1,1};

  myMap = {row1, row2, row3, row4};

  std::cout << nmOfIslands(myMap) << std::endl;


}
