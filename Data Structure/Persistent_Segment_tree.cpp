/*

problem - SPOJ-PSEGTREE

*/

#include <bits/stdc++.h>
using namespace std;

const int Mx = 1e5 + 10;
int N;
int ar[Mx];

struct persistent
{
  struct node
  {
    int val;
    node *left,*right;
    node(){
      val = 0;
      left = right = nullptr;
    }
  };

  node *root[Mx];

  int Size(node *cur){
    if(cur) return cur->val;
    return 0;
  }

  node *update(node *u,int b,int e,int in,int val){
    node *cur = new node();
    if(u) *cur = *u;

    if(b == e){
      cur->val += val;
      return cur;
    }else{
      int mid = (b + e)/2;
      if(in <= mid){
        cur->left = update(cur->left,b,mid,in,val);
      }else{
        cur->right = update(cur->right,mid+1,e,in,val);
      }
      cur->val = Size(cur->left) + Size(cur->right);
      return cur;
    }
  }

  void update(int prev,int ver,int in,int val){
    root[ver] = update(root[prev],1,Mx-1,in,val);
  }
  int query(node *cur,int b,int e,int l,int r){
    if(!cur) return 0;
    if(l>e or r<b) return 0;
    if(b>=l and e <= r) return cur->val;
    else{
      int mid = (b + e)/2;
      return query(cur->left,b,mid,l,r) + query(cur->right,mid+1,e,l,r);
    }
  }
  int query(int ver,int l,int r){
    return query(root[ver],1,Mx-1,l,r);
  }
}t;

void solve(){
  t.root[0] = nullptr;
  scanf("%d",&N);
  for(int i = 1; i<=N; i++){
    scanf("%d",&ar[i]);
    t.update(0,0,i,ar[i]);
  }
  int qq; scanf("%d",&qq);
  int cnt = 0;
  while(qq--){
    int type,k,l,r; scanf("%d %d %d %d",&type,&k,&l,&r);
    if(type == 1){
      t.update(k,++cnt,l,r);
    }else{
      int val = t.query(k,l,r);
      printf("%d\n",val);
    }
  }
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}
