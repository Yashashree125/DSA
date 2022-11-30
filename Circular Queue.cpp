#include <iostream>
#define N 5
using namespace std;
class cqueue
{
	
	int front;
	int rear;
	int queue[];
	public:
		int isfull();
		void enqueue(int);
		void dequeue();
		void display();
		cqueue()
		{
			front=rear=-1;
		}
	
};
int cqueue::isfull()
{
	if (front == 0 && rear == N - 1) {
      return 0;
    }
    if (front == rear + 1) {
      return 0;
    }
    return false;
}


void cqueue::enqueue(int x)
{
	if(isfull())
	{
		cout<<"\nQueue is Full"<<endl;
	}
	
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else if ((rear+1)%N==front)
	{
		cout<<"\nQueue is Full"<<endl;
	}
	else
	{
		rear=(rear+1)%N;
		queue[rear]=x;
		
	}
}
void cqueue::dequeue()
{
	if(front==-1 && rear==-1)
	{
		cout<<"\nQueue is Empty !!!";
	}
	else if(front==rear)
	{
		int ele=queue[front];
		cout<<"\nDeleted Element Is: "<<ele;
		front=rear=-1;
	}
	else
	{
		int ele=queue[front];
		cout<<"\nDeleted Element Is: "<<ele;
		front=(front+1)%N;
		
	}
	
	
}

void cqueue:: display()
{
	int i;
if(front == -1&& rear==-1)
{
    cout<<"queue is empty!";
}
else
{
    {
        for (int i = front; i !=(rear); i=((i+1)%N))
        {
            cout << queue[i] << "\t";
        }
        cout<<queue[rear]<<endl;
    }
   
}
}

int main()
{
	cqueue q;
	int ch;
	do
	{
		cout<<"\n1.Insert Elements\n2.Display\n3.Delete Elements\n4.Exit"<<endl;
		cout<<"\nEnter Your Choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				int x;
				cout<<"Enter Element :";
				cin>>x;
				q.enqueue(x);
				
				
			break;
				
			case 2:
				cout<<"\nQueue is : ";
				q.display();
				
			break;
			
			case 3:
					q.dequeue();
				
			break;
			
			
			case 4:
				exit(0);
			
			
			default: cout<<"\nWrong Choice";
		}
	

	}while(ch!=4);
	
	return 0;
}
