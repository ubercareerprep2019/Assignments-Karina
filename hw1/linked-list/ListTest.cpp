#include <iostream>
#include "List.h"

int main()
{
  List< int > *l = new List< int >();
    std::cout << l->getDebugString();
    l->pushBack(1);
    l->pushBack(3);
    l->pushBack(7);
    l->pushBack(15);
    l->pushBack(20);
    l->pushBack(22);

    std::cout << l->getDebugString() << std::endl;


    std::cout<< "INSERTION TESTS..." << std::endl << std::endl;
    std::cout<< "INSERTING 10 AT INDEX 5" << std::endl;
    l->insert(5, 10);
    std::cout << l->getDebugString() << std::endl;
    std::cout<< "INSERTING 10 AT INDEX 6" << std::endl;
    l->insert(6, 10);
    std::cout << l->getDebugString() << std::endl;
    std::cout<< "INSERTING 3 AT INDEX 25" << std::endl;
    l->insert(3, 25);
    std::cout << l->getDebugString() << std::endl;

    std::cout<< "DELETION TESTS..." << std::endl << std::endl;
    std::cout<< "ERASING INDEX 3" << std::endl;
    l->erase(3);
    std::cout << l->getDebugString() << std::endl;

    std::cout<< "ERASING INDEX 0" << std::endl;
    l->erase(0);
    std::cout << l->getDebugString() << std::endl;

    delete l;
    return 0;
}
