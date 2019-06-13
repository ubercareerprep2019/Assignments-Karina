#include <iostream>
#include "List.h"
#include "Node.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

List< int > *l = new List< int >();

TEST_CASE("testPushBackAddsOneNode"){
  l->pushBack(1);
  CHECK( l->getDebugString() == "TOP-> 1-> NULL\n");
}

TEST_CASE("pushBack"){
  l->pushBack(3);
  l->pushBack(7);
  l->pushBack(15);
  l->pushBack(20);
  l->pushBack(22);
  CHECK(l->getDebugString() == "TOP-> 1->3->7->15->20->22-> NULL\n");
}


TEST_CASE("testPopBackRemovesCorrectNode"){
  l->popback();
  CHECK(l->getDebugString() == "TOP-> 1->3->7->15->20-> NULL\n");
}


TEST_CASE("testEraseRemovesCorrectNode"){
  l->erase(0);
  CHECK(l->getDebugString() == "TOP-> 3->7->15->20-> NULL\n");
  l->erase(2);
  CHECK(l->getDebugString() == "TOP-> 3->7->20-> NULL\n");
}

TEST_CASE("testEraseDoesNothingIfNoNode"){
  CHECK_THROWS(l->erase(10));
  CHECK(l->getDebugString() == "TOP-> 3->7->20-> NULL\n");
}


TEST_CASE("testElementAtReturnNode"){
  CHECK(l->elementAt(1) == 7);
}

TEST_CASE("testElementAtReturnsNoNodeIfIndexDoesNotExist"){
  CHECK_THROWS( l->elementAt(10));
}


TEST_CASE("testSizeReturnsCorrectSize"){
  std::cout << l->getDebugString() << std::endl;
  CHECK(l->size() == 3);
}

TEST_CASE("hasCycle"){
 
  Node<int> *first = new Node<int>(5, nullptr);
  Node<int> *second = new Node<int>(5, nullptr);
  Node<int> *third = new Node<int>(5, nullptr);
  first->setNext(second);
  second->setNext(third);
  List< int > *l2 = new List<int>(first);
  CHECK(l2->size() == 2);
}

TEST_CASE("palindrome"){

  //apple
  List< std::string > *a = new List<std::string>();
  a->pushBack("a");
  a->pushBack("p");  
  a->pushBack("p");
  a->pushBack("l");
  a->pushBack("e");
  //elppa
  List< std::string > *b = new List<std::string>();
  b->pushBack("e");
  b->pushBack("l");
  b->pushBack("p");  
  b->pushBack("p");
  b->pushBack("a");

  CHECK(a->isPalindrome(b) == true);
}

  
