/*
Department maintains a student database. The file contains roll number, name, division and
address. Write a program to create a sequential file to store and maintain student data. it should
allow the user to add, delete information of student. Display iformation of particular student. If record of student does not
exist an appropriate message is displayed. if student record is found it should display the student details.
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class student
{
	int marks;
	char name[100];
	char div;
	char addr[100];
	public:
		void getdata();
		void display();
		void put_to_file();
};

void student::getdata()
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

void student::put_to_file()
{
	fstream fileobj;
	fileobj.open("db.txt",ios::app);
	fileobj << name << "\t" << marks << "\n";	
	fileobj.close();
}


int main()
{
	student s;
	fstream fileobj;
	cout << "Student Database\n";
	int ch = -1;
	do
	{
		cout << "1.Add\n2.Display\n3.Search\n4.Delete\n5.Exit\n";
		int index = 1;
		int flag = 0;
		int x = 0;
		cout << "Choice: ";
		cin >> ch;
		cout << endl;
		switch(ch)
		{
			case 1:
				cout << "Enter the number of students: ";
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					s.getdata();
					s.put_to_file();
				}
				break;
			case 2:
				fileobj.open("db.txt", ios::in);
				if(fileobj.peek() == 10)                  // 10  newline character '\n'
				{
					fileobj.get();
				}
				cout << "Sr.no\t Name\tMarks.\n";
				while(fileobj.peek() != -1)               // -1 is ascii for EOF
				{
					char name_temp[100];
					fileobj.getline(name_temp,100);
					cout << index << ".\t " << name_temp <<"\t"<< endl;
					index++;
				}
				cout << endl;
				fileobj.close();
				break;
			case 3:
				fileobj.open("db.txt", ios::in);
				cout << "Enter the record number: ";
				cin >> x;
				if(fileobj.peek() == 10)
				{
					fileobj.get();
				}
				while(fileobj.peek() != -1 && index <= x)
				{
					char name_temp[100];
					fileobj.getline(name_temp,100);
					if (index == x)
					{
						cout << "Name\tMarks.\n";
						cout << name_temp << endl;
						flag = 1;
						break;
					}
					index++;
				}
				if(!flag)
					cout << "\nIndex not found.\n\n";
				cout << endl;
				fileobj.close();
				break;
			case 4:
				fstream temp_file;
				temp_file.open("temp.txt",ios::out);
				fileobj.open("db.txt", ios::in);
				cout << "Enter the record number to delete: ";
				cin >> x;
				int flag = 0;
				if(fileobj.peek() == 10)
				{
					fileobj.get();
				}
				while(fileobj.peek() != -1)
				{
					char temp_name[100];
					fileobj.getline(temp_name,100);
					if (index == x)
					{
						flag = 1;
						index++;
						continue;
					}
					temp_file << temp_name << endl;
					index++;
				}
				if(!flag)
					cout << "\nIndex not found.\n\n";
				temp_file.close();
				fileobj.close();
				remove("db.txt");
				rename("temp.txt","db.txt");
				break;
		}
	}while(ch != 6);
	return 0;
}

