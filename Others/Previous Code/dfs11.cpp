#include<bits/stdc++.h>
using namespace std;

vector<int> arr[100010];
bool visit[100010];

void dfs(int u)
{
    cout<<u<<endl;
    visit[u]=1;
    for(int i=0;i<arr[u].size();i++)
    {
        if(!visit[arr[u][i]])
        {
            dfs(arr[u][i]);
        }
    }
}

int main()
{
    int e,u,v;
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
        visit[u]=1;
        visit[v]=1;
    }
    for(int i=0;i<100010;i++)visit[i]=0;
    
    	dfs(1);
    
}
/*
7
6 0
0 2
4 2
5 2
1 4
1 5
6 5
*/
