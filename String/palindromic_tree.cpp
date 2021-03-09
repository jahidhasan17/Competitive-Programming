//reference : https://rezwanarefin01.github.io/posts/palindromic-tree-01/


#include <bits/stdc++.h>
using namespace std;


const int N = 100005;

struct palindromic_tree
{
  int tr[N][26],idx;
  int len[N],link[N],t,indx[N];

  void init(){
  	memset(tr,0,sizeof(tr));
    len[1] = -1,link[1] = 1;
    len[2] = 0, link[2] = 1;
    idx = t = 2;
  }

  void extend(string &s,int p){
    while(s[p - len[t] - 1] != s[p]) t = link[t];
    int x = link[t],c = s[p] - 'a';
    while(s[p - len[x] - 1] != s[p]) x = link[x];
    if(!tr[t][c]){
      tr[t][c] = ++idx;
      len[idx] = len[t] + 2;
      indx[idx] = p - len[idx] + 1;
      link[idx] = len[idx] == 1 ? 2 : tr[x][c];
    }
    t = tr[t][c];
  }


  void build(string &s){
    s = '~' + s;
    for(int i = 1; i<(int)s.size(); i++){
      extend(s,i);
    }
  }
}a;

void dfs(string s,int in){
  for(int i = 0; i<26; i++){
    if(a.tr[in][i]){
      int cur = a.tr[in][i];
      cout << s.substr(a.indx[cur],a.len[cur]) << endl;
      dfs(s,a.tr[in][i]);
    }
  }
}

void solve(){
	a.init();
  string s = "xyxyxabba";
  a.build(s);

  cout << "distinct odd palindrome : " << endl;
  dfs(s,1);
  cout << endl;
  cout << "distinct even palindrome : " << endl;
  dfs(s,2);
}


int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tt; tt = 1;
  int cas = 1;
  while(tt--){
    //printf("Case %d:\n",cas++);
    solve();
  }
}
