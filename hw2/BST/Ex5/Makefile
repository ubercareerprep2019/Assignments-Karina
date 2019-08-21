CXXFLAGS =-g -std=c++11

ListPhoneBook: ListPhoneBook.o 
	g++ $(CXXFLAGS) ListPhoneBook.o -o ListPhoneBook

ListPhoneBook.o: ListPhoneBook.cpp ListPhoneBook.h 
	g++ $(CXXFLAGS) -c ListPhoneBook.cpp 

BSTPhoneBook: BSTPhoneBook.o 
	g++ $(CXXFLAGS) BSTPhoneBook.o -o BSTPhoneBook

BSTPhoneBook.o: BSTPhoneBook.cpp BSTPhoneBook.h
	g++ $(CXXFLAGS) -c BSTPhoneBook.cpp 

clean: 
	rm BSTPhoneBook ListPhoneBook *.o 