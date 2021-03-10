#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MEM(x,val) memset(x,val,sizeof(x))
#define LL long long
#define F first
#define S second
#define PI pair<int,int>
#define PLL pair<LL,LL>
#define ALL(x) x.begin(),x.end()
int II(){int q;scanf("%d",&q);return q;}
LL LII(){LL q;scanf("%lld",&q);return q;}

const int Mx = 200005;
int N;
vector<set<int>>tr(Mx);

// LCA FOR distance

struct LCA{
  int P[22][Mx];
  int L[Mx];

  void dfs(int u,int p,int dep){
    L[u] = dep;
    for(auto v : tr[u]){
      if(v != p){
        P[0][v] = u;
        dfs(v,u,dep+1);
      }
    }
  }

  void lca_init(){
    for(int k = 1; (1<<k) < N; k++){
      for(int i = 1; i<=N; i++){
        if(P[k-1][i] != -1){
          P[k][i] = P[k-1][P[k-1][i]];
        }
      }
    }
  }

  void preprocess(){
    MEM(P,-1);
    dfs(1,-1,0);
    lca_init();
  }

  int lca(int p,int q){
    if(p == q) return p;
    if(L[p] < L[q]) swap(p,q);
    int d = L[p] - L[q];

    for(int i = 0; i<22; i++){
      if((d&(1<<i))){
        p = P[i][p];
      }
    }

    if(p == q) return p;

    for(int i = 21; i>=0; i--){
      if(P[i][p] != -1 && P[i][p] != P[i][q]){
        p = P[i][p], q = P[i][q];
      }
    }
    return P[0][p];
  }

  int dist(int p,int q){
    return L[p] + L[q] - (2*L[lca(p,q)]);
  }

}a;

// Centroid Decomposition

struct CentroidDecomposition{
  
  int dad[Mx],sub[Mx];

  void build(int u,int p){
    int n = dfs(u,p);
    int centroid = dfs(u,p,n);
    if(p == -1) p = centroid;
    dad[centroid] = p;

    for(auto v : tr[centroid]){
      tr[v].erase(centroid);
      build(v,centroid);
      tr[v].insert(centroid);
    }
  }

  int dfs(int u,int p){
    sub[u] = 1;
    for(auto v : tr[u]){
      if(v != p){
        sub[u] += dfs(v,u);
      }
    }
    return sub[u];
  }

  int dfs(int u,int p,int n){
    for(int v : tr[u]){
      if(v != p && sub[v] > n/2) return dfs(v,u,n);
    }
    return u;
  }

}t;

int ans[Mx];

void update(int u){
  int x = u;
  while(1){
    ans[x] = min(ans[x],a.dist(x,u));
    if(x == t.dad[x]) break;
    x = t.dad[x];
  }
}

int query(int u){
  int x = u;
  int ret = Mx;
  while(1){
    ret = min(ret, a.dist(u,x) + ans[x]);
    if(x == t.dad[x]) break;
    x = t.dad[x];
  }
  return ret;
}

void solve(){
  int q; scanf("%d %d",&N,&q);
  for(int i = 1; i<=N; i++) ans[i] = N+N;
  for(int i = 1; i<N; i++){
    int a,b; scanf("%d %d",&a,&b);
    tr[a].insert(b);
    tr[b].insert(a);
  }
  t.build(1,-1);
  a.preprocess();
  update(1);
  while(q--){
    int ty,u; scanf("%d %d",&ty,&u);
    if(ty == 1) update(u);
    else printf("%d\n",query(u));
  }
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tt; tt = 1;
  int cas = 1;
  while(tt--){
    //printf("Case %d:\n",cas++);
    solve();
  }
}