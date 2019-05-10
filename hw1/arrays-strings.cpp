#include <iostream>


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

int main(){
  //test cases
  std::cout << isStringPermutation("hello", "olehl") << std::endl; //true
  std::cout << isStringPermutation("hello", "world") << std::endl; //false
  return 0;
}
