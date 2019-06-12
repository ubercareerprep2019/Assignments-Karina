#include <iostream>
#include "stack.h"
#include "queue.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <array>
// stack
TEST_CASE("Pop, Size,"){
  stack s = stack();
  s.push(1);
  CHECK(s.top() == 1);
  s.push(2);  
  CHECK(s.top() == 2);
  s.push(3);  
  CHECK(s.top() == 3);
  CHECK(s.pop() == 3);
  CHECK(s.pop() == 2);
  CHECK(s.pop() == 1);
  CHECK(s.pop() == -1);
}

