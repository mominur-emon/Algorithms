/*A weighted directed graph from user and apply Dijkstra algorithm to find shortest path from source node to all other nodes. */


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
int nd,weight;
}temp;

vector < node > G[100];
bool vis[100]; int dist[100];

class cmp
{
public:
    bool operator() (node &A, node &B){
        if (A.weight > B.weight) return true;
        return false;
    }
};

void dijkstra(int s)
{
    priority_queue<node, vector<node>, cmp> PQ;
    PQ.push({s, 0});

    while(!PQ.empty()){
        node current = PQ.top();
        PQ.pop();

        int nd = current.nd;
        int weight = current.weight;

        if (vis[nd] == 1) continue;

        dist[nd] = weight;
        vis[nd] = 1;

        for (int i = 0; i < G[nd].size(); i++){
            int nxt = G[nd][i].nd;
            int nxtCost = G[nd][i].weight;

            if (vis[nxt] == 0){

                PQ.push({nxt, weight + nxtCost});
            }
        }
    }
}

int main()
{
    int nodes, edges,u, v,w, i,s;

    cout<<"Enter node and edges : ";
    cin >> nodes >> edges;

     cout<<"Enter ' u v w ' "<<endl;
      for(i = 0 ; i < edges ; i++)
    {
        cin>> u>>v>>w ;
        temp.nd=v;
        temp.weight=w;
        G[u].push_back(temp);
        temp.nd=u;
        G[v].push_back(temp);
    }

    cout << "Enter source : ";
    cin >> s;

    dijkstra(s);

    for (int i = 1; i <= nodes; i++){


        cout <<"Node "<< i << " Cost: "<<dist[i]<< " \n";

     }

    return 0;
}
