#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
class tree
{
	tree *left,*right;
	int data;
	public:
		tree* create(int);
		tree* insert(tree*,int);
		tree* search (tree*,int);
		void inorder(tree*);
		void preorder(tree*);
		void postorder(tree*);
		tree* delete_key(tree* , int);
		tree* leaf_nodes(tree *);
		tree* level_order(tree *);
		void parent_child_display(tree *);
		
};
class stack
{
	public:
		tree *item;
		stack *link;
		stack* push(stack* , tree * );
		stack* pop(stack* );
};

stack* stack::push(stack *top , tree *temp )
{
	
	stack *newnode=new stack;
	newnode->item=temp;
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

tree * tree::create(int key)
{
	tree *temp=new tree;			
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;

}
tree * tree::insert(tree* root, int key)
{
	cout<<"\nEnter the element to insert : ";
	cin>>key;
	tree *temp=create(key);
	if (root==NULL)
	{
		root=temp;
	}
	else
	{
		tree *curr=root;
		tree *parent;
		while(curr!=NULL && curr->data!=key)
		{
			parent=curr;
			if(key<curr->data)
				curr=curr->left;
			else
				curr=curr->right;
				
		}
		if (curr ==NULL)
		{
			if(key<parent->data)
				parent->left=temp;
			else
				parent->right=temp;
		}
		else
		{
			cout<<"Element Is Already Present "<<endl;
		}
	
	}
		return root;
}

tree * tree:: search(tree *root, int key)
{
	cout<<"\nEnter the element you want to search :";
	cin>>key;
	tree *curr=root;
	
	while( curr!=NULL && curr->data!=key )
	{
		if(curr->data<key)
			curr=curr->right;
		else
			curr=curr->left;
	}
	if(curr!=NULL)
	{
		cout<<"\nElement Found ";
	
	}
	else
	{
		cout<<"\nElement is not Present ";
	}
	
}

tree * tree:: delete_key(tree *root, int key)
{
	

 	tree *curr,*parent,*gp;
    curr=root;
    cout<<"\nEnter the element you want to delete :";
	cin>>key;
        while(curr!=NULL && curr->data!=key)      //searching
        {
            parent=curr;
            
            if(key<curr->data)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
        }

if(curr!=NULL)
{
	

        if(curr->right==NULL && curr->left==NULL)     //leaf node
        {
            if(curr!=root)
            {
                if(parent->left==curr)
                {
                    parent->left=NULL;
                }
                else
                {
                    parent->right=NULL;
                }
            }
            else
                root=NULL;
            cout<<"Deleted";
        }
        else if(curr->right!=NULL && curr->left!=NULL)       //node with 2 children
        {
            gp=curr;
            curr=curr->left;                                //first one left 
            parent=curr;
            while(curr->right!=NULL)                      // till largest inorder predecesssor
            {
                parent=curr;
                curr=curr->right;
            }
            gp->data=curr->data;
      
            //if(curr->left==NULL)
            if(parent==curr)
            {
                parent->right=NULL;
                gp->left=NULL;                      //case for root node having only left
                
            }
            else
            {
                parent->right=curr->left;
            }
            cout<<" Deleted";
        }
        
        else if(curr->left!=NULL)                    //single child
        {
            if(parent->right=curr)
            {
                parent->right=curr->left;
            }
            else
            {
                parent->left=curr->left;
            }
            cout<<" Deleted";
        }
        else if(curr->right!=NULL)
        {
            if(parent->right==curr)
            {
                parent->right=curr->right;
            }
            else
            {
                parent->left=curr->right;
            }
            cout<<" Deleted";
        }
        return root;
}
else
	{
		cout<<"\nElement is not Present ";
	}
        
    //return root;

}

void tree::inorder(tree *root)
{
	if(root==NULL)
	
		return;
	
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
}
void tree::preorder(tree *root)
{
	if(root==NULL)
	
		return;
	
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	
}
void tree::postorder(tree *root)
{
	if(root==NULL)
			return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
tree * tree:: leaf_nodes(tree *root)
{
	tree *curr=root;
	stack *top=NULL;
	
	top=top->push(top,curr);                             // push root node
	while(top!=NULL)
	{
		curr=top->item;                                  // stack not empty->pop
		top=top->pop(top);
		 
	if(curr->left !=NULL)                                // comparison
		top=top->push(top,curr->left);
	if(curr->right !=NULL)
		top=top->push(top,curr->right);  
	if(curr->left==NULL && curr->right==NULL)
		cout<<curr->data<<" ";
	}	
	
}


tree * tree::level_order(tree *root)
{
	
 
    if (root == NULL)  
	return 0; 
  
    
    queue<tree *> q; 
  
    
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        
        tree *node = q.front(); 
        
        cout << node->data << " "; 
        q.pop(); 
  
       
        if (node->left != NULL) 
            q.push(node->left); 
  
        
        if (node->right != NULL) 
            q.push(node->right); 
    } 
} 

void tree::parent_child_display(tree *root)
{
	
	tree* parent=root;
    if(parent->left!=NULL && parent->right!=NULL)
    {
    	cout<<"Parent : "<<parent->data<<"\t";
    	cout<<" Left Child : "<<parent->left->data<<"\t";
    	cout<<"\tRight Child : "<<parent->right->data<<endl;
    	parent_child_display(parent->left);
        parent_child_display(parent->right);
    }
    else if(parent->left==NULL && parent->right==NULL)
    {
    	return;
    }
    else if(parent->left==NULL && parent->right!=NULL)
    {
    	cout<<"Parent : "<<parent->data<<"\t\t\t\t";
    	cout<<"Right Child : "<<parent->right->data<<endl;
        parent_child_display(parent->right);
    }
    else if(parent->right==NULL && parent->left!=NULL)
    {
    	cout<<"Parent : "<<parent->data<<"\t";
    	cout<<" Left Child : "<<parent->left->data<<"\t"<<endl;
        parent_child_display(parent->left);
    }
    
}	
	
int main()
{
	int n,key,ch;
	tree t;
	tree *root=NULL;
	
	do 
	{
		cout<<endl;
		cout<<"\n1.Getdata\n2.Display\n3.Search\n4.Delete\n5.Display Leaf nodes\n6.Level order\n7.Display Parent and Child nodes\n8.Exit"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		switch (ch)
		{
			case 1:
				cout<<"\nEnter the number of elements :";
				cin>>n;
				for(int i=0;i<n;i++)
				{
					root=t.insert(root,key);
				}
			break;
			
			case 2:
				
				cout<<endl;
				
				cout<<"Inorder Traversal : ";
				t.inorder(root);
				
				cout<<"\nPreorder Traversal : ";
				t.preorder(root);
				
				cout<<"\nPostorder Traversal : ";
				t.postorder(root);
			
			break;
			
			case 3:
					t.search(root,key);
					
			break;
			
			case 4:
					t.delete_key(root,key);
					break;
			case 5:
					cout<<"\nLeaf nodes in the BST : ";
					t.leaf_nodes(root);
			break;
			case 6:
				cout<<"Level Order Traversal : ";
				t.level_order(root);
				break;
			case 7:
				cout<<"Result"<<endl;
				t.parent_child_display(root);
				
			
			case 8: exit(0);
			
			default: cout<<"\nWrong Choice";
				
	}
		
	}while(ch!=8);
	
	return 0;
}
