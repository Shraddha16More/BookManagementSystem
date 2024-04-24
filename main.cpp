#include <iostream>
#include "bookManagement.h"
using namespace std;

int main() 
{
	int choice;
	BookManagement bm1(50);
	bm1.storeHc();
	while(choice!=-1)
	{
		cout<<"\t1.Store\n";
		cout<<"\t2.Display the data\n";
		cout<<"\t3.Search for the book\n";
		cout<<"\t4.Delete record\n";
		cout<<"\t5.Update\n";
		cout<<"\t6.Sort\n";
		cout<<"\t7.Top 3\n";
		cout<<"\n";
		cout<<"Enter choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					int id,p,r;
					char name[20];
					char ath[20];
					char cat[20];
					cout<<"Enter id,name,author,category,price,rating\n";
					cin>>id>>name>>ath>>cat>>p>>r;
					Book b1(id,name,ath,cat,p,r);
					if(bm1.store(b1))
					{
						cout<<"Book Info added successfully!\n";
					}
					else
					{
						cout<<"Operation failed!\n";
					}
				}
				break;
			case 2:
				{
					bm1.displayBook();
				}
				break;
			case 3:
				{
					int c;
                    cout << "Search By: 1) BookId 2) Name 3) Author 4) Category\n";
                    cin >> c;
	                int res = bm1.search(c);
	                if (res == 0) 
					{
	                    cout << "Library is Empty\n";
	                }
			    }
				break;
			case 4:
				{
					int res=bm1.delete1();
					if (res == 0) 
					{
	                    cout << "Library is Empty\n";
	                }
				}
				break;
			case 5:
				{
					int res=bm1.update();
					if (res == 0) 
					{
	                    cout << "Library is Empty\n";
	                }
				}
				break;
			case 6:
				{
					int ch;
		            cout << "Sort By: 1) Price 2) Rating\n";
		            cin >> ch;
		            bm1.sort(ch);
		            cout << "Books sorted successfully!\n";
		            bm1.displayBook();
				}
				break;
			case 7:
				{
					bm1.top();
				}
				break;
			default:
                cout << "Invalid choice!\n";
                break;	
		}
	}
	return 0;
}