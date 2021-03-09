#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MEM(x,val) memset(x,val,sizeof(x))
#define LL long long

/*

segtree - add on segment, minimum or maximum on segment

*/


#define int LL

const int Mx = 2e5 + 100;
const int Inf = 1e18;

struct info
{
  int mi;
};

info tr[Mx * 4];
int lz[Mx * 4];


void propagate(int node,int b,int e){
  if(b != e){
    lz[node*2] += lz[node];
    lz[node*2+1] += lz[node];
  }
  tr[node].mi += lz[node];
  lz[node] = 0;
}

info combine(info &a,info &b){
  // merge
}

void build(int node,int b,int e){
  if(b == e){
    tr[node] = {}
  }else{
    int mid = (b + e)/2;
    build(node*2,b,mid);
    build(node*2+1,mid+1,e);
    tr[node] = combine(tr[node*2],tr[node*2+1]);
  }
}

void update(int node,int b,int e,int l,int r,int val){
  propagate(node,b,e);
  if(l > e or r < b) return;
  if(b >= l and e <= r){
    lz[node] += val;
    propagate(node,b,e);
    return;
  }else{
    int mid = (b + e)/2;
    update(node*2,b,mid,l,r,val);
    update(node*2+1,mid+1,e,l,r,val);
    tr[node] = combine(tr[node*2],tr[node*2+1]);
  }
}

info qu(int node,int b,int e,int l,int r){
  propagate(node,b,e);
  if(l > e or r < b){
    return {Inf};
  }
  if(b >= l and e <= r) return tr[node];
  else{
    int mid = (b + e)/2;
    info a = qu(node*2,b,mid,l,r);
    info b = qu(node*2+1,mid+1,e,l,r);
    return combine(a,b);
  }
}


void solve(){
  
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int tt; tt = 1;
  int cas = 1;
  while(tt--){
    //printf("Case %lld: ",cas++);
    solve();
  }
}
