#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>

int  isAlpha(char[]);

using namespace std;

class student
{
	int roll_no;
	char name[15];
	float marks;
	public:
		void getdata(int);
		void display();
};

void student::getdata(int )
{
	cout<<"Enter the name:";
	cin>>name;
	cout<<"Enter the marks:";
	cin>>marks;
}

void student::display()
{
	cout<<"\t"<<name<<"\t"<<marks<<"\n";
}
int main()
{
	int i,n,l,pos,ch,r,x,count,no;
	fstream iofile;
	fstream iofile1;
	student s;
	cout<<"Enter the no. of records you want to add:";
	cin>>n;
	fstream file;
	file.open("file.doc",ios::in | ios::out | ios::app);
	
	
	cout<<" Student Database "<<endl;
	do
	{
		cout<<"\n1.Create\n2.Display\n3.Search\n4.Modify\n5.Add\n6.Delete\n7.Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				iofile.open("Student.doc",ios::out);
				cout<<"Enter total number of students : ";
				cin>>n;
					for(i=0;i<n;i++)
					{
						s.getdata(i);
						iofile.write((char *)&s,sizeof(student));
					}
					iofile.close();
					break;
					
			case 2:
					count=0;
					iofile.open("Student.doc",ios::in);
					file.seekp(0);
					while(iofile.read((char *)&s,sizeof(student)))
					{
						s.display();
						++count;
					}
					iofile.close();
					break;
					
			case 3:
				cout<<"Enter the number of records you want to search : ";
				cin>>x;
				while(x>count)
				{
					cout<<"Only"<<count<<" records are present\nEnter a valid search number"<<endl;
					cin>>x;
				}
				iofile.open("Student.doc",ios::in|ios::out|ios::app);
				for(i=0;i<x;i++)
				{
					cout<<"Enter the record number you want to search : ";
					do
					{
						cin>>no;
						if(no>count){
							cout<<"Record not found \n Please reenter : ";
						}
						
						}while(no>count);
						l=(no-1)*sizeof(s);
						iofile.seekp(l,ios::beg);
						cout<<"\nDetails :- "<<endl;
						cout<<"\nRoll.no\tName\tMarks"<<endl;
						while(!iofile(EOF))
							iofile.read((char *)&s,sizeof(s));
							s.display();	
			
				
				}
		
				iofile.close();
				break;
					
			case 4:
	
				cout<<"Enter the number of records you want to modify : ";
				cin>>x;
				while(x>count)
				{
					cout<<"Only"<<count<<" records are present\nEnter a valid search number"<<endl;
					cin>>x;
				}
				iofile.open("Student.doc",ios::in|ios::out|ios::ate);
				for(i=0;i<x;i++)
				{
					cout<<"Enter the record number you want to modify : ";
					do
					{
						cin>>no;
						if(no>count){
							cout<<"Record not found \n Please reenter : ";
						}
						
						}while(no>count);
						l=(no-1)*sizeof(s);
						iofile.seekp(l,ios::beg);
						s.getdata(no-1);
						iofile.write((char *)&s,sizeof(student));
					
			}
	
					iofile.close();	
					break;
					
			case 5:
				cout<<"\Enter number of records you want to add : ";
				cin>>x;
				iofile.open("Student.doc",ios::in|ios::out|ios::app);
					for(i=0;i<x;i++)
					{
						count=count+i;
						s.getdata(count);
						iofile.write((char *)&s,sizeof(student));
					}
					iofile.close();	
					break;
			case 6:
				r=0;
				iofile.open("Student.doc",ios::in|ios::out|ios::ate);
				iofile1.open("Student.doc1",ios::in|ios::out|ios::app);
				cout<<"\nEnter the record number you wish to delete : ";
				do{
					cin>>no;
					if(no>count)
						cout<<"Record not found \n Please reenter : ";
						
				}while(no>count);
					l=(no-1)*sizeof(s);
					iofile.seekp(l,ios::beg);
					iofile.seekp(0);
					while(iofile.read((char *)&s,sizeof(student)))
					{
						pos=r*sizeof(s);
						if()
						{
							
							
						}
						
						else
						{
							iofile1.write((char *)&s,sizeof(student));
							
						}
						pos=r*sizeof(s);
						if(pos!=l)
						{
							iofile1.write((char *)&s,sizeof(student));
						}
						r++;
					}
		
			iofile.close();
			iofile1.close();
			remove("Student.doc");
			rename("Student.doc1","Student.doc");
			break;
			
		case 7:
			exit(0);
			
		default:
			cout<<"\nWrong choice "<<endl;
       
	}
	}while(ch!=6);
	
	return 0;
}
