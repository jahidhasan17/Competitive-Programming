#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define UN unsigned int
#define mod 1000000007
#define F first
#define S second
#define mk make_pair
#define B(v) v.begin(), v.end()
#define BS binary_search
vector<int>edge[100001],cost[100001];
int d[10000];
void bfs(int s)
{
	for(int i=0;i<100;i++) d[i]=10000;
	d[s]=0;
	queue<int>q;
	q.push(s);

	while(!q.empty())
	{
		int qq=q.front();
		q.pop();
		for(int i=0;i<edge[qq].size();i++)
		{
			if(d[edge[qq][i]]>(cost[qq][i]+d[qq]))
			{
				d[edge[qq][i]]=(cost[qq][i]+d[qq]);
				q.push(edge[qq][i]);	
			}
		}
	}
}

int main()
{
	
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int q,w,r;
		cin>>q>>w>>r;
		edge[q].pb(w);
		edge[w].pb(q);
		cost[q].pb(r);
		cost[w].pb(r);
	}
	bfs(4);
	for(int i=1;i<=4;i++)
	{
		cout<<d[i]<<endl;
	}
}
/*
6
1 2 2
1 3 4
1 4 1
2 3 3
2 4 5
3 4 2
*/