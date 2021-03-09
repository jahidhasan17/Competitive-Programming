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

#define pb push_back

const int mx = 505 * 505;

int tree[mx][30];
int cnt[mx];
int fail[mx];
int ind=0;

void insert(string s){
  int N = (int)s.size();
  int cur=0;
  for(int i=0; i<N; i++){
    int val = s[i]-'a';
    if(tree[cur][val] == 0){
      tree[cur][val] = ++ind;
    }
    cur = tree[cur][val];
  }
}

void Build_Aho_Corasick_Fail(){
  queue<int>q;
  for(int i=0; i<26; i++){
    if(tree[0][i]) q.push(tree[0][i]);
  }
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i=0; i<26; i++){
      if(tree[cur][i] == 0) continue;
      q.push(tree[cur][i]);
      int temp_cur = fail[cur];
      while(temp_cur>0 && tree[temp_cur][i] ==0){
        temp_cur = fail[temp_cur];
      }
      fail[tree[cur][i]]=tree[temp_cur][i];
    }
  }
}

void Search(string s){
  int N = (int)s.size();
  int cur=0;
  for(int i=0; i<N; i++){
    int val = s[i]-'a';
    while(cur > 0 && tree[cur][val] == 0){
      cur = fail[cur];
    }
    cur = tree[cur][val];
    int temp_cur = cur;
    while(temp_cur > 0){
      cnt[temp_cur]++;
      temp_cur = fail[temp_cur];
    }
  }
}

int find(string s){
  int N = (int)s.size();
  int cur=0;
  for(int i=0; i<N; i++){
    int val = s[i]-'a';
    cur = tree[cur][val];
  }
  return cnt[cur];
}

void solve(){
  ind=0;
  int n;cin>>n;
  vector<string>v(n+10);
  for(int i=0; i<n; i++){
    cin>>v[i];
    insert(v[i]);
  }

  string s;cin>>s;

  Build_Aho_Corasick_Fail();
  Search(s);

  for(int i=0; i<n; i++){
    cout<<v[i]<<" found : "<<find(v[i])<<" times"<<endl;
  }
}

main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}