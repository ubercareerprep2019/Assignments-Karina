#include <iostream>
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_set>   
//takes two strings and returns true if one string is a permutation of the other, false otherwise


//Orignially, I used two for-loops to find the sum of the ascii values of every character in each string and retrned sum1 == sum2. However, I then realized that this method doesn't work because the sums of different characters can yield the same sums (ie: 'a' + 'r', or 97 + 114 ==  100 + 111 or 'd' + 'o.)'

//Instead I stored the ascii values in two vectors, sorted the vectors, and checked if they're the same. This is nlog(n)
bool isStringPermutation(std::string s1, std::string s2){
  if (s1.length() != s2.length()){
    return false;
  }
  
  std::vector<int> v1 = std::vector<int>();
  std::vector<int> v2 = std::vector<int>();

  for (int i=0; i < s1.length(); i++){
    v1.push_back(int(s1[i]));
    v2.push_back(int(s2[i]));
  }

  std::sort(v1.begin(), v1.begin()+s1.length());
  std::sort(v2.begin(), v2.begin()+s1.length());

  // Compare all the elements of two vectors
  bool result = std::equal(v1.begin(), v1.end(), v2.begin());
 
  return result;

}

//returns an array of all pairs of integers from the input array whose sum equals the target



std::vector<std::pair<int, int> > pairsThatEqualSum(std::vector<int> inputArray,  int targetSum){
  
  //declaring vector to be returned
  std::vector<std::pair<int, int> > ret;

  /*//TO DO: Optomize to O(n) using a hashset?
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
    }*/

  
  //optimizing from o(n^2) to o(n)
  std::unordered_set<int> vals = std::unordered_set<int>();
  for (int i=0; i<inputArray.size(); i++){
    vals.insert(inputArray.at(i));
  }

  for (int i=0; i<inputArray.size(); i++){
    if (vals.find(abs(targetSum - inputArray.at(i))) != vals.end()){
      std::pair<int, int> p;                                                            
      p.first = inputArray.at(i); 
      p.second = targetSum - inputArray.at(i);
      ret.push_back(p);  
      vals.erase(targetSum - inputArray.at(i)); //accounting for duplicates
      vals.erase(inputArray.at(i)); //accounting for duplicates
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
