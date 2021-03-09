#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100],cost[100];
const int infinity=1000000;
int d[100],vi[100];

void bfs(int source)
{


	queue<int>q;
	q.push(source);
	d[source]=0;

	while(!q.empty())
	{
		int u=q.front();

		int ucost=d[u];
		q.pop();

		for(int i=0;i<edge[u].size();i++)
		{
			int v=edge[u][i],vcost=cost[u][i]+ucost;
			if(d[v]>vcost)
			{
				d[v]=vcost;
				q.push(v);
				
			}
		}
	}
	
}


int main()
{
	for(int i=0;i<100;i++) d[i]=infinity;
	int  ea,n;
	cin>>ea>>n;
	for(int i=0;i<ea;i++)
	{
		int node1,node2,w;
		cin>>node1>>node2>>w;
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
		cost[node1].push_back(1);
		cost[node2].push_back(1);

	}
	bfs(2);
	for(int i=0;i<=n;i++)
    {
        cout<<"2--"<<i<<" "<<d[i]<<endl;
    }

    return 0;
}
