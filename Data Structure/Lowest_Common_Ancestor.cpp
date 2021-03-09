/*INPUT
11
3 10
0 1
0 2
0 3
0 8
2 4
4 5
5 6
5 7

OUTPUT
Longest Common Ancestor of 2 and 3 is: 0
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back


const int N=100005;

int n;
vector<int>v[N];
int P[N][22];
int T[N];
int L[N];

void dfs(int u,int parent,int dep){
	T[u]=parent;
	L[u]=dep;
	for(auto it:v[u]){
		dfs(it,u,dep+1);
	}
}

void lca_init(){
	memset(P,-1,sizeof(P));
	for(int i=0; i<n; i++){
		P[i][0]=T[i];
	}

	for(int j=1; (1<<j) < n; j++){
		for(int i=0; i<n; i++){
			if(P[i][j-1]==-1) continue;
			P[i][j]=P[P[i][j-1]][j-1];
		}
	}
}

	int log=0;
	if(L[p]<L[q]) swap(p,q);
	
	while(1){
		if((1<<log)>L[p]){
			log--;
			break;
		}
		log++;
	}

	for(int i=log; i>=0; i--){
		if((L[p]-(1<<i))>=L[q]){
			p=P[p][i];
		}
	}
	if(p==q) return p;
	for(int i=log; i>=0; i--){
		if(P[p][i]!=-1 && P[p][i]!=P[q][i]){
			p=P[p][i];
			q=P[q][i];
		}
	}
	return T[p];
}

void solve(){
	cin>>n;
	for(int i=0; i<n; i++){
		int u,vv;cin>>u>>vv;
		v[u].pb(vv);
	}
	dfs(0,-1,0);
	lca_init();

	cout<<"Longest Common Ancestor of "<<2<<" and "<<3<<" is: "<<lca_query(2,3)<<endl;
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}