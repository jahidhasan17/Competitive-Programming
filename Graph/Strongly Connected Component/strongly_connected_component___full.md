```
Input
11
0 2
2 1
1 0
3 5
5 4
4 3
6 8
8 7
7 6
2 3
3 6

Output
Total SCC : 3
1--: 0 1 2 
2--: 3 4 5 
3--: 6 7 8 
```

```c++
#include <bits/stdc++.h>
using namespace std;

#define pb push_back


vector<int>v[1005]; 
vector<int>rev_v[1005]; //for reverse direction
vector<int>component[10005]; // for all separated component
int vis[1005];
stack<int>st; // for order


// dfs for find order
void dfs1(int u){
  vis[u]=1;
  for(auto it:v[u]){
    if(vis[it]==0) dfs1(it);
  }
  st.push(u);
}

//dfs for find all SCC 
void dfs(int u,int mark){
  vis[u]=mark;
  component[mark].pb(u);
  for(auto it:rev_v[u]){
    if(vis[it]==0) dfs(it,mark);
  }
}

void solve(){
  int n;cin>>n;
  for(int i=0; i<n; i++){
    int u,vv;cin>>u>>vv;
    v[u].pb(vv);
    rev_v[vv].pb(u);
  }

  dfs1(0);
  for(int i=0; i<=1000; i++) vis[i]=0;

  int mark=1;
  while(!st.empty()){
    if(vis[st.top()]==0) dfs(st.top(),mark++);
    st.pop();
  }
  cout<<"Total SCC : "<<mark-1<<endl;
  for(int i=1; i<mark; i++){
    cout<<i<<"--: ";
    for(auto it:component[i]){
      cout<<it<<" ";
    }
    cout<<endl;
  }
}

main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}
```