#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n,m;
vector<int>v[205],cost[205];
int dist[205];

bool belmen_ford(int source){
	for(int i=1; i<=n; i++) dist[i]=1000000;
	dist[source]=0;
	for(int q=1; q<n; q++){ // For relaxation all node node for (number of node - 1) times.
		for(int i=1; i<=n; i++){
			for(int j=0; j<v[i].size(); j++){
				int new_node=v[i][j],new_cost=cost[i][j];
				if((dist[i]+new_cost)<dist[new_node]){
					dist[new_node]=(dist[i]+new_cost);
				}
			}
		}
	}
	bool is_negative_cycle=0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<v[i].size(); j++){
			int new_node=v[i][j],new_cost=cost[i][j];
			if((dist[i]+new_cost)<dist[new_node]){
				is_negative_cycle=1;
				break;
			}
		}
		if(is_negative_cycle) break;
	}
	return is_negative_cycle;
}


void solve(){
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u,vv,w;cin>>u>>vv>>w;
		v[u].pb(vv);
		cost[u].pb(w);
	}
	if(belmen_ford(1)) cout<<"Negative cycle is found"<<endl;
	else cout<<"Negative cycle is not found"<<endl;
}

main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}