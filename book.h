#include<iostream>
using namespace std;

class Book
{
	int bookId;
	char bookName[50];
	char author[20];
	char category[20];
	int price;
	int rating;
	
	public:
		Book();
		Book(int, char*, char*, char*,int,int);
		void setId(int);
	    int getId();
	    void setBName( char*);
	    char* getBName();
	    void setAuth(char*);
	    char* getAuth();
	    void setCat(char*);
	    char* getCat();
	    void setPrice(int);
	    int getPrice();
	    void setRating(int);
	    int getRating();
	    void displayData();
};