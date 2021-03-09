#include <bits/stdc++.h>
using namespace std;

struct node
{
  int val,priority,size;
  int sum,mi,mx,replace_val,lazy;
  bool rev,replace_flag;
  int l,r;
};

node tree[500005];
int ind;

int size(int t){
  if(~t) return tree[t].size;
  return 0;
}

void update_size(int t){
  if(~t) tree[t].size = size(tree[t].l) + 1 + size(tree[t].r);
}

void update_reverse(int t){
  if(t == -1 or !tree[t].rev) return;
  swap(tree[t].l,tree[t].r);
  tree[t].rev = 0;
  if(~tree[t].l) tree[tree[t].l].rev ^= 1;
  if(~tree[t].r) tree[tree[t].r].rev ^= 1;
}

void update_replace(int t){
  if(t == -1 or tree[t].replace_flag == 0) return;
  tree[t].val = tree[t].mx = tree[t].mi = tree[t].replace_val;
  tree[t].sum = tree[t].val * size(t);

  if(~tree[t].l){
    tree[tree[t].l].replace_val = tree[t].replace_val;
    tree[tree[t].l].replace_flag = 1;
  }
  if(~tree[t].r){
    tree[tree[t].r].replace_val = tree[t].replace_val;
    tree[tree[t].r].replace_flag = 1;
  }
  tree[t].replace_flag = 0;
  tree[t].replace_val = 0;
}

void update_lazy(int t){
  if(t == -1 or tree[t].lazy == 0) return;
  tree[t].val += tree[t].lazy;
  tree[t].mx += tree[t].lazy;
  tree[t].mi += tree[t].lazy;
  tree[t].sum += tree[t].lazy * size(t);

  if(~tree[t].l) tree[tree[t].l].lazy += tree[t].lazy;
  if(~tree[t].r) tree[tree[t].r].lazy += tree[t].lazy;
  tree[t].lazy = 0;
}

void combine(int t,int l,int r){
  if(l == -1){
    t = r;
    return;
  }
  if(r == -1){
    t = l;
    return;
  }
  tree[t].sum = tree[l].sum + tree[r].sum;
  tree[t].mx  = max(tree[l].mx , tree[r].mx);
  tree[t].mi  = min(tree[l].mi , tree[r].mi);
}

void reset(int t){
  tree[t].sum = tree[t].val;
  tree[t].mx  = tree[t].val;
  tree[t].mi  = tree[t].val;
}

void operation(int t){
  if(t == -1) return;
  reset(t);
  update_reverse(t);
  update_lazy(t);
  update_lazy(tree[t].l);
  update_lazy(tree[t].r);
  update_replace(t);
  update_replace(tree[t].l);
  update_replace(tree[t].r);
  combine(t,tree[t].l,t);
  combine(t,t,tree[t].r);
}

void split(int t,int &l,int &r,int k,int add = 0){
  if(t == -1){
    l = -1;
    r = -1;
    return;
  }
  operation(t);
  int idx = add + size(tree[t].l) + 1;
  if(idx <= k){
    split(tree[t].r,l,r,k,idx);
    tree[t].r = l;
    l = t;
  }else{
    split(tree[t].l,l,r,k,add);
    tree[t].l = r;
    r = t;
  }
  update_size(t);
  operation(t);
}

int merge(int l,int r){
  if(l == -1) return r;
  if(r == -1) return l;

  operation(l);
  operation(r);

  if(tree[l].priority > tree[r].priority){
    tree[l].r = merge(tree[l].r,r);
    update_size(l);
    operation(l);
    return l;
  }else{
    tree[r].l = merge(l,tree[r].l);
    update_size(r);
    operation(r);
    return r;
  }
}

int create(int val){
  ind++;
  tree[ind].val          = val;
  tree[ind].size         = 1;
  //tree[ind].priority     = pr;
  tree[ind].priority     = rand();
  tree[ind].l            = -1;
  tree[ind].r            = -1;
  tree[ind].sum          = val;
  tree[ind].mx           = val;
  tree[ind].mi           = val;
  tree[ind].rev          = 0;
  tree[ind].replace_val  = 0;
  tree[ind].replace_flag = 0;
  tree[ind].lazy         = 0;
  return ind;
}

void insert(int &root,int pos,int val){
  int l,r;
  int mid = create(val);
  split(root,l,r,pos);
  root = merge(merge(l,mid),r);
}

void dfs(int cur,int par,char c){
  if(cur == -1) return;
  operation(cur);
  cout<<tree[par].val<<" "<<tree[cur].val<<" "<<c<<endl;
  dfs(tree[cur].l,cur,'L');
  dfs(tree[cur].r,cur,'R');
}

int query(int &root,int qL,int qR){
  int l,r,mid;
  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);
  int ans = tree[mid].sum;
  //int ans = tree[mid].mx;
  //int ans = tree[mid].mi;
  /*cout<<"sum --- "<<tree[mid].sum<<endl;
  cout<<"min --- "<<tree[mid].mi<<endl;
  cout<<"max --- "<<tree[mid].mx<<endl;*/
  r    = merge(mid,r);
  root = merge(l,r);
  return ans;
}

void erase(int &root,int qL,int qR){
  int l,r,mid;

  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);

  root = merge(l,r);
}

void reverse(int &root,int qL, int qR){
  int l,r,mid;
  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);
  tree[mid].rev ^= 1;

  r    = merge(mid,r);
  root = merge(l,r);
}

void cyclic_shift(int &root,int qL,int qR,int k,bool left_shift = 1){
  int l,r,mid,ll,rr;
  if(qL == qR) return;

  k %= (qR - qL + 1);

  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);
  if(left_shift) split(mid,ll,rr,(qR - qL + 1) - k);
  else split(mid,ll,rr,k);

  mid  = merge(rr,ll);
  r    = merge(mid,r);
  root = merge(l,r);
}

void replace(int &root,int qL, int qR,int v){
  int l,r,mid;

  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);

  tree[mid].replace_val  = v;
  tree[mid].replace_flag = 1;
  r    = merge(mid,r);
  root = merge(l,r);
}

void add_val(int &root, int qL, int qR, int v){
  int l,r,mid;

  split(root,l,r,qL);
  split(r,mid,r,qR - qL + 1);

  tree[mid].lazy += v;

  r    = merge(mid,r);
  root = merge(l,r);
}

void print_array(int root){
  for(int i = 0; i<size(root); i++) cout<<query(root,i,i)<<" ";
  cout<<endl;
}

int32_t main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
}