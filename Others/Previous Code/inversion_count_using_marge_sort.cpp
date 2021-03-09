#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,re=0;
void marge(int l,int mid,int r)
{
	int b_l=mid-l+1,c_l=r-mid;
	int b[b_l],c[c_l];
	for(int i=l;i<=mid;i++) b[i-l]=a[i];
	for(int i=mid+1;i<=r;i++) c[i-mid-1]=a[i];
	int i=0,j=0,k=l;
	while(i<b_l&&j<c_l)
	{
		if(b[i]>c[j])
		{
			a[k++]=b[i++];
			re+=c_l-j;
		}
		else
		{
			a[k++]=c[j++];
		}
	}
	while(i<b_l) a[k++]=b[i++];
	while(j<c_l) a[k++]=c[j++];
}
void marge_sort(int l,int r)
{
	if(l>=r) return;
	int mid=l+(r-l)/2;
	marge_sort(l,mid);
	marge_sort(mid+1,r);
	marge(l,mid,r);
}

main()
{
	int t;scanf("%lld",&t);
	while(t--){
	scanf("%lld",&n);
	re=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	marge_sort(1,n);
	cout<<re<<endl;
	}
}