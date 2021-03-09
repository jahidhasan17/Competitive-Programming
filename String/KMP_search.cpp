/*
INPUT
aaaaaaa
aaaaa

OUTPUT
Text is found : 0
Text is found : 1
Text is found : 2

*/
#include <bits/stdc++.h>
using namespace std;

string s,t;
int lps[100005];

void LPS(string t){
	int i=1;
	int len=0;
	while(i < (int)t.size()){
		if(t[i] == t[len]){
			lps[i]=++len;
			i++;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMP(string s,string t){
	int N=(int)s.size(),M=(int)t.size();
	int i=0,j=0;
	while(i<N){
		if(s[i] == t[j]){
			i++,j++;
			if(j == M){
				cout<<"Text is found : "<<i-j<<endl;
				j=lps[j-1];
			}
		}else{
			if(j!=0) j=lps[j-1];
			else i++;
		}
	}
}

void solve(){
	cin>>s>>t;
	LPS(t);
	KMP(s,t);
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}