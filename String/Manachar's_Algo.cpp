//Resources : Almost same as Z algorithm

/*
  INPUT
  abba

  OUTPUT
  # a # b # b # a #
  0 1 0 1 4 1 0 1 0
*/

#include <bits/stdc++.h>
using namespace std;

string find_manachar_string(string s){
  string ss="#";
  for(int i=0; i<(int)s.size(); i++){
    ss += s[i];
    ss += '#';
  }
  return ss;
}

const int mx=100005;

int fail[mx];

void manachar(string s){
  int N = (int)s.size();
  int left=0,right=-1;
  for(int i=0; i<N; i++){
    int k;
    if(i<=right){
      k = min(fail[left+right-i],right-i);
    }else{
      k=1;
    }
    while((i-k)>=0 && (i+k)<N && s[i-k] == s[i+k]){
      k++;
    }
    if(s[i-k]!=s[i+k] or (i-k)<0 or (i+k)>=N) k--;
    fail[i] = k;
    if((i+k)>right){
      right = i+k;
      left = i-k;
    }
  }
}

void solve(){
  string s;cin>>s;
  s = find_manachar_string(s);
  manachar(s);
  cout<<s<<endl;
  for(int i=0; i<(int)s.size(); i++){
    cout<<fail[i];
  }
}
 
main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}