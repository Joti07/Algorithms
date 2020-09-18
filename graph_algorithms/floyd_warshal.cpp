#include <bits/stdc++.h>
#define inf 10000000
#define mx 105
using namespace std;

int parent[1005][1005];
int graph[1005][1005];
int pathfind(int src,int dst)
{
    if(src==dst)
    {
        cout<<"path: "<<src;
        return 0;
    }
    pathfind(src,parent[src][dst]);
    cout<<" "<<dst;
}
void init()
{
    for(int i=1; i<=mx; i++)
    {
        for(int j=1; j<=mx; j++)
        {
            if(i==j)
                graph[i][j]=0;
            else
                graph[i][j]=inf;
            parent[i][j]=i;
        }
    }
}
void print(int node)
{
    cout<<"cost"<<endl;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            if(graph[i][j]==inf)
                cout<<"INF ";
            else
                cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"pie"<<endl;
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            if(parent[i][j]==10000000)
                cout<<"N ";
            else
                cout<<parent[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floyd_warshal(int node)
{


    for(int k=1; k<=node; k++)
    {
        for(int i=1; i<=node; i++)
        {
            for(int j=1; j<=node; j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                    parent[i][j]=parent[k][j];
                }
            }

        }

        print(node);


    }
}

int main()
{

    init();
    int node,edge;
    cin>>node>>edge;

    for(int i=1; i<=edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    for(int i=1; i<=node; i++)
    {
        for(int j=1; j<=node; j++)
        {
            if(graph[i][j]==0 || graph[i][j]==10000000)
            {
                parent[i][j]=10000000;
            }
        }
    }

    print(node);
    floyd_warshal(node);

    while(1)
    {
        int src,dest;
        cout<<"Enter source and destination: ";
        cin>>src;
        cin>>dest;
        cout<<"Distance: "<<graph[src][dest]<<endl;
        pathfind(src,dest);

    }





}
