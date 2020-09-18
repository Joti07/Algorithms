#include <bits/stdc++.h>
#define MX 105
#define INF 1000000000
using namespace std;
typedef long long ll;
struct node
{
    ll val;
    ll cost;

};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
vector<node> graph[MX];

ll vis[MX];
ll dist[MX];
void reset()
{
    for (int i = 0; i < MX; i++)
    {
        graph[i].clear();
        vis[i]=0;
        dist[i] = INF ;
    }
}

void dijkstra(ll s)
{

    //dist[s]=0;
    priority_queue<node> pq;
    pq.push({s,0});
    while(!pq.empty())
    {
        node current =pq.top();
        pq.pop();
        ll val =current.val;
        ll cost=current.cost;
        if(vis[val]==1)
        {
            continue;
        }
        dist[val]=cost;
        vis[val]=1;
        for(int i=0;i<graph[val].size();i++)
        {
            ll nxt = graph[val][i].val;
            ll nxtCost=graph[val][i].cost;

            if(vis[nxt]==0)
            {
                pq.push({nxt,cost+nxtCost});
            }
        }
    }
}

int main()
{
    reset();
    ll Node,Edge;
    cin>>Node>>Edge;
    for(int i=1; i<=Edge; i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    cout<<"Enter source: ";
    ll s;
    cin>>s;

    dijkstra(s);

    for(int i=1; i<=Node; i++)
    {
        cout<<"Node "<<i<<" Distance: ";
        if(dist[i]==INF)
            cout<<"inf"<<endl;
        else
            cout<<dist[i]<<endl;
    }

}
