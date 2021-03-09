/*

greekforgreeks,wikipedia

input
6
1 4
1 5
1 6
2 4
2 5
3 4

output
maximum matching is : 3

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 2005; // N = left node + right node

struct HK
{
  const int INF = (1<<30);
  int match[N],dist[N],L,R;   // L,R no of nodes in left and right side
  vector<int>g[N];
  
  void init(int l,int r){
    L = l,R = r;
    for(int i = 0; i <= L + R + 1; i++){
      g[i].clear();
      match[i] = 0;
    }
  }

  void add_edge(int u,int v){
    g[u].push_back(v); // u = left node numbered from 1 to L and v = right node numbered from L+1 to L+R
  }

  bool bfs(){
    queue<int>q;

    for(int i = 1; i<=L; i++){
      if(!match[i]){
        q.push(i);
        dist[i] = 0;
      }else dist[i] = INF;
    }
    dist[0] = INF;

    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int v : g[u]){
        if(dist[match[v]] == INF){
          dist[match[v]] = dist[u] + 1;
          q.push(match[v]);
        }
      }
    }
    return dist[0] != INF;
  }

  bool dfs(int u){
    if(u){
      for(int v : g[u]){
        if(dist[match[v]] == dist[u] + 1){
          if(dfs(match[v])){
            match[v] = u;
            match[u] = v;
            return 1;
          }
        }
      }
      dist[u] = INF;
      return 0;
    }
    return 1;
  }

  int hopcroft_karp(){
    int matching = 0;
    while(bfs()){
      for(int i = 1; i <= L; i++){
        if(!match[i] && dfs(i)){
          matching++;
        }
      }
    }
    return matching;
  }
}t;


void solve(){
  int n; cin >> n;
  t.init(3,3);
  for(int i = 1; i<=n; i++){
    int u,v; cin >> u >> v;
    t.add_edge(u,v);
  }
  cout << "maximum matching is : " << t.hopcroft_karp() << endl;
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  solve();
}
