#include <iostream>
#include "stack.h"
#include "queue.h"

int main() {

  std::cout<< "--------------------------------STACK TESTS---------------------------"<<std::endl;
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
 std::cout << s.debugString() << std::endl;

//at capacity
s.push(55);
s.push(60);


std::cout << s.pop() << std::endl;
std::cout << s.pop() << std::endl;
std::cout << s.pop() << std::endl;
std::cout << s.pop() << std::endl;
std::cout << s.pop() << std::endl;
std::cout << s.pop() << std::endl;
 std::cout<< s.debugString() << std::endl;
std::cout << "top: " << s.top() << std::endl;

std::cout<<"-----------------------------MIN STACK TEST---------------------------"<<std::endl;

 minStack s2 = minStack();
 s2.push(3);
 s2.push(8);
 s2.push(12);
 s2.push(5);
 std::cout << s2.debugString() << std::endl;
 std::cout << "curr min: " << s2.minVal() << std::endl;
 s2.push(12);
 s2.push(22);
 s2.push(11);
 s2.push(2);
 std::cout << s2.debugString() << std::endl;
 std::cout << "curr min: " << s2.minVal() << std::endl;
 s2.pop();
 s2.pop();
 std::cout << s2.debugString() << std::endl;
 std::cout << "curr min: " << s2.minVal() << std::endl;




 std::cout<<"\n" << "-----------------------------QUEUE TESTS---------------------------"<<std::endl;

queue q1 = queue();
q1.enqueue(1);
q1.enqueue(2);
q1.enqueue(3);
q1.enqueue(4);
q1.enqueue(5);

 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;
 std::cout << q1.dequeue() << std::endl;

}
