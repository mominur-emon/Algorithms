/*find the strongly connected component having maximum nodes. The  algorithm is DFS based. It does DFS two times.*/

#include<bits/stdc++.h>
using namespace std;
void finishing_time(int v, vector<int> graph[],int visited[],stack<int> &s)
{
    visited[v]=1;
    for(int i=0;i<graph[v].size();i++)
    {
        if(!visited[graph[v][i]])
        {
            finishing_time(graph[v][i],graph,visited,s);
        }
    }
    s.push(v);
}
void dfs(int source, vector<int> revrse_graph[],int visited[])
{
    visited[source]=1;
    cout<<source<<" ";
    for(int i=0;i<revrse_graph[source].size();i++)
    {
        if(!visited[revrse_graph[source][i]])
        {
            dfs(revrse_graph[source][i],revrse_graph,visited);
        }
    }
}
int main()
{
    int nodes,edges;
    cout<<"enter the number of nodes and edges: ";
    cin>>nodes>>edges;
    vector<int> graph[nodes+1];
    vector<int> revrse_graph[nodes+1];
    cout<<"enter the X and Y: ";
    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        revrse_graph[y].push_back(x);
    }
    int visited[nodes+1];
    memset(visited,0,sizeof(visited));
    stack<int> s;
    for(int i=1;i<=nodes;i++)
    {
        if(!visited[i])
        {
            finishing_time(i,graph,visited,s);
        }
    }
    memset(visited,0,sizeof(visited));
    cout<<"strongly connected components of given directed graphs: " ;
    while(s.size()>0)
    {
        int top=s.top();
        s.pop();
        if(!visited[top])
        {
            dfs(top,revrse_graph,visited);
            cout<<endl;
        }
    }
    return 0;
}
