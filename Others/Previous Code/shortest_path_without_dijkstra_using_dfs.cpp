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

void dfs(int s,int l)
{
	d[s]=l;

	for(int i=0;i<edge[s].size();i++)
	{
		if(d[edge[s][i]]>(cost[s][i]+d[s]))
		{
			dfs(edge[s][i],(cost[s][i]+d[s]));
		}
	}
}

int main()
{
	for(int i=0;i<1000;i++) d[i]=100000;
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
	dfs(1,0);
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