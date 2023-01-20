```
INPUT
7 7
1 2
1 3
3 4
3 7
4 6
4 5
6 7

OUTPUT
Total number of bridge:3
1 and 2 is bridge.
```

```
Main concept
	
	suppose v is a child of u.

	But-1# (low[u]==low_of_subtree_of_v[v])
	তাহলে v এর কোন subtree এর child এর low এর
	মান যদি u এর সমান হয় তার মানে ওই node থেকে 
	u এর সাথে এক এর বেশী connection আছে।
	
	তাহলে (u-v) এই road টা articulation bride না।
```

```c++
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
int time_count=0;
int cnt=0;
int is_bridge[N];

bool is_the_road_is_bridge(int x,int y){
	if(is_bridge[x]==1 and parent[x]==y) return 1;
	if(is_bridge[y]==1 and parent[y]==x) return 1;
	return 0;
}

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

			if(discovery_time[u]<low[it]){
				cnt++;
				is_bridge[it]=1;
				//if discovery_time[u]==low[it] that means subtree 
				//of a child of u is connected by u more than one road.
				//so this road (u==it) is not the articulation bridge
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

	printf("Total number of bridge:%d\n",cnt);
	if(is_the_road_is_bridge(1,2)){
		printf("1 and 2 is bridge.\n");
	}
}

main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
```