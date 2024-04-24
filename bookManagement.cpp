#include "bookManagement.h"
//#include "book.h"
#include <iomanip>

BookManagement::BookManagement(int s)
{
	size=s;
	index=-1;
	this->b=new Book[size];
}
BookManagement::BookManagement(BookManagement& bm)
{
	size=bm.size;
	index=bm.index;
	this->b=new Book[size];
	for(int i=0;i<=index;i++)
	{
		b[i]=bm.b[i];
	}
}
void BookManagement::storeHc()
{
	b[++index] = Book(1,"Ikigai","Rampal","Fiction",100,5);
	b[++index] = Book(2, "To Kill a Mockingbird", "Harper Lee", "Drama", 150, 4);
    b[++index] = Book(3, "1984", "George Orwell", "Fiction", 120, 4);
    b[++index] = Book(4, "Pride and Prejudice", "Jane Austen", "Historic", 110, 4);
    b[++index] = Book(5, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 130, 4);
    b[++index] = Book(6, "The Catcher in the Rye", "J.D. Salinger", "Thriller", 125, 4);
    b[++index] = Book(7, "Inception", "Harper Lee", "Sci-fi", 300, 5);
    b[++index] = Book(8, "The Hobbit", "J.R.R. Tolkien", "Fantasy", 180, 5);
    b[++index] = Book(9, "Harry Potter", "J.K. Rowling", "Fantasy", 200, 5);
}
bool BookManagement::isEmpty()
{
	return index==-1;
}
bool BookManagement::isFull()
{
	return index=size-1;
}
bool BookManagement::store(Book& b1)
{
	if(isFull())
	{
		cout<<"Library is full\n";
		return false;
	}
	else if(index>=size-1)
	{
		cout<<"Array is full!!\n";
		return false;	
	}
	else
	{
		b[++index]=b1;
		return true;
	}
}
//void BookManagement::display(int idx)
//{
//	for(int i=0;i<=index;i++)
//	{
//		if(idx==i)
//		{
//			b[i].display();
//		}
////		b[i].display();
////		cout<<"\n";
//	}
//	cout<<"\n";
//}
bool BookManagement::search(int choice) {
    if (isEmpty()) {
        return false;
    }

    if (choice == 1) {
        int bid;
        cout << "Enter book Id: ";
        cin >> bid;
        int flag = 0;
        for (int i = 0; i <= index; i++) {
            if (bid == b[i].getId()) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            cout << "\n-------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << setw(4) << "Id" << "|\t";
            cout << setw(35) << "Name" << "|\t";
            cout << setw(20) << "Author" << "|\t";
            cout << setw(15) << "Category" << "|\t";
            cout << setw(8) << "Price" << "|\t";
            cout << setw(8) << "Ratings" << "|\t";
            cout << "\n-----------------------------------------------------------------------------------------------------------------------------------\n";
            for (int i = 0; i <= index; i++) {
                if (bid == b[i].getId()) {
                    b[i].displayData();
                    break;
                }
            }
            cout << "---------------------------------------------------------------------------------------------------------------------------------\n";
        } else {
            cout << "Book not found!!\n";
        }
        return true;
    } 
	else if (choice == 2) 
	{
		fflush(stdin);
        char bnm[50];
        cout << "Enter Book Name: ";
        cin.getline(bnm,50);
        int flag = 0;
        for (int i = 0; i <= index; i++) {
            if (strcasecmp(bnm, b[i].getBName()) == 0) 
			{
                flag = 1;
                cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
                cout << setw(4) << "Id" << "|\t";
                cout << setw(35) << "Name" << "|\t";
                cout << setw(20) << "Author" << "|\t";
                cout << setw(15) << "Category" << "|\t";
                cout << setw(8) << "Price" << "|\t";
                cout << setw(8) << "ratings" << "|\t";
                cout << "\n---------------------------------------------------------------------------------------------------------------------------\n";
                b[i].displayData();
                cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
                break;
			}
        }
        if (flag == 0) {
            cout << "Book Not Found !!\n";
        }
        return true;
    } 
	else if (choice == 3) 
	{
		fflush(stdin);
        char aname[20];
        int found = 0;
        cout << "Enter Author Name: ";
        cin.getline(aname,20);
        
        for (int i = 0; i <= index; i++) {
            if (strcasecmp(b[i].getAuth(), aname) == 0) {
            	cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
		        cout << setw(4) << "Id" << "|\t";
		        cout << setw(35) << "Name" << "|\t";
		        cout << setw(20) << "Author" << "|\t";
		        cout << setw(15) << "Category" << "|\t";
		        cout << setw(8) << "Price" << "|\t";
		        cout << setw(8) << "ratings" << "|\t";
		        cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
                b[i].displayData();
                cout << "----------------------------------------------------------------------------------------------------------------------------\n";
                found = 1;
            }
        }
        if (found == 0) {
            cout << "Book not found!!\n";
        }
        return true;
    } 
	else if (choice == 4) 
	{
		fflush(stdin);
        char cname[20];
        int found = 0;
        cout << "Enter category: ";
        cin.getline(cname,20);

        for (int i = 0; i <= index; i++) {
            if (strcasecmp(b[i].getCat(), cname) == 0) {
            	cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
		        cout << setw(4) << "Id" << "|\t";
		        cout << setw(35) << "Name" << "|\t";
		        cout << setw(20) << "Author" << "|\t";
		        cout << setw(15) << "Category" << "|\t";
		        cout << setw(8) << "Price" << "|\t";
		        cout << setw(8) << "ratings" << "|\t";
		        cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
                b[i].displayData();
                cout << "------------------------------------------------------------------------------------------------------------------------------\n";
                found = 1;
            }
        }
        if (found == 0) {
            cout << "Book not found!!\n";
        }
        return true;
    } else {
        cout << "Invalid choice!!\n";
        return false; // Return false for invalid choice
    }
}

