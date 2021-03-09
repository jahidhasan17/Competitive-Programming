/*
INPUT
3 4
0 1 99
0 2 10
1 2 30
2 3 30

OUTPUT
159
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
 

int n,m;
vector<int>v[105],cost[105];

struct node
{
	int st,en,dist;
	bool operator<(const node &seg)const{
		return dist<seg.dist;
	}
};

vector<node>pa;
int dsu[105];

int find(int u){
	if(dsu[u]==u) return u;
	return dsu[u]=find(dsu[u]);
}

void solve(){
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		int u,vv,w;
		cin>>u>>vv>>w;
		pa.pb({u,vv,w});
	}
	
	sort(pa.rbegin(),pa.rend());

	for(int i=0; i<=n; i++) dsu[i]=i;
	int Minimum_cost=0;
	for(int i=0; i<m; i++){
		int uu=find(pa[i].st);
		int vv=find(pa[i].en);
		if(uu!=vv){
			dsu[uu]=vv;
			Minimum_cost+=pa[i].dist;
		}
	}
	cout<<Minimum_cost<<endl;
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}