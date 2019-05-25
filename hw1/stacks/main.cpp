#include <iostream>
#include "stack.h"

int main() {

stack s = stack();
std::cout << s.isEmpty() << std::endl;
s.push(5);
s.push(10);
s.push(15);
s.push(20);
s.push(25);
s.push(30);
s.push(35);
s.push(40);
s.push(45);
s.push(50);

//at capacity
s.push(55);
s.push(60);

std::cout << "popping... " << std::endl;
std::cout << s.pop() << std::endl;
std::cout << "popping... " << std::endl;
std::cout << s.pop() << std::endl;
std::cout << "popping... " << std::endl;
std::cout << s.pop() << std::endl;
std::cout << "popping... " << std::endl;
std::cout << s.pop() << std::endl;

std::cout << s.top() << std::endl;


}
