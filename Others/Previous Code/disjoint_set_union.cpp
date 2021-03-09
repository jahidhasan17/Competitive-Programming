#include <bits/stdc++.h>
using namespace std;

int parent[100];

int Find(int reprasentative)
{
	if(parent[reprasentative]==reprasentative)
	{
		return reprasentative;
	}
	
	return parent[reprasentative]=Find(parent[reprasentative]);
}

void Union(int a,int b)
{
	int u=Find(a);
	int v=Find(b);
	if(u!=v)
	{
		parent[u]=v;
	}
}

int main()
{
	for(int i=0;i<100;i++)
	{
		parent[i]=i;
	}
	int n;
	cin>>n;
	set<int>se;
	for(int i=0;i<n;i++)
	{
		int q,w;
		cin>>q>>w;
		Union(q,w);
		se.insert(q);
		se.insert(w);
	}

	for(auto it=se.begin();it!=se.end();it++)
	{
		cout<<*it<<" "<<Find(*it)<<endl;
	}

	//Check 3 and 5 friend or not
	if(Find(3)==Find(5))
	{
		cout<<"3 and 5 are friend"<<endl;
	}
	else cout<<"NOT Friend"<<endl;
}
/*
5
1 3
3 5
2 3
4 5
6 7
*/