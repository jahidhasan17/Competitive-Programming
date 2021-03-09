/*INPUT
7 7
1 2
1 3
3 4
3 7
4 6
4 5
6 7

OUTPUT
3
*/

//Main concept
/*
	suppose v is a child of u.

	#সাধারণত low[u]<low[v]
	
	But-1# (low[u]==low_of_subtree_of_v[v])
	তাহলে v এর কোন subtree এর child এর low এর
	মান যদি u এর সমান হয় তার মানে ওই node থেকে 
	u এর সাথে এক এর বেশী connection আছে।

	else But-2#(low[u]>low_of_subtree_of_v[v])
	তার মানে u এর ancestor এর সাথে v বা এর subtree
	এর কোন node এর connection
	আছে। তাইলে (u) এইটা articulation point na 
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N=10005;

int n,m;
vector<int>v[N];
int discovery_time[N];
int low[N];
int visited[N];
int parent[N];
int calculate_articulation[N];
int time_count=0;

void find_articulation(int u){
	time_count++;
	low[u]=discovery_time[u]=time_count;
	visited[u]=1;

	int child=0;

	for(auto it:v[u]){
		if(parent[u]==it) continue;

		if(visited[it]==0){
			child++;
			parent[it]=u;
			find_articulation(it);
			low[u]=min(low[u],low[it]);

			if(discovery_time[u]<=low[it] and parent[u]!=-1){
				calculate_articulation[u]=1;
			}
			if(parent[u]==-1 and child>1){
				calculate_articulation[u]=1;
			}

		}else if(visited[it]){
			low[u]=min(low[u],discovery_time[it]);
		}
	}
	time_count++;
}


void solve(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		v[i].clear();
		discovery_time[i]=low[i]=visited[i]=0;
		parent[i]=-1;
		calculate_articulation[i]=0;
	}
	for(int i=0; i<m; i++){
		int u,vv;cin>>u>>vv;
		v[u].pb(vv);
		v[vv].pb(u);
	}

	for(int i=1; i<=n; i++){
		if(visited[i]==0){
			find_articulation(i);
		}
	}
	
	int cnt=0;

	for(int i=1; i<=n; i++){
		cnt+=calculate_articulation[i];
	}

	printf("%d\n",cnt);
}

main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}