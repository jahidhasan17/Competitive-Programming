//reference : https://returnzerooo.wordpress.com/2017/09/28/%E0%A6%86%E0%A6%B9%E0%A7%8B-%E0%A6%95%E0%A7%8B%E0%A6%B0%E0%A6%BE%E0%A6%B8%E0%A6%BF%E0%A6%95/

/*
INPUT
5
aba
ba
ac
a
abc

ababacbabc

OUTPUT

aba found : 2 times
ba found : 3 times
ac found : 1 times
a found : 4 times
abc found : 1 times
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 9;
int cnt[N];
 
struct aho_corasick{
  bool is_end[N];
  int link[N]; // link to the longest proper suffix
  int out_link[N]; // link to the longest proper suffix which is appered in patterns
  int sz;
  map<char,int>to[N],dp[N];
 
  void clear(){
    for(int i = 0; i<sz; i++){
      is_end[i] = 0,link[i] = 0,to[i].clear(),dp[i].clear();
      sz = 0;
      is_end[0] = 1;
    }
  }
  aho_corasick(){
    sz = N-2;
    clear();
  }
 
  void add_word(string &s){
    int u = 0;
    for(char c : s){
      if(!to[u].count(c)) to[u][c] = ++sz;
      u = to[u][c];
    }
    is_end[u] = 1;
  }
 
  void push_links(){
    queue<int>q;
    int u,v,j;
    char c;
    q.push(0);
    link[0] = -1;
    while(!q.empty()){
      u = q.front();
      q.pop();
      for(auto it : to[u]){
        v = it.second;
        c = it.first;
        j = link[u];
 
        while(j!=-1 && !to[j].count(c)) j = link[j];
        if(j != -1) link[v] = to[j][c];
        else link[v] = 0;
        out_link[v] = (is_end[link[v]] ? link[v] : out_link[link[v]]);
 
        q.push(v);
      }
    }
  }
 
  // go to the state if we add the character ch
  int go(int v,char ch){
    if(!dp[v].count(ch)){
      if(to[v].count(ch)) return dp[v][ch] = to[v][ch];
      return dp[v][ch] = (v == 0 ? 0 : go(link[v],ch));
    }
    return dp[v][ch];
  }
}aho;


void dfs(int u,char c){
  cout << u << " " << c << " " << cnt[u] << endl;
  for(auto it : aho.to[u]){
    dfs(it.second,it.first);
  }
}
 

void solve(){
  int n; cin >> n;
  for(int i = 0; i<n; i++){
    string s; cin >> s;
    aho.add_word(s);
  }
  aho.push_links();

  string text; cin >> text;

  int cur = 0;
  for(char ch : text){
    cur = aho.go(cur,ch);
    int temp = cur;
    while(temp > 0){
      cnt[temp]++;
      temp = aho.out_link[temp];
    }
  }
  dfs(0,'.');
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}