bool BookManagement::delete1()
{
	if(isEmpty())
	{
		return false;
	}
	int bid;
	cout<<"Enter the id to delete book: ";
	cin>>bid;
	int found=0;
	for(int i=0;i<=index;i++)
	{
		if(b[i].getId()==bid)
		{
			found=1;
			for(int j=i;j<index;j++)
			{
				b[j]=b[j+1];
			}
			index--;
			break;
		}	
	}
	if(found!=1)
	{
		cout<<"Book not found!!\n";
	}
	else
	{
		cout<<"Deleted Successfully!\n";
	}
	return true;
}
bool BookManagement::update()
{
	if(isEmpty())
	{
		return false;
	}
	int up;
	cout<<"Update 1)Price 2)Rating \n";
	cin>>up;
	if(up==1)
	{
		int id;
		cout<<"Enter book id to update price: ";
		cin>>id;
		int index=-1;
		for(int i=0;i<size;i++)
		{
			if(b[i].getId()==id)
			{
				int p;
				cout<<"Enter price: ";
				cin>>p;
				index=i;
				b[i].setPrice(p);
				break;
			}
		}
		if(index==-1)
		{
			cout << "Book not found!!\n";
		}
		return true;	
	}
	else if(up==2)
	{
		int id,index=-1;
		cout<<"Enter book id to update rating: ";
		cin>>id;
		for(int i=0;i<size;i++)
		{
			if(b[i].getId()==id)
			{
				int r;
				cout<<"Enter Ratings: ";
				cin>>r;
				index=i;
				b[i].setRating(r);
				break;
			}
		}
		if(index==-1)
		{
			cout << "Book not found!!\n";
		}
		return true;	
	}
	else
	{
		cout<<"Invalid choice!!\n";
	}
}
void BookManagement::sort(int ch)
{
	if(ch==1)
	{
		for(int i=0;i<=index;i++)
		{
			for(int j=i+1;j<=index;j++)
			{
				if(b[i].getPrice()>b[j].getPrice())
				{
					Book temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
	}
	else if(ch==2)
	{
		for(int i=0;i<=index;i++)
		{
			for(int j=i+1;j<=index;j++)
			{
				if(b[i].getRating()<b[j].getRating())
				{
					Book temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
	}
	else
	{
		cout<<"Invalid input!\n";
	}
}
void BookManagement::top()
{
	int c;
	cout<<"Top 3: 1.Low Priced Books  2.Rated Books\n";
	cin>>c;
	if(c==1)
	{
		sort(1);
		for(int i=0;i<3;i++)
		{
			b[i].displayData();
		}
	}
	else if(c==2)
	{
		sort(2);
		for(int i=0;i<3;i++)
		{
			b[i].displayData();
		}
	}
	else
	{
		cout<<"Invalid Input\n";
	}
}
BookManagement::~BookManagement()
{
	if(b!=NULL)
	{
		delete []b;
	}
}
void BookManagement::displayBook()
{
	    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-* Books  Management *-*-*-*-*-*-*-*-*-*-*-*-*\n");
		int i;
		cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
		cout << setw(4) << "Id" << "|\t";
	    cout << setw(35) << "Name" << "|\t";
	    cout << setw(20) << "Author" << "|\t";
	    cout << setw(15) << "Category" << "|\t";
	    cout << setw(8) << "Price" << "|\t";
	    cout << setw(8) << "Ratings" << "|\t";
		cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n";
		for(i=0; i<=index; i++)
		{
			b[i].displayData();
		}
		cout<<"----------------------------------------------------------------------------------------------------------------------------\n";
}