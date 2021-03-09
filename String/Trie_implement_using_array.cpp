#include <bits/stdc++.h>
using namespace std;


int tree[10000][27];
int ind=0; // node number

void insert(string s){
	int cur=0;
	for(int i=0; i<(int)s.size(); i++){
		int id=s[i]-'a';
		if(tree[cur][id]==-1){ // if letter not found
			tree[cur][id]=++ind; // create new node by ++ind
			memset(tree[ind],-1,sizeof(tree[ind])-1); // all 26 node of new node declear as khali using -1
		}
		cur=tree[cur][id];
	}
	tree[cur][26]=-2; // endmark of word by special number (-2)
}

bool check(string s){
	int cur=0;
	for(int i=0; i<(int)s.size(); i++){
		int id=s[i]-'a';
		if(tree[cur][id]==-1) return 0; // if dectionary has no word since (1-i)
		cur=tree[cur][id];
	}
	return (tree[cur][26] == -2);
}

void solve(){
	int n;cin>>n;
	memset(tree[0],-1,sizeof(tree[0]));
	while(n--){
		string s;cin>>s;
		insert(s);
	}
	cout<<check("jahidd")<<endl;
}
 
main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}