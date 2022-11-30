//Minimum Spanning Trees
#include<iostream>
using namespace std;
class graph
{
		int source , dest , weight ;
		public:
			void accept();
    		void display();
    		void sort(graph *[],int);
    		int findParent(int,int *);
    		graph *kruskal(graph *[],int);
	
};
void graph::accept()
{
    cout<<"\nEnter source vertex : ";
    cin>>source;
    cout<<"\nEnter the destination vertex : ";
    cin>>dest;
    cout<<"\nEnter the weight of the edge  : ";
    cin>>weight;
}

void graph::display()
{
    cout<<source<<"\t\t"<<dest<<"\t\t\t"<<weight<<"\n";
}
void graph::sort(graph * edge[],int n)
{
    int i,j;
    graph *temp = NULL;
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(edge[j]->weight > edge[j+1]->weight)
            {
                temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }

}

int graph::findParent(int v,int *parent)
{
    if(parent[v] == v)
        return v;
    return findParent(parent[v],parent);
}


graph *graph::kruskal(graph * edge[],int v)
{
    int i,count=0,p=0;
    int *parent = new int[v];
    for(i=0;i<v;i++)
    {
        parent[i] = i;
    }
    cout<<"\nMinimum Spanning Tree : "<<endl;
    cout<<"\nSource\t\tDestination\t\tWeight\n";
    while(count!=(v-1))
    {
        int source = findParent(edge[p]->source,parent);
        int dest = findParent(edge[p]->dest,parent);
        if(source!=dest)
        {
            cout<<"\n"<<edge[p]->source<<"\t\t"<<edge[p]->dest<<"\t\t\t"<<edge[p]->weight;
            parent[source] = dest;
            count++;
        }
        p++;
    }
}
int main()
{
	graph *edge[10];
    graph *temp;
    int v,i,e,ch;
    do
    {
    	cout<<"\n1.Create a Graph\n2.Display the Sorted Graph\n3.Display Minimum Spanning Tree\n4.Exit"<<endl;
    	cout<<"Enter your choice : ";
    	cin>>ch;
    	
    	switch(ch)
    	{
    		case 1:
    			cout<<"\nEnter total number of vertices : ";
                cin>>v;
                cout<<"\nEnter total number of edges : ";
                cin>>e;
                for(i=0;i<e;i++)
                 {
                    edge[i]=new graph;
                    edge[i]->accept();
                 }
    		break;
    		
    		case 2:
    			temp->sort(edge,e);
            	cout<<endl;
            	cout<<"Graph after Sorting Edges :"<<endl;
                cout<<"\nSource\t\tDestination\t\tWeight\n";
                for(i=0;i<e;i++)
                {
                    edge[i]->display();
                }
    			
    			
    		break;
    		
    		case 3:
    			edge[i]->kruskal(edge,v);
    			
    		break;
    		
    		case 4:
    			exit(0);
    			
    			
    			default: printf("\nWrong Choice");
		}
    	
	}while(ch!=4);
     				
   return 0;             
            
            	
            
             
}

