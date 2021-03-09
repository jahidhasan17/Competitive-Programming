//https://codeforces.com/problemset/problem/1284/D

/*

B = base //should be prime

Let a set of integers S = {a,b,c,....z}
Hash value of set S = B^a + B^b + B^c+...+B^z

*/

/*

INPUT
6
1 5 2 9
2 4 5 8
3 6 7 11
7 10 12 16
8 11 13 17
9 12 14 18

OUTPUT
YES

INPUT

3
1 3 2 4
4 5 6 7
3 4 5 5

OUTPUT
NO

*/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define MEM(x,val) memset(x,val,sizeof(x))
#define LL long long
#define F first
#define S second
#define PI pair<int,int>
#define PLL pair<LL,LL>
#define ALL(x) x.begin(),x.end()
int II(){int q;scanf("%d",&q);return q;}
LL LII(){LL q;scanf("%lld",&q);return q;}

const int M1 = 1e9+7,M2 = 1e9+9,B1 = 19999909,B2 = 19999897;
const int N = 100006;

LL P1[N],P2[N];

void pre(){
	P1[0] = P2[0] = 1;
	for(int i = 1; i<N; i++){
		P1[i] = (P1[i-1] * B1) % M1;
		P2[i] = (P2[i-1] * B2) % M2;
	}
}

vector<int>st[N*2],en[N*2];
LL h1 = 0,h2 = 0;

void reset(){
	h1 = 0,h2 = 0;
}

void add(int x){
	h1 = (h1 + P1[x]) % M1;
	h2 = (h2 + P2[x]) % M2;
}

vector<PLL>find(vector<PLL>&v){

	//compress
	map<LL,int>mp;
	int M = v.size();
	for(auto it:v){
		mp[it.F] = 0;
		mp[it.S] = 0;
	}
	int in = 0;
	for(auto &it : mp) it.S = ++in;
	for(auto &it:v){
		it.F = mp[it.F];
		it.S = mp[it.S];
	}
	for(int i = 1; i<2*N; i++){
		st[i].clear();
		en[i].clear();
	}
	for(int i = 0; i<M; i++){
		st[v[i].F].pb(i);
		en[v[i].S].pb(i);
	}
	reset();
	vector<PLL>ans(M);
	for(int i = 1; i<2*N; i++){
		for(auto it:st[i]){
			ans[it].F = (ans[it].F + h1) % M1;
			ans[it].S = (ans[it].S + h2) % M2;
		}
		for(auto it:en[i]){
			add(it);
		}
	}
	reset();
	for(int i = 2*N - 1; i>=1; i--){
		for(auto it:en[i]){
			ans[it].F = (ans[it].F + h1) % M1;
			ans[it].S = (ans[it].S + h2) % M2;
		}
		for(auto it:st[i]){
			add(it);
		}
	}
	return ans;
}

void solve(){
	pre();
	int N; cin>>N;
	vector<PLL>v1(N),v2(N);
	for(int i = 0; i<N; i++){
		cin>>v1[i].F>>v1[i].S>>v2[i].F>>v2[i].S;
	}
	vector<PLL>ans1 = find(v1);
	vector<PLL>ans2 = find(v2);
	if(ans1 == ans2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}


 
int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}