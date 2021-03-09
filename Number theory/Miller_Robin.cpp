//Reference :
//https://simantaturja.blogspot.com/2019/05/blog-post.html#more
//https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/

#include <bits/stdc++.h>
using namespace std;
#define u64  uint64_t
#define u128  __uint128_t

u64 modpow(u64 N,u64 x,u64 M){
  if(x == 0) return 1;
  u64 u = modpow(N,x/2,M)%M;
  u = (u128) u * u % M;
  if(x&1) u = (u128) N * u % M;
  return u;
}


bool MillerRobin(u64 N){
  if(N == 1 or N == 4) return 0;
  if(N == 2 or N == 3) return 1;
  u64 DD = N - 1;
  int R = 0;
  while((DD&1) == 0){
    DD >>= 1;
  }
  for(int k = 1; k<=4; k++){
    u64 D = DD;
    u64 A = 2 + rand() % (N-4);
    u64 x = modpow(A,D,N);
    if(x == 1 or x == (N-1)) continue;
    bool bo = 0;
    while(D != (N-1)){
      x = (u128) x * x % N;
      D <<= 1;
      if(x == 1) return 0;
      if(x == (N-1)){
        bo = 1;
        break;
      }
    }
    if(bo == 0) return 0;
  }
  return 1;
}

void solve(){
  if(MillerRobin(77777777777777747)){
    cout<<"Probably Prime"<<endl;
  }else cout<<"Not Prime"<<endl;
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