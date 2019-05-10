#include <iostream>
#include <vector>

//takes two strings and returns true if one string is a permutation of the other, false otherwise

//this method compares the sum of the ascii char summation of each string, which makes it a case-sensitive comparison? 

bool isStringPermutation(std::string s1, std::string s2){
  if (s1.length() != s2.length()){
    return false;
  }

  //sum of ASCII values of s1 chars:
  int sum1 = 0;
  for (int i=0; i < s1.length(); i++){
    sum1 += int(s1[i]);
  }

  int sum2 = 0;
  for (int i=0; i <s2.length(); i++){
    sum2 += int(s2[i]);
  }

  return sum1 == sum2;
}

//returns an array of all pairs of integers from the input array whose sum equals the target

//TO DO: Optomize to O(n) using a hashset?

std::vector<std::pair<int, int> > pairsThatEqualSum(std::vector<int> inputArray,  int targetSum){
  
  //declaring vector to be returned
  std::vector<std::pair<int, int> > ret;

  //O(n^2):
  for (int i = 0; i < inputArray.size() - 1; i++){
    for (int j = i + 1; j < inputArray.size(); j++){
      if (targetSum - inputArray[i] == inputArray[j]){
	std::pair<int, int> p;
	p.first = inputArray[i];
	p.second = inputArray[j];
	ret.push_back(p);
      }
    }
  }
  return ret;
}


int main(){
  //test cases fxn1
  std::cout << isStringPermutation("hello", "olehl") << std::endl; //true
  std::cout << isStringPermutation("hello", "world") << std::endl; //false

  //test cases fxn2
  std::vector<int> param1;
  param1.push_back(0);
  param1.push_back(1);
  param1.push_back(2);
  param1.push_back(3);
  param1.push_back(4);
  param1.push_back(5);

  
  std::vector<std::pair<int, int> > ans = pairsThatEqualSum( param1, 5); 
  //(1,4), (2,3), (5,0)

  for (int i=0; i < ans.size(); i++){
    std::cout << "--------" << std::endl;
    std::cout << "(" << ans.at(i).first << ", " << ans.at(i).second << ")" << std::endl;
  }
  
  
  return 0;
}
