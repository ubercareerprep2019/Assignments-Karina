#include <iostream>
#include <vector>
#include "stack.cpp"
#include "stack.h"
#define CONSTANTS_H

const int numRods = 3;

stack rod1 = stack();
stack rod2 = stack();
stack rod3 = stack();

std::vector<stack> rods = {rod1, rod2, rod3};

stack& disksAtRod(int rodIndex){
  return rods.at(rodIndex);
}


//popping from startRod and pushing the Disk to destRod
void moveDisk(int startRod, int destRod){
  int popped = disksAtRod(startRod).pop();
  //  std::cout << "popped: " << popped << std::endl;
  disksAtRod(destRod).push(popped);
}


void hanoi(int n, int s, int t, int d){
  //std::cout << "n: " << n << std::endl;
  if (n==1){
    moveDisk(s, d);
    return;
  }
  else{
    hanoi(n-1,s,d,t);
    hanoi(1,s,t,d);
    hanoi(n-1,t,s,d);
  }
}


int main()
{
  //test 1: 3 disks stacked TOP-> 1-2-3 on peg 1 moving to peg 3:
  int numDisks = 3;

  disksAtRod(0).push(3);
  disksAtRod(0).push(2);
  disksAtRod(0).push(1);

  int s = 0;
  int t = 1;
  int d = 2;

  hanoi(numDisks, s, t, d);

  std::vector<int> dest;
  while (!(disksAtRod(d).isEmpty())){
      dest.push_back(disksAtRod(d).pop());
  }

  for (int i = 0; i < numDisks; i++){
    std::cout << dest.at(i) << std::endl;
  }

  //reset
  while (!disksAtRod(d).isEmpty()){
    disksAtRod(d).pop();
  }


  //testing for 5 disks starting at peg 1 stacked 5-4-3-2-1
  numDisks = 5;
  disksAtRod(0).push(5);
  disksAtRod(0).push(4);
  disksAtRod(0).push(3);
  disksAtRod(0).push(2);
  disksAtRod(0).push(1);

  hanoi(numDisks, s, t, d);

  dest = {};
  while (!(disksAtRod(d).isEmpty())){
    dest.push_back(disksAtRod(d).pop());
  }

  std::cout << "\n---------------------\n" << std::endl;
  for (int i = 0; i < numDisks; i++){
    std::cout << dest.at(i) << std::endl;
  }



}

