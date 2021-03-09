/*INPUT
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
int vis[105];

struct node
{
	int city,dist;
	bool operator<(const node &seg)const{
		return dist<seg.dist;
	}
};


int MST(int s){
	vis[s]=0;
	priority_queue<node>q;
	q.push({0,0});
	int sum=0;
	while(!q.empty()){
		auto it=q.top();
		q.pop();
		if(vis[it.city]==0){
			sum+=it.dist;
			vis[it.city]=1;
		}
		//cout<<it.city<<" "<<it.dist<<endl;
		for(int i=0; i<v[it.city].size(); i++){
			int new_node=v[it.city][i],new_cost=cost[it.city][i];
			if(vis[new_node]==0){
				q.push({new_node,new_cost});
			}
		}
	}
	return sum;
}

void solve(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,vv,w;cin>>u>>vv>>w;
		v[u].pb(vv);
		v[vv].pb(u);
		cost[u].pb(w);
		cost[vv].pb(w);
	}
	int Maximum_cost=MST(0);
	cout<<Maximum_cost<<endl;
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}