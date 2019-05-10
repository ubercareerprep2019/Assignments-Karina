#include <iostream>



//takes two strings and returns true if one string is a permutation of the other, false otherwise
bool isStringPermutation(std::String String s1, std::String String s2){
  if (s1.length() != s2.length()){
    return false;
  }

  //storing every char in s1 in a set
  std::set<char> s1_chars;
  for (int i=0; i < s1.length(); s++){
    s1_chars.insert(s1[i]);
  }
}


int main(){





  return 0;
}
