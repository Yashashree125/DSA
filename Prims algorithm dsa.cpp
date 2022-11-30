//Minimum Spanning Trees
#include<iostream>
using namespace std;
class graph
{
	
	int mat[10][10];

	public:
		
		int source , dest , weight ,v,  e ;
		void getdata();
		//void display_matrix();
		int minkey(int [] , bool []);
		void prim();
		void display(int [] );
	
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
	    	cout<<"\nEnter the weight of the edge  : ";
	    	cin>>weight;
	    	
	    	mat[source][dest]=weight;
			mat[dest][source]=weight;
		}
	
		//mat[source][dest]=weight;
		//mat[dest][source]=weight;
		
	
}

/*void graph::display_matrix()
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
}*/

int graph::minkey(int key[],bool visit[])
{
 
 	int p;
  	int max=999;
  	int min_index=0;
  	
    for (p=0; p<v; p++)  
    {
    	
	
        if (visit[p] == false && key[p] < max) 
		{
			max = key[p];
			min_index = p;
			
		 } 
    }                                        //if value is less accept 
  	return min_index;                        // and that becomes parent 
	
}

void graph::display(int parent[])
{
	int i;
	cout<<"\nMinimum Spanning Tree :  "<<endl;
	cout<<endl;
	cout<<"Edge\t\tWeight\n";  
    for (i = 0; i < v; i++)  
    {
    	if(mat[i][parent[i]]!=0)
			cout<<parent[i]<<" -> "<<i<<" \t\t"<<mat[i][parent[i]]<<" \n";
	}
        
	
	
}

void graph::prim()
{
	int j,a;
	int parent[v];                                    //store mst
	int key[v];                                       //min weight
	bool visit[v];
	for(int i=0 ; i<v ; i++)
	{
		key[i]=999;
		visit[i]=false;
		parent[i]=i;
	}
	
	cout<<endl;
	cout<<"\nSource Vertex for MST : ";
	cin>>source;

	key[source]=0;		                                   //start vertex
	for(a=0;a<v;a++)
	{
		int u = minkey(key, visit);
		visit[u] = true; 
		for (int j = 0; j<v; j++) 
		{
			if ((mat[u][j]!=0) && visit[j] == false && mat[u][j] < key[j])
			{
				
				parent[j] = u; 
				key[j] = mat[u][j]; 
			}
				
		}
	}
	display(parent); 
	
}

int main()
{
	//int mat[10][10];
	graph g;
	g.getdata();
	//g.display_matrix();
	g.prim();
	return 0;
}

