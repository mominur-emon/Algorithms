/*A weighted directed graph from user and apply Bellman Ford algorithm to find shortest path from source node to all other nodes.*/
/*  this time algorithm has to be able to detect negative cycle.*/

#include<iostream>
#include<vector>

using namespace std;


struct edge{

	int src,dst,wt;

};

void bellmanFord(vector<edge>&e, int V, int E,int s)
{
	int parent[V];
	int cp[V];

	vector<int> value(V,99999);
	value[s] = 0;
	parent[s]=-1;

	bool updated;

	for(int i=0;i<V-1;i++)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = e[j].src;
			int V = e[j].dst;
			int wt =e[j].wt;

			if(value[U]+wt < value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
				cp[V] = value[V];
				updated = true;
			}
		}

		if(updated==false)
			break;
  }

	for(int j=0;j<E && updated==true;j++)
		{
			int U = e[j].src;
			int V = e[j].dst;
			int wt =e[j].wt;

			if(value[U]+wt < value[V])
			{
				cout<<"present negative cycle. \n";
				return;
			}
		}
	for(int i=1;i<V;i++)
      cout<<parent[i]<<"->"<<i<<"  Cost: "<<value[i]<<"\n";
}

int main()
{
	int src,dst,wt,s,V,E;
	vector<edge> e(E);

    cout<<"Enter the number of node & edges : ";
	cin>>V>>E;

   cout<<"Enter 'src dst wt' : \n";

	for(int i=0;i<E;i++)
	{
		cin>>src>>dst>>wt;

		e[i].src = src;
		e[i].dst = dst;
		e[i].wt = wt;
	}

	cout<<"Enter source : ";
	cin>>s;

	bellmanFord(e,V,E,s);

	return 0;
}

