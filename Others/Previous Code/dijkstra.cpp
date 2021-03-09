#include <bits/stdc++.h>
using namespace std;

vector<int>edge[100],cost[100];
const int infinity=1000000;
int d[100];

struct data
{
    int city,dist;
};
bool operator<(data a,data b)
{
    return a.dist>b.dist;
}


void dijk(int source)
{
    priority_queue<data>q;
    data u,v;
    u.city=source;
    u.dist=0;
    q.push(u);
    d[source]=0;

    while(!q.empty())
    {
        u=q.top();
        q.pop();
        int ucost=d[u.city];
        for(int i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i];
            v.dist=cost[u.city][i]+ucost;
            if(d[v.city]>v.dist)
            {
                d[v.city]=v.dist;
                q.push(v);
            }
        }
    }

}

int main()
{
    for(int i=0;i<100;i++) d[i]=infinity;
    int e,n;
    cin>>e>>n;
    for(int i=0;i<e;i++)
    {
        int node1,node2,w;
        cin>>node1>>node2>>w;
        edge[node2].push_back(node1);
        edge[node1].push_back(node2);
        cost[node1].push_back(w);
        cost[node2].push_back(w);
    }
    dijk(0);
    for(int i=0;i<=n;i++)
    {
        cout<<"0--"<<i<<" "<<d[i]<<endl;
    }
    return 0;
}
