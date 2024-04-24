#include<iostream>
#include "book.h"
using namespace std;

class BookManagement
{
	int size;
	int index=-1;
	Book* b;
	
	public:
		BookManagement(int);
		BookManagement(BookManagement&);
		void storeHc();
		bool isEmpty();
		bool isFull();
		bool store(Book&);
	    bool search(int);
	    bool delete1();
	    bool update();
	    void sort(int);
	    void top();
	    void displayBook();
	    ~BookManagement();
};