//Shortest Path tree
#include<iostream>
using namespace std;
class graph
{
	int mat[10][10];
	int source , dest , distance , v , e;
	public:
		void getdata();
	
		void display(int [],int [],int);
		void display_matrix();
		int min_dist(int [] , bool []);
		void dijkstra();
		void path(int [],int);
		
	
};

void graph::getdata()
{
		cout<<"\nEnter total number of vertices : ";
        cin>>v;
        cout<<"\nEnter total number of edges : ";
        cin>>e;
        for(int i=0 ; i<v ;i++)		                         
		{
			for(int j=0 ; j<v ;j++)
			{
				mat[i][j]=0;
			}
		}
		for( int i=0 ; i<e ; i++)
		{
			cout<<"\nEnter source vertex : ";
	    	cin>>source;
	    	cout<<"\nEnter the destination vertex : ";
	    	cin>>dest;
	    	cout<<"\nEnter the distance of the edge  : ";
	    	cin>>distance;
	    	
	    	mat[source][dest]=distance;
			mat[dest][source]=distance;
		}
	
	
		
	
}




void graph::display_matrix()
{
	cout<<"Adjacency Matrix is : "<<endl;
	for(int i=0;i<v;i++)
	{
			for(int j=0;j<v;j++)
			{
				cout<<mat[i][j]<<"\t";
			}
			cout<<"\n";
		
	}
}
int graph::min_dist(int dist[], bool visit[]) 
{ 
    
    
    int min_index=0;
    int max=999;

    for(int i=0;i<v;i++)
    {
        if(visit[i]==false && dist[i]<max)
        {
            max=dist[i];
            min_index=i;
        }
    }
    return min_index;
} 



void graph::dijkstra()
{
	


	int parent[v],dist[v];
    bool visit[v];
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
        dist[i]=999;
        visit[i]=false;
    }

    int source;
    cout<<"\nEnter source vertex:";
    cin>>source;

    dist[source]=0;

    for(int i=0;i<v;i++)
    {
        int s;

        s=min_dist(dist,visit);
        visit[s]=true;
        for(int k=0;k<v;k++)
        {
            if((mat[s][k]!=0) && visit[k]==false  &&  dist[s]+mat[s][k] < dist[k])
            {
                dist[k]=dist[s]+mat[s][k];
                parent[k]=s;
            }
        }
        /*for(int j=0;j<v;j++)
        {
            cout<<dist[j]<<"  ";
        }
        cout<<"\n";*/

    }
    display(parent,dist,source);
	
} 
void graph::path(int parent[],int i)
{
    if(parent[i]==i)        
    {
        return;
    }
    path(parent,parent[i]);
    cout<<"->"<<i;
}

void graph::display(int parent[],int dist[],int source)
{
    cout<<"\nVertex\tDistance from source\tPath"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<endl;
        cout<<i<<"\t\t"<<dist[i]<<"\t\t"<<source;
        path(parent,i);
    }
}

int main()
{
	graph g;
	g.getdata();
	g.display_matrix();
	g.dijkstra();
	
	return 0;
}
