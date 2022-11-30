#include<iostream>

using namespace std;
class student
{
	int Roll_no,i,j;
	int mid;
	string Name;
	float SGPA;
	
	public:
		
		void getrecord();
		void display();
		void linear_search(student s[],int n,float sgpa);
		void binary_search(student s[],int n,string name);
		void bubble_sort(student s[],int n);
		void insertion_sort(student s[],int n);
		void quick_sort(student s[],int low,int high);
		
}; //s[15];

void student::getrecord()
{
	cin>>Roll_no;
	cin>>Name;
	cin>>SGPA;
}

void student::display()
{
	cout<<Roll_no<<"\t\t"<<Name<<"\t\t"<<SGPA<<endl;
}
void student::linear_search(student s[],int n,float sgpa)
{
    int flag=0;
    
    for(int i=0;i<n;i++)
    {
        if(s[i].SGPA==sgpa)
        {
           s[i].display();
           flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"\nStudent not found in the record";
    }
}
void student::insertion_sort(student s[],int n)
{
	int i,j;
	student temp;
	
	for (i = 0; i < n ; i++)
	{
		temp=s[i];
		j=i-1;
		while (j>=0 && s[j].Name>temp.Name)
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=temp;
	}
	
}

void student:: binary_search(student s[],int n,string name)
{
	
	int low,high,mid;
	 
	low=0;
	high=n-1;

	//mid=(low+high)/2;
	
    do
	{
		mid = (low + high)/2;
		if(s[mid].Name==name)
		{
		
            
			s[mid].display();
			break;
		}
		else if (name<s[mid].Name)
		{
			high=mid-1;
			
		}
		else if(name>s[mid].Name)
		{
			low=mid+1;
		}
		 
		
	}while (low<=high);
	


	
}	

void student:: bubble_sort(student s[],int n)
{
	int i,j;
	student temp;


     
    
    for (i = 0; i < n ; i++)
    {
        for (j = 0; j < (n - 1-i); j++)
        {
            if (s[j].Roll_no > s[j + 1].Roll_no)
            {
                temp = s[j];
                s[j]= s[j + 1];
                s[j + 1] = temp;
                
                
            } 
          
        }
    }

	
}

void student::quick_sort(student s[],	int low,int high)
{

	student temp;
	if (low<high)
	{
		student pivot=s[low];
		int i=low+1;
		int j=high;
		while (i<j)
		{
			while(pivot.SGPA<=s[i].SGPA && i<j)
			i++;
			while(pivot.SGPA>s[j].SGPA && j>0)
			j--;
			
			if (i<j)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		   
		}
		temp=s[j];
		s[j]=s[low];
		s[low]=temp;
		cout<<endl;
		quick_sort(s,low,j-1);
		quick_sort(s,j+1,high);
	}
	
}



int main()
{
	int n,i,j;
	string name;
	float sgpa;
	
	int ch;
	student s[15];
	
	do
	{
		
	cout<<"1.Enter your Record \n2.Display the Record \n3.Display students of Similar SGPA \n4.Display Students alphabetically \n5.Search a Student by name \n6.Sort by SGPA \n7.Quick_sort";
	cout<<"\nEnter your choice : ";
	cin>>ch;
		
	
	switch(ch)
	{
		case 1:
		{
			cout<<"Enter the number of Students:";
			cin>>n;
//			cout << n <<"xyz" <<endl;
//			student s[n];
			cout<<"Enter roll no , name  and SGPA\n";
			for (i=0;i<n;i++)
			{
				s[i].getrecord();
			}
			break ;
		}
		case 2:
			cout<<"\nDatabase  :-"<<endl;
			cout<<"\nRoll_no\t\tName\t\tSGPA"<<endl;
	
			
			for (i=0;i<n;i++)
			{
				s[i].display();
			}
			break ;
		
		case 3:
			cout<<"\n Enter SGPA to be searched ";
			cin>>sgpa;
				s[0].linear_search(s,n,sgpa);
				
			break;
	
		case 4:
			cout <<"\n Sorted Record according to Name Using insertion sort\n"<<endl;
 			for(i = 0; i<n; i++) {
 				s[0].insertion_sort( s, n);
 				s[i].display();
 		}
 		break;
 	
 		case 5:
 			cout<<"\n Enter Name to be searched ";
			cin>>name;
				s[0].binary_search(s,n,name);
				
			break;
		
		case 6:
			cout <<"\n Sorted Record according to Roll_no Using Bubble sort\n"<<endl;
 			for(i = 0; i<n; i++) {
 				s[0].bubble_sort( s, n);
 				s[i].display();
 			}
			break;
		
		case 7:
			cout <<"\n Sorted Record according to sgpa Using Quick sort\n"<<endl;
 				for(i = 0; i<n; i++) 
				{
 					s[0].quick_sort( s,i,j);
 					s[i].display();
 				}
 				break;
 		default: printf("\nWrong Choice");
						
	}
	}while(ch!=7);
	

return 0;

}




