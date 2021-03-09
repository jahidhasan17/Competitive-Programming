//Uses Rolling Double Hash.
//Hash(abc........z) = a*p^n + b*p^(n-1) + ...... + z


#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define F first
#define S second
#define PLL pair<LL,LL>

ostream& operator<<(ostream& os,PLL hash){
  return os<<"("<<hash.F<<", "<<hash.S<<")";
}

PLL operator+ (PLL a,LL x)  {return {a.F + x, a.S + x};}
PLL operator- (PLL a,LL x)  {return {a.F - x, a.S - x};}
PLL operator* (PLL a,LL x)  {return {a.F * x, a.S * x};}
PLL operator+ (PLL a,PLL x) {return {a.F + x.F,a.S + x.S};}
PLL operator- (PLL a,PLL x) {return {a.F - x.F,a.S - x.S};}
PLL operator* (PLL a,PLL x) {return {a.F * x.F,a.S * x.S};}
PLL operator% (PLL a,PLL x) {return {a.F % x.F,a.S % x.S};}


const PLL M = {1e9+7,1e9+9};
const LL base = 347;
const int Mx = 100005;
string s;

PLL P[Mx];
PLL inv;

PLL power(PLL a, LL p){
  if(p == 0) return {1,1};
  PLL u = power(a,p/2);
  u = (u * u) % M;
  if(p&1) u = (u * a) % M;
  return u;
}

PLL inverse(PLL a){
  return power(a,(M.F-1)*(M.S-1) - 1);
}

void HashPre(){
  P[0] = {1,1};
  for(int i = 1; i<Mx; i++){
    P[i] = (P[i-1] * base) % M;
  }
  inv = inverse(P[1]);
}

//Calculates hash of a string
PLL Hash(string s){
  PLL ans = {0,0};
  for(int i = 0; i<(int)s.size(); i++){
    ans = (ans * base + s[i]) % M;
  }
  return ans;
}

///Calculates hashes of all prefixes of s including empty prefix
vector<PLL> HashList(string s){
  int N = s.size();
  vector<PLL>v(N+1);
  v[0] = {0,0};
  for(int i = 1; i<=N; i++){
    v[i] = (v[i-1] * base + s[i-1]) % M;
  }
  return v;
}

PLL SubStringHash(vector<PLL>hl,int l,int r){
  int len = r - l + 1;
  return ((hl[r] - hl[l-1]*P[len])%M + M ) % M;
}

void solve(){
  HashPre();
}

 
int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}