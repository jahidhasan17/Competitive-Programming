#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int left,int mid,int right)
{
	int size_l=mid-left+1,size_r=right-mid;
	int L[size_l+10],R[size_r+10];

	for(int i=0;i<size_l;i++)
	{
		L[i]=a[left+i];
	}
	for(int i=0;i<size_r;i++)
	{
		R[i]=a[mid+1+i];
	}
	int i=1,k=0,l=0;
	for(i=left;k<size_l&&l<size_r;i++)
	{
		if(L[k]<R[l])
		{
			a[i]=L[k];
			k++;
		}
		else
		{
			a[i]=R[l];
			l++;
		}
	}

	while(k<size_l)
	{
		a[i]=L[k];
		i++;
		k++;
	}
	while(l<size_r)
	{
		a[i]=R[l];
		i++;
		l++;
	}
}

void merge_sort(int a[],int left,int right)
{
	if(left>=right) return;
	int mid=left+(right-left)/2;
	merge_sort(a,left,mid);
	merge_sort(a,mid+1,right);
	merge(a,left,mid,right);
}


int main()
{
	int n;
	cin>>n;
	int a[n+10];
	for(int i=0;i<n;i++) cin>>a[i];
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}