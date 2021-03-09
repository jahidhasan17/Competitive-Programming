//Reference: mahbubul hasan book,cp_algorithm site,greeks for greeks
/*INPUT

6 9
1 0 5
0 2 12
1 2 5
1 3 8
2 3 9
2 4 4
3 4 3
3 5 7
5 4 9

OUTPUT
14
*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back


struct FlowEdge
{
    int u,v;
    long long cap,flow=0;
    FlowEdge() {}
    FlowEdge(int _u,int _v,long long _cap){
        u = _u;
        v = _v;
        cap = _cap;
    }
};

struct Dinic
{
    const long long flow_inf = 1e18;
    int N,M=0;
    vector<vector<int>>adj;
    vector<FlowEdge> edge;
    vector<int>level,Done;
    Dinic() {}
    Dinic(int _N){
        N = _N+10;
        level.resize(N);
        Done.resize(N);
        adj.resize(N);
    }

    void add_edge(int u,int v,long long cap){
        edge.pb({u,v,cap});
        edge.pb({v,u,0});
        adj[u].pb(M);
        adj[v].pb(M+1);
        M += 2;
    }

    bool bfs(int st,int en){
        queue<int>q;
        q.push(st);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int id : adj[u]){
                int v = edge[id].v;
                if((edge[id].cap-edge[id].flow)<1) continue;
                if(level[v] != -1) continue;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
        return level[en]!=-1;
    }

    long long dfs(int u,int en,long long flow){
        if(flow == 0) return 0;
        if(u == en) return flow;
        for(int &i = Done[u]; i<adj[u].size(); i++){
            int id = adj[u][i];
            int v = edge[id].v;
            if(level[v] == level[u]+1){
                if((edge[id].cap - edge[id].flow)>0){
                    long long temp = dfs(v,en,min(flow,edge[id].cap - edge[id].flow));
                    if(temp == 0) continue;
                    edge[id].cap -= temp;
                    edge[id^1].flow += temp;
                    return temp;
                }
            }
        }
        return 0;
    }

    long long Flow(int st,int en){
        long long Ans = 0;
        while(true){
            fill(level.begin(),level.end(),-1);
            level[st] = 0;
            if(!bfs(st,en)) break;
            fill(Done.begin(),Done.end(),0);
            while(long long temp = dfs(st,en,flow_inf)){
                Ans += temp;
            }
        }
        return Ans;
    }
};

void solve(){
    int N,M; cin>>N>>M;
    Dinic D(100);
    for(int i=0; i<M; i++){
        int u,v;long long cap; cin>>u>>v>>cap;
        D.add_edge(u,v,cap);
        D.add_edge(v,u,cap);
    }
    cout<<D.Flow(0,5)<<endl;
}

int32_t main(){
  #ifndef ONLINE_JUDGE 
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}
