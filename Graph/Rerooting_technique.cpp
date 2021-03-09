//prob link-https://codeforces.com/problemset/problem/1324/F

/*
	Rerooting technique

First find the ans for a fixed root(node).
Then find answer for all other node by
changing root.That means we find solution
for a node by changing it root.This is 
re-rooting technique.
*/

/*Input
9
0 1 1 1 0 0 0 0 1
1 2
1 3
3 4
3 5
2 6
4 7
6 8
5 9

Output
2 2 2 2 2 1 1 0 2 

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n;
vector<int>v[200005];
int ar[200005];

//For find answer a fixed root(such as 1);
void dfs(int u,int parent){
	for(auto it:v[u]){
		if(it==parent) continue;
		dfs(it,u);
		if(ar[it]>=0) ar[u]+=ar[it];
	}
}

/* For find a answer all other node
 by re-rooting */
void dfs1(int u,int parent){
	for(auto it:v[u]){
		if(it==parent) continue;
		int x=ar[u]-max(0,ar[it]);
		if(x<0) x=0;
		ar[it]+=x; // changing root
		dfs1(it,u);
	}
}

void solve(){
	cin>>n;
	for(int i=1; i<=n; i++){
		int q;cin>>q;
		if(q==0) q=-1;
		ar[i]=q;
	}
	for(int i=1; i<n; i++){
		int u,vv;cin>>u>>vv;
		v[u].pb(vv);
		v[vv].pb(u);
	}
	dfs(1,-1);
	dfs1(1,-1);
	for(int i=1; i<=n; i++){
		cout<<ar[i]<<" ";
	}
}

main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}