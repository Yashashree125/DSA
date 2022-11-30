#include<iostream>
#include<string.h>
using namespace std;

template<class T>
class stack
{
	T data;
	stack *next;
	
	public:
		stack *push(stack *,T);
		stack *pop(stack *);
		char *postfix(char *exp);
		int  postfix_eval(char []);
		void prefix(char [],char []);
		int  prefix_eval(char []);
	
		void display(stack *);
		
};
template <class T>
void stack<T>::display(stack *top)
{
	while(top!=NULL)
	{
		cout<<top->data;
		top=top->next;
	}
}

template <class T>
stack<T> *stack<T>::push(stack *top,T exp )
{
	stack *newnode=new stack;
	newnode->data=exp;
	newnode->next=NULL;
	if (top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
	
	return top;
	
	
	
}
	
template <class T>
stack<T> *stack<T>::pop(stack *top)
{
	if(top==NULL)
	cout<<"Stack is empty"<<endl;
	else
	{
		stack *ptr=top;
		top=top->next;
		delete ptr;
	}
	return top;
}



int priority(char x)
{
	if(x=='^')
		return 3;
	else if(x=='*'||x=='/')
		return 2;
	else if(x=='+'||x=='-')
		return 1;

	else if(x=='(');
		return 0;
}
template<class T>
char *stack<T>::postfix(char *infix)
{
	char postfix[10];
	int p=0;
	int instack,token;
	
	stack *top=NULL;
	while(*infix!='\0')
		if(!isalnum(*infix))
		{
			
		

	
	{
		if(!isalnum(*infix))
		{
			if(*infix=='(')
			{
				top=top->push(top,*infix);
				infix++;
			}
		
		//	else 
		//	{
		else if	(top==NULL)
				{
					top=top->push(top,*infix);
					infix++;
				}
				
		//	}
	
			
			else
			{
				if(*infix==')')
				{
					while(top->data!='(')
					{
						postfix[p]=top->data;
						p++;
						top=top->pop(top);
					}
				top=top->pop(top);
				infix++;
					
				}
				else
				{
					instack=priority(top->data);
					token=priority(*infix);
					
				if(instack>=token)
					{
						while(top!=NULL && instack>=token)
						{
						postfix[p]=top->data;
						p++;
						top=top->pop(top);
						}
						top=top->push(top,*infix);
						infix++;
					}
					else
					{
						top=top->push(top,*infix);
						infix++;
					}
					
				}
			}
		}
		else
		{
			postfix[p]=*infix;
			infix++;
			p++;
		}
		
		
	}
	
}
else
{
	cout<<"invalid";
	break;
	
}

	while(top!=NULL)
	{
		postfix[p]=top->data;
		p++;
		top=top->pop(top);
	}
	postfix[p]='\0';
	return postfix;


}

int value(char y,int val[20][2])  //abc+*
{
	for (int k=0;k<20;k++)
	{
		if(val[k][0]==int(y))  //a =1 a 65 
			return val[k][1];
		
	}
}
int cal(int x,int y,char opr)
{
	if(opr=='+')
		return (y+x);
	if(opr=='-')
		return (y-x);
	if(opr=='*')
		return (y*x);
	if(opr=='/')
		return (y/x);
}

template<class T>
int stack<T>::postfix_eval(char postfix1[20])
//postfix_eval(char postfix[20])
{
	int val[20][2];
	int i=0,n=0;
	int j;
	int res;    //ab+
	//char *Post=postfix;
	stack<T>*top=NULL;
	
	int flag=0;
	
	while(postfix1[i]!='\0')
	{
		flag=0;
		if(isalnum(postfix1[i]))
		{
			
		
		/*	for(j=0;j<n;j++)
		{
			if(val[j][0]==int(postfix1[i]))  
			{
				flag=1;
				break;
				
			}
				      
		}*/
		
		if(flag==0)
		{
			cout<<"\nEnter The Value: "<<postfix1[i]<<" ";
			cin>>val[n][1];
			val[n][0]=int(postfix1[i]);
			n++;
		}
	}
	i++;
	}
	i=0;
	while(postfix1[i]!='\0')
	{
		if(isalpha(postfix1[i]))
		{
			int v=value(postfix1[i],val);
			top=top->push(top,v);
			
		}
		else
		{
			
			int x=top->data;
			top=top->pop(top);
			int y=top->data;
			top=top->pop(top);
			int res=cal(x,y,postfix1[i]);
		//	cout<<"Interemediate result is"<<res;
			top=top->push(top,res);
			
		}
		i++;
	}
	res=top->data;
	top=top->pop(top);
	return res;
}


/*void reverse(char infix[],char rinfix[])
{
	int len=strlen(infix);
	int j=0;
	for(int i=len-1;i>=0;i--)
	{
		if(infix[i]=='(')
		{
			rinfix[j]=')';
			j++;
		}
		else if(infix[i]==')')
		{
			rinfix[j]='(';
			j++;
		}
		else
		{
			rinfix[j]=infix[i];
			j++;
		}
	
	}
	//return rinfix;
	
}

template<class T>
void stack<T>::prefix(char infix[],char prefix[])
{
		char rinfix[20];
		reverse(infix,rinfix);
	//	cout<<"answer"<<rinfix;
	//	char *rev=rinfix;
		char *post1;
	//	stack <char>*top2=NULL;
		
	  	post1=postfix(rinfix);
		reverse(post1,prefix);
}
int calculate(int x,int y,char opr)
{
	if(opr=='+')
		return (x+y);
	if(opr=='-')
		return (x-y);
	if(opr=='*')
		return (x*y);
	if(opr=='/')
		return (x/y);
}
template<class T>
int stack<T>::prefix_eval(char prefix1[20])
{
	
	int val[20][2];
	int i=0,n=0;
	int j;
	int result;
	stack<T>*top3=NULL;
	int flag=0;
	char prefix_exp[20] ;
	reverse(prefix_exp,prefix1);
	cout<<"answer"<<prefix1;
	
	while(prefix1[i]!='\0')
	{
		flag=0;
		if(isalnum(prefix1[i]))
		{
			
		
			for(j=0;j<n;j++)
		{
			if(val[j][0]==int(prefix1[i]))
			{
				flag=1;
				break;
				
			}
				
		}
		
		if(flag==0)
		{
			cout<<"\nEnter The Value: "<<prefix1[i]<<" ";
			cin>>val[n][1];
			val[n][0]=int(prefix1[i]);
			n++;
		}
	}
	i++;
	}
	i=0;
	while(prefix1[i]!='\0')
	{
		if(isalpha(prefix1[i]))
		{
			int v=value(prefix1[i],val);
			top3=top3->push(top3,v);
			
		}
		else
		{
			
			int x=top3->data;
			top3=top3->pop(top3);
			int y=top3->data;
			top3=top3->pop(top3);
			int res=calculate(x,y,prefix1[i]);
			top3=top3->push(top3,res);
			
		}
		i++;
	}
	result=top3->data;
	top3=top3->pop(top3);
	return result;
}*/

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

int main()
{
	char infix[20];
	char *post;
	char rev;
	char prefix1[20];
	char postfix1[20];
	//char prefix1[20];
	char prefix_exp[20];
	stack <int>*top2=NULL;
	
	
	char post1[20],rinfix[20]	;
	int result,res;
	stack <char>*top=NULL;
	stack <int>*top1=NULL;
	cout<<"Enter Infix Expression : "<<endl;
	cin>>infix;
	post=top->postfix(infix);
	cout<<"\nPostfix Expression is : "<<post<<"\n";
	
	cout<<"\nEnter the postfix expression: ";
	cin>>postfix1;
	result=top1->postfix_eval(postfix1);
	cout<<"\nPostfix Evaluation Answer :"<<result<<endl;
	
		//reverse(infix,rinfix);
		//cout<<"\nanswer"<<rinfix;
		//top->prefix(infix,prefix1);
		//cout<<"\nPrefix Expression is "<<prefix1;
		
		//cout<<"\nEnter the prefix expression: ";
		//cin>>prefix_exp;
		//res=top2->prefix_eval(prefix1);
		//cout<<"\nPrefix Evaluation Answer :"<<res<<endl;
	
	
	
	return 0;
}


//7-(2*3+5)*(8-4/2)
//(2/4-8)*(5+3*2)-7
//24/8-532*+*7-
//723*5+842/-*-


