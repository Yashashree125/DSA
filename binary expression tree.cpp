#include<iostream>
#include<string.h>
using namespace std;
class tree
{
	tree *left,*right;
	char data;
	public:
		tree* create(char);
		tree* construct(char []);
		tree* constr_pre(char []);
		void inorder(tree *);
		void nr_inorder(tree *);
		void preorder(tree *);
		void nr_preorder(tree *);
		void postorder(tree *);
		void nr_postorder(tree *);
		
};
class stack
{
	public:
		tree *item;
		stack *link;
		int val;
		stack* push(stack* , tree * , int);
		stack* pop(stack* );
};

stack* stack::push(stack *top , tree *temp , int flag)
{
	
	stack *newnode=new stack;
	newnode->item=temp;
	newnode->val=flag;
	newnode->link=NULL;
	
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
		newnode->link=top;
		top=newnode;
	}
	return top;
}

stack* stack::pop(stack *top)
{
	stack *temp=top;
	top=top->link;
	delete temp;
	return top;
}
tree * tree::create(char element)
{
	tree *temp=new tree;			
	temp->data=element;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
tree* tree::construct(char post[])
{
	int i=0 ;
	stack *top=NULL;
	tree *newnode;
	while(post[i]!='\0')
	{
		if(isalnum(post[i]))
		{
			newnode=create(post[i]);
			i++;
			top=top->push(top,newnode,0);
		}
		else
		{
			newnode=create(post[i]);
			i++;
			newnode->right = top->item;
			top = top->pop(top);
			newnode->left = top->item;
			top = top->pop(top);
			top = top->push(top,newnode,0);
		}
	}
	newnode=top->item;
	top=top->pop(top);
	return newnode;
}
tree* tree::constr_pre(char pre[])
{
//	int i=strlen(pre)-1 ;
int i=0;
for(int j=0;pre[j]!='\0';j++)
{
	i++;
}
i=i-1;
	stack *top=NULL;
	tree *newnode;
	while(pre[i]!='\0')
	{
		if(isalnum(pre[i]))
		{
			newnode=create(pre[i]);
			i--;
			top=top->push(top,newnode,0);
		}
		else
		{
			newnode=create(pre[i]);
			i--;
			newnode->left=top->item;
			top=top->pop(top);
			newnode->right=top->item;
			top=top->pop(top);
			top=top->push(top,newnode,0);
		}
	}
	newnode=top->item;
	top=top->pop(top);
	return newnode;
}

void tree::inorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		cout<<root->data;                              //lvr
		inorder(root->right);
		
	}
}

void tree::preorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		cout<<root->data;
		preorder(root->left);                               //vlr
		preorder(root->right);
	}
}
void tree::postorder(tree *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data;
	}
}

void tree::nr_inorder(tree *root)
{
	stack *top=NULL;
	tree *current=root;
	while(current!=NULL || top!=NULL)
	//while(1)
	{
		while (current!=NULL) 
        { 
        
            top=top->push(top,current,0); 
			current = current->left; 
        } 
     
		
		if(top!=NULL)
		{
			current=top->item;
			top=top->pop(top);
			cout<<current->data;
			current=current->right;
		
		}
		else
		
		break;
			
	
			
	}
	
}
void tree::nr_preorder(tree *root)
{
	stack *top=NULL;
	tree *current=root;
	while(current!=NULL || top!=NULL)
	{
		while (current!=NULL) 
		{
			cout<<current->data;
			if(current->right)
				top=top->push(top,current->right,0); 
			current=current->left;
		}
		if(top!=NULL)
		{
			current=top->item;
			top=top->pop(top);
		}                     //lrv
		else
		
		break;
	}
}
void tree::nr_postorder(tree *root)
{
	stack *top=NULL;
	tree *current=root;
	int flag;
	do
	{
		while(current!=NULL)
		{
			top=top->push(top,current,0);
			current=current->left;
			
		}
		flag=top->val;
		current=top->item;
		top=top->pop(top);
		if (flag==1)
		{
			cout<<current->data;
			current=NULL;
		}
		else
		{
			top=top->push(top,current,1);
			current=current->right;
		}
		
		
	}while(top!=NULL);
}


int main()
{
	tree *root=NULL;
	char post[20];
	char pre[20];
	tree t;
	int ch;
	do
	{
		cout<<endl;
		cout<<"\n1.Enter Postfix expression\n2.Enter Prefix Expression\n3.Inorder Traversal{Recursive}\n4.Preorder Traversal{Recursive}\n5.Postorder Traversal{Recursive}\n6.Inorder Traversal{Non recursive}\n7.Preorder Traversal{Non recursive}\n8.Postorder Traversal{Non recursive}\n9.exit"<<endl;
		
		cout<<"Enter Your Choice :"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter the postfix expression : ";
				cin>>post;
				root=t.construct(post);
				break;
				
			case 2:
				cout<<"\nEnter the prefix expression : ";
				cin>>pre;
				root=t.constr_pre(pre);
				break;
				
			case 3:
				cout<<"\nInorder Traversal : ";
				t.inorder(root);
				break;
				
			case 4:
				cout<<"\nPreorder Traversal : ";
				t.preorder(root);
				break;
				
			case 5:
				cout<<"\nPostorder Traversal : ";
				t.postorder(root);
				break;
				
			case 6:
				cout<<"\nInorder Traversal : ";
				t.nr_inorder(root);
				break;
				
			case 7:
				cout<<"\nPreorder Traversal : ";
				t.nr_preorder(root);
				break;
				
			case 8:
				cout<<"\nPostorder Traversal : ";
				t.nr_postorder(root);
				break;
				
				
			case 9: exit(0);
			
			default: cout<<"\nWrong Choice";
				
				
		}
		
	}while(ch!=9);
	
	

	

		
	return 0;
}
