//Resources : Programming contest book/mahbobul hasan
/*
INPUT
abababababa

OUTPUT
11 0 9 0 7 0 5 0 3 0 1
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

int Z[mx + 10];

void Z_function(string s){

  int N = (int)s.size();
  for(int i=0; i<N; i++) Z[i]=0;
  Z[0] = N;

  for(int i=1,left=0,right=0; i<N; i++){
    if(i<=right){
      Z[i] = min(Z[i-left],right - i + 1);
    }
    while((i+Z[i])<N && s[i+Z[i]] == s[Z[i]]) Z[i]++;

    if((i+Z[i])>right){
      left = i,right = i+Z[i]-1;
    }
  }
}

void solve(){
  string s;
  cin>>s;
  Z_function(s);
  for(int i=0; i<(int)s.size(); i++){
    cout<<Z[i]<<" ";
  }
}

main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}