/*
  mississippi

index suffix
0     mississippi
1			ississippi
2			ssissippi
3			sissippi
4			issippi
5			ssippi
6			sippi
7			ippi
8			ppi
9			pi
10		i
*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;

struct node{
	int tup[2],indx;
	bool operator<(const node &seg)const{
		if(tup[0] == seg.tup[0]) return tup[1] < seg.tup[1];
		return tup[0] < seg.tup[0];
	}
}ar[mx];

int Rank[20][mx],step,jump;

void Build_Suffix_Array(string s){
	int N = (int)s.size();
	for(int i=0; i<N; i++){
		Rank[0][i]=s[i]-'a';
		memset(ar[i].tup,0,sizeof(ar[i].tup));
	}
	for(step = 1, jump=1; jump <=  N ; step++,jump<<=1){
		for(int i=0; i<N; i++){
			ar[i].indx=i;
			ar[i].tup[0]=Rank[step-1][i];
			ar[i].tup[1] = ((i + jump)<N)?Rank[step-1][i+jump] : -1;
		}
		sort(ar,ar+N);
		Rank[step][ar[0].indx]=0;
		for(int i=1; i<N; i++){
			if(ar[i].tup[0] == ar[i-1].tup[0] && ar[i].tup[1] == ar[i-1].tup[1]){
				Rank[step][ar[i].indx]=Rank[step][ar[i-1].indx];
			}else Rank[step][ar[i].indx]=i;
		}
	}
}

int Calc_LCP(int x,int y){  //Calculate for longest prefix of index x and index y
	int ans=0;
	for(int i=step-1; i>=0; i--){
		if(Rank[i][x] == Rank[i][y]){
			ans += (1<<i);
			x += (1<<i);
			y += (1<<i);
		}
	}
	return ans;
}

void solve(){
	string s;cin>>s;
	Build_Suffix_Array(s);
	cout<<"Longest prefix of index 1 and 4 : "<<Calc_LCP(1,4)<<endl; 
}
 
main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int tt;tt=1;
  int cas=1;
  while(tt--){
  	//printf("Case %d: ",cas++);
    solve();
  }
}