```
Input
1
4 4
2 1
1 4
3 4
2 3
```

```c++
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define pii pair<int,int>


int II(){int q;scanf("%d",&q);return q;}
 
int n,m;
vector<int>v[100005];
int vis[100005]; //For first dfs
int vis1[100005]; //For second dfs
int ti=0; //For time count
int f[100005]; //For finishing time of every node

//find sorted order for minimum conneted component
void dfs(int u){
    if(vis[u]==1) return;
    vis[u]=1;
    ti++;
    for(auto it:v[u]){
        if(vis[it]==0){
            dfs(it);
        }
    }
    f[u]=++ti; //whose has no indegree or whose has minimum time
}
 
//visit or color each component 
void dfs1(int u){
    if(vis1[u]) return;
    vis1[u]=1;
    for(auto it:v[u]){
        if(vis1[it]==0){
            dfs1(it);
        }
    }
}
 
void solve(){
    n=II(),m=II();
    for(int i=0; i<=n; i++){
        vis[i]=vis1[i]=0;
        v[i].clear();
    }
    for(int i=0; i<m; i++){
        int u,vv;u=II(),vv=II();
        v[u].pb(vv);
    }
    ti=0;
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    vector<pii>pa;
    for(int i=1; i<=n; i++){
        //cout<<f[i]<<endl;
        pa.pb({f[i],i});
    }
    sort(pa.rbegin(),pa.rend());
    int re=0;
    for(auto it:pa){
        //cout<<it.S<<endl;
        if(vis1[it.S]==0){
            re++;
            dfs1(it.S);
        }
    }
    printf("%d\n",re);
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int tt;tt=II();
    int cas=1;

    while(tt--){
        printf("Case %d: ",cas++);
        solve();
    }
}
```