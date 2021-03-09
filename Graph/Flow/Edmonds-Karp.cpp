//Referece: cp_algorithm

/*
INPUT

4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20

OUTPUT

Max Flow is: 25

*/


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007

struct Flowedge
{
	int u,v,cap,flow=0;
};

struct Dinic
{
	int N,M=0;
	vector<Flowedge>edge;
	vector<vector<int>>adj;
	Dinic(){}
	Dinic(int _N){
		N = _N+10;
		adj.resize(N);
	}
	void add_edge(int u,int v,int cap){
		edge.pb({u,v,cap});
		edge.pb({v,u,0});
		adj[u].pb(M);
		adj[v].pb(M+1);
		M += 2;
	}

	int bfs(int st,int en){
		int path[N];
		memset(path,-1,sizeof(path));
		queue<int>q;
		q.push(st);
		path[st] = -2;
		while(!q.empty()){
			int u = q.front();
			q.pop();

			if(u == en) break;

			for(auto it:adj[u]){
				int v = edge[it].v;
				if(edge[it].cap > edge[it].flow && path[v] == -1){
					//cout<<u<<" "<<v<<endl;
					q.push(v);
					path[v] = it;
				}
			}
		}
		//cout<<endl<<endl;

		if(path[en] == -1) return 0;
		int cur = path[en];
		int mi = mod;
		while(1){
			mi = min(mi,edge[cur].cap-edge[cur].flow);
			cur = path[edge[cur].u];
			if(cur == -2) break;
		}
		
		cur = path[en];
		while(1){
			edge[cur].flow += mi;
			edge[cur^1].flow -= mi;
			cur = path[edge[cur].u];
			if(cur == -2) break;
		}
		return mi;
	}

	int Flow(int st,int en){
		int ans = 0;
		while(int temp=bfs(st,en)){
			ans += temp;
		}
		return ans;
	}
};

void solve(){
	int N; cin>>N;
	int st,en,M; cin>>st>>en>>M;
	Dinic D(N);
	for(int i=0; i<M; i++){
		int a,b,c; cin>>a>>b>>c;
		D.add_edge(a,b,c);
		D.add_edge(b,a,c);
	}
	cout<<"Max Flow is: "<<D.Flow(st,en)<<endl;
}


int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}