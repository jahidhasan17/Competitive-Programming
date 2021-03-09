#include <bits/stdc++.h>
using namespace std;

#define left node*2
#define right (node*2)+1
#define mid (b+e)/2
int a[100],tree[100*4],lz[100*4];
int n;

void init(int node,int b,int e){
	if(b==e){
		tree[node]=a[b];
		return;
	}
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int i,int j,int val){
	if(j<b||i>e) return;
	if(b>=i&&e<=j){
		lz[node]+=val;
		tree[node]+=(e-b+1)*val;
		return;
	}
	update(left,b,mid,i,j,val);
	update(right,mid+1,e,i,j,val);
	tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j,int carry){
	if(i>e||j<b) return 0;
	if(b>=i&&e<=j){
		return tree[node]+(carry*(e-b+1));
	}
	carry+=lz[node];
	return query(left,b,mid,i,j,carry)+query(right,mid+1,e,i,j,carry);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	init(1,1,n);
	update(1,1,n,1,5,2);
	cout<<query(1,1,n,1,5,0)<<endl;
	/*for(int i=1;i<=20;i++){
		cout<<lz[i]<<endl;
	}*/
}