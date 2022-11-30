#include<iostream>
using namespace std;

class node
{
	public:
    	int data;
    	node * left;
    	node * right;
    	bool rthread,lthread;
};


class tbt
{
    node * root;
public:
    node * insert(node *,node *);
   	node * create(int );
    node * leftmostnode(node *);
    void inorder(node *,node * );
    node * preorder(node *,node *);

};

node * tbt :: create(int key)
{
    node * newnode=new node;
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->lthread = true;
    newnode->rthread = true;
    
}

node * tbt :: insert(node * root,node *top)
{
    int key;
    node * curr;
    cout<<"Enter the element to insert : ";
    cin>>key;
    node * newnode = create(key);
    

    if(root==NULL)
    {
        top->left=newnode;
        root=newnode;
        root->left=root->right=top;
        top->lthread=false;
        return root;
    }
    else
    {
        curr=root;
        while(curr!=NULL)
        {
        if (curr->data==key) 
        { 
            cout<<"Element already present !!\n"; 
            return root ;
            break;
             
        } 
            if(key<curr->data)
            {
                if(curr->lthread)
                {
                     break;
                }
                else
                {
                    curr=curr->left;
                }

            }
          
            else
            {
                if(curr->rthread)
                {
                    break;
                }
                curr=curr->right;
            }
        }
        if(key<curr->data)
        {
            newnode->left=curr->left;
            curr->left=newnode;
            newnode->right=curr;
            curr->lthread=false;
        }
        else
        {
            newnode->left=curr;
            newnode->right=curr->right;
            curr->right=newnode;
            curr->rthread=false;
        }
    }
    return root;
}


node * tbt :: leftmostnode(node *temp) 
{
    if(temp == NULL)
    {
        return NULL;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->lthread)
            {
                break;
            }
            temp = temp->left;
        }
        return temp;
    }
}

void tbt :: inorder(node *root,node *head)
{
    node * curr;
    curr = leftmostnode(root);
    while(curr != head)
    {

            cout<<curr->data<<" ";
            if(curr->rthread)
            {
                curr = curr->right;
            }
            else
            {
                curr = leftmostnode(curr->right);
            }

    }
}

node * tbt::preorder(node * root, node* head)
{
    node * curr=root;
    while(curr!=head)
    {
        cout<<curr->data<<" ";
        if(curr->lthread==false)
            curr=curr->left;
        else if(curr->rthread==false)
            curr=curr->right;
        else
        {
            while(curr->rthread==true)
            {
                curr=curr->right;
            }
            curr=curr->right;
        }
    }
}



int main()
{
    node * root = NULL;
    node * head = new node;
    head->left = head->right = root;
    head->lthread = true;
    tbt t;
    int ch;

    do
    {

        cout<<"\n1.Create a tree.\n2.Inorder traversal.\n3.Preorder traversal.\n4.Exit. "<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;

        switch(ch)
        {

        case 1:
            root = t.insert(root,head);
            break;
        case 2:
            t.inorder(root,head);
            break;
        case 3:
            t.preorder(root,head);
            break;
        case 4:
            exit(0);
			
			
			default: cout<<"\nWrong Choice";
        }
    }while(ch != 4);
    
    return 0;
}


















