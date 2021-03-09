#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MEM(x,val) memset(x,val,sizeof(x))

const int Mx = 10005;

int N;
vector<int>v[Mx],cost[Mx],Ind[Mx];
int tr[Mx * 4];

struct HLD{
  int sub[Mx],chainInd[Mx],chainHead[Mx],baseAr[Mx],posInBase[Mx];
  int chainNo,ptr;

  void init(){
    chainNo = 1,ptr = 1;
    for(int i = 1; i<Mx; i++){
      sub[i] = 0;
      chainInd[i] = 0;
      chainHead[i] = -1;
      baseAr[i] = 0;
      posInBase[i] = 0;
    }
    dfs(1,-1);
  }
  int dfs(int u,int p){
    sub[u] = 1;
    for(auto it : v[u]){
      if(it != p){
        sub[u] += dfs(it,u);
      }
    }
    return sub[u];
  }

  void hld(int u,int p,int c_cost){
    if(chainHead[chainNo] == -1){
      chainHead[chainNo] = u;
    }
    chainInd[u] = chainNo;
    baseAr[ptr] = c_cost;
    posInBase[u] = ptr;
    ptr++;

    int ncost = -1,ind = -1,cost_t;
    for(int i = 0; i<v[u].size(); i++){
      int it = v[u][i],cc = cost[u][i];
      if(sub[it] > ncost && it != p){
        ncost = sub[it];
        ind = it;
        cost_t = cc;
      }
    }

    if(ind != -1){
      hld(ind,u,cost_t);
    }

    for(int i = 0; i<v[u].size(); i++){
      int it = v[u][i], cc = cost[u][i],iii = Ind[u][i];
      if(it != p){
        if(it != ind){
          chainNo++;
          hld(it,u,cc);
        }
      }
    }
  }
}t;


void solve(){
  
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}
