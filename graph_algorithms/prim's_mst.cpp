#include <bits/stdc++.h>
#define mx 100
using namespace std;
bool visit[mx];
int dist[mx];
int parent[mx];
int node,edge;
struct Node
{
    int v;
    int cost;
};
vector<Node> graph[mx];
void init()
{
    for(int i=0; i<mx; i++)
    {
        dist[i]=INT_MAX;
        visit[i]=false;
        parent[i]=-1;
    }
}

bool operator<(Node a,Node b)
{
    return a.cost>b.cost;
}

void prims(int src)
{
    priority_queue<Node> pq;
    dist[src]=0;
    pq.push({src,0});
    int total_cost=0;

    while(!pq.empty())
    {
        Node current = pq.top();
        pq.pop();
        int val=current.v;
        int cost=current.cost;
        if(visit[val])
        {
            continue;
        }
        visit[val]=true;
        total_cost+=cost;
        for(int i=0; i<graph[val].size(); i++)
        {
            int nxtval=graph[val][i].v;
            int nxtcost=graph[val][i].cost;
            if(visit[nxtval]==1)
            {
                continue;
            }
            if(nxtcost<dist[nxtval])
            {
                pq.push({nxtval,nxtcost});
                dist[nxtval]=nxtcost;
                parent[nxtval]=val;

            }
        }

    }
    cout<<"Total cost of MST is ";
    cout<<total_cost<<endl;


}
void printMST(int src)
{
     cout<<"Edge \tWeight\n";
    for (int i = 1; i <= node; i++) {
        if(i !=src)
        cout<<parent[i]<<" - "<<i<<" \t"<<dist[i]<<" \n";

    }

}

int main()
{
    init();
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        graph[u].push_back({v,weight});
        graph[v].push_back({u,weight});
    }
    int src;
    cin>>src;
    prims(src);
    printMST(src);


}
