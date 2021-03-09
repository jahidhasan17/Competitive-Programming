/*

Reference : cp_algorithm

INPUT
4 5
1 2 20
1 3 10
1 4 10
2 4 50
3 4 20

OUTPUT
Flow and Cost is: 3 110

*/


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define mod 1e9
#define F first
#define S second


struct Flowedge
{
  int u,v,cap,cost,flow=0;
};

struct MCMF
{
  vector<Flowedge>edge;
  vector<vector<int>>adj;
  int N,M = 0;
  MCMF(){}
  MCMF(int _N){
    N = _N+10;
    adj.resize(N+10);
    M = 0;
  }
  void add_edge(int u,int v,int cap,int cost){
    edge.push_back({u,v,cap,cost});
    edge.push_back({v,u,0,-cost});
    adj[u].push_back(M);
    adj[v].push_back(M+1);
    M += 2;
  }


  pii Bellmen_Ford(int st,int en){
    int L = en + 10;
    int dist[L + 10];
    int path[L + 10],vis[L + 10];

    for(int i = 0; i<L; i++){
      dist[i] = 1e9;
      path[i] = -1;
      vis[i] = 0;
    }
    dist[st] = 0;
    queue<int>q;
    q.push(st);
    vis[st] = 1;

    while(!q.empty()){
      int u = q.front();
      q.pop();
      vis[u] = 0;

      for(auto it : adj[u]){
        int v = edge[it].v;
        int new_cost = dist[u] + edge[it].cost;

        if(new_cost < dist[v] && edge[it].cap > edge[it].flow){
          dist[v] = new_cost;
          path[v] = it;

          if(vis[v] == 0){
            vis[v] = 1;
            q.push(v);
          }
        }
      }
    }


    if(path[en] == -1) return {-1,-1};


    int cur = path[en];
    int mi = 1e9;
    while(1){
      mi = min(edge[cur].cap-edge[cur].flow,mi);
      cur = path[edge[cur].u];
      if(cur == -1) break;
    }

    cur = path[en];
    int cost = 0;
    while(1){
      edge[cur].flow += mi;
      edge[cur^1].flow -= mi;
      cost += (mi * edge[cur].cost);
      cur = path[edge[cur].u];
      if(cur == -1) break;
    }
    return {mi,cost};
  }


  pii Flow(int st,int en){
    int K = 0;
    int cost = 0;
    while(1){
      pii it = Bellmen_Ford(st,en);
      if(it.F == -1) break;
      K += it.F;
      cost += it.S;
    }
    return {K,cost};
  }
};


void solve(){
  int N,M; cin>>N>>M;
  MCMF D(N+10);
  for(int i=0; i<M; i++){
    int a,b,c,d; cin>>a>>b>>c>>d;
    D.add_edge(a,b,c,d);
    D.add_edge(b,a,c,d);
  }
  pii it = D.Flow(1,N);
  cout<<"Flow and Cost is: "<<it.F<<" "<<it.S<<endl;
}

int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}
