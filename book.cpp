#include "book.h"
#include<string.h>
#include <iomanip>

Book::Book()
{
	bookId=0;
	strcpy(bookName,"Not given\n");
	strcpy(author,"Not given\n");
	strcpy(category, "Not given\n");
	price=0;
	rating=0;
}

Book::Book(int i, char* bn, char* auth, char* cat,int p,int r)
{
	bookId=i;
	strcpy(bookName, bn);
    strcpy(author, auth);
    strcpy(category, cat);
    price=p;
    rating=r;
}
void Book::setId(int i)
{
	bookId = i;
}
int Book::getId()
{
    return bookId;	
}
void Book::setBName(char* bn)
{
	strcpy(bookName, bn);
}
char* Book::getBName()
{
	return bookName;
}
void Book::setAuth(char* ath)
{
	strcpy(author, ath);
}
char* Book::getAuth()
{
	return author;
}
void Book::setCat(char* cat)
{
	strcpy(category, cat);
}
char* Book::getCat()
{
	return category;
}
void Book::setPrice(int p)
{
	price=p;
}
int Book::getPrice()
{
	return price;
}
void Book::setRating(int r)
{
	rating=r;
}
int Book::getRating()
{
	return rating;
}
void Book::displayData()
{
	cout << setw(4) << bookId << "|\t";
    cout << setw(35) << bookName << "|\t";
    cout << setw(20) << author << "|\t";
    cout << setw(15) << category << "|\t";
    cout << setw(8) << price << "|\t";
    cout << setw(8) << rating << "|\n";
	cout<<"\n";
}
//static void Book::storeHc(Book& b)
//{
//	b[0].setId(1);
//	b[0].setBName("Ikigai");
//	b[0].setAuth("Rampal");
//	b[0].setCat("Fiction");
//	b[0].setPrice(100);
//	b[0].setRating(5);
//	index++;
//	
//	b[1].setId(2);
//	b[1].setBName("The Great Gatsby");
//	b[1].setAuth("F. Scott Fitzgerald");
//	b[1].setCat("Classic");
//	b[1].setPrice(150);
//	b[1].setRating(4);
//	index++;
//	
//	b[2].setId(3);
//	b[2].setBName("To Kill a Mockingbird");
//	b[2].setAuth("Harper Lee");
//	b[2].setCat("Classic");
//	b[2].setPrice(120);
//	b[2].setRating(4);
//	index++;
//	
//	b[3].setId(4);
//	b[3].setBName("1984");
//	b[3].setAuth("George Orwell");
//	b[3].setCat("Science Fiction");
//	b[3].setPrice(110);
//	b[3].setRating(4.5);
//	index++;	
//}