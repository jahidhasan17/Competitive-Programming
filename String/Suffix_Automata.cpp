#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

const int Mx = 1e5+10;
int cnt[Mx * 2];

struct suffixautomaton{
  
  int sz,last;

  struct state{
    int len,link;
    map<char,int>next;
    int cnt1; // for number of occurrence of a state in string
    int cnt2; // for number of path from a this state (not only distict)
  }st[Mx*2];

  void init(){
    for(int i = 0; i<Mx*2; i++){
      st[i].next.clear();
    }
    st[0].len = 0;
    st[0].link = -1;
    sz = 0;
    last = 0;
  }

  void build(string &s){
    init();
    for(int i = 0; i<(int)s.size(); i++) sa_extend(s[i]);
    vis.resize(sz + 1);
    dfs(0);
  }
  vector<int>vis;

  void dfs(int cur){
    vis[cur] = 1;
    for(auto v : st[cur].next){
      if(vis[v.S] == 0) dfs(v.S);
      if(v.F == '#') st[cur].cnt1++;
      else st[cur].cnt1 += st[v.S].cnt1;
      st[cur].cnt2 += st[v.S].cnt2;
    }
    st[cur].cnt2 += st[cur].cnt1;
  }

  void sa_extend(char c){
    int cur = ++sz;
    cnt[cur] = 1;
    st[cur].len = st[last].len + 1;
    int p = last;
    while(p != -1 && !st[p].next.count(c)){
      st[p].next[c] = cur;
      p = st[p].link;
    }

    if(p == -1){
      st[cur].link = 0;
    }else{
      int q = st[p].next[c];

      if(st[p].len + 1 == st[q].len){
        st[cur].link = q;
      }else{
        int clone = ++sz;
        st[clone].len = st[p].len + 1;
        st[clone].next = st[q].next;
        st[clone].link = st[q].link;

        while(p != -1 && st[p].next[c] == q){
          st[p].next[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
}t;


void solve(){
  string s = "abcbc#"; // must be add '#' char
  t.build(s);

  string ss = "bc";
  // find the number of occurence
  int cur = 0;
  for(int i = 0; i<(int)ss.size(); i++){
    if(t.st[cur].next[ss[i]]){
      cur = t.st[cur].next[ss[i]];
    }else{
      cout << 0 << endl;
      return;
    }
  }
  cout << t.st[cur].cnt1 << endl;
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tt; tt = 1;
  int cas = 1;
  while(tt--){
    //printf("Case %d: ",cas++);
    solve();
  }
}
