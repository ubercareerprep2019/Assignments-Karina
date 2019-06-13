#include <iostream>
#include "stack.h"
#include "queue.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <array>

// stack
stack s = stack();

TEST_CASE("push, pop, top"){
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
  CHECK(s.debugString() == "TOP->50->45->40->35->30->25->20->15->10->5");
  s.push(55);
  //should do nothing:
  CHECK(s.debugString() == "TOP->50->45->40->35->30->25->20->15->10->5");
  s.pop();
  s.pop();
  s.pop();
  CHECK(s.debugString() == "TOP->35->30->25->20->15->10->5");
  CHECK(s.top() == 35);
  s.pop();
  s.pop();
  CHECK(s.top() == 25);
  s.pop();
  s.pop();
  s.pop();
  s.pop();
  CHECK(s.top() == 5);
  s.pop();
  CHECK(s.top() == -1);
}

minStack s2 = minStack();
TEST_CASE("min stack"){
  s2.push(3);
  s2.push(8);
  s2.push(12);
  s2.push(5);
  CHECK(s2.debugString() == "TOP->5->12->8->3");
  CHECK(s2.minVal() == 3);
  s2.push(12);
  s2.push(22);
  s2.push(11);
  s2.push(2);
  CHECK(s2.debugString() == "TOP->2->11->22->12->5->12->8->3");
  CHECK(s2.minVal() == 2);
  s2.pop();
  s2.pop();
  CHECK(s2.minVal() == 3);
}



//queue
queue q = queue();
TEST_CASE("enqueue, dequeue"){
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  
  CHECK(q.debugString() == "TOP->1->2->3->4->5");

  q.dequeue();
  q.dequeue();
  q.dequeue();

  CHECK(q.debugString() == "TOP->4->5");
}
