//TIME COM:2^n
#include <bits/stdc++.h>
using namespace std;

int n,rod;
int a[100],b[200],dp[1000];


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		dp[a[i]]=b[i];
	}
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=i/2;j++)
		{
			dp[i]=max(dp[i],dp[j]+dp[i-j]);
		}
		cout<<dp[i]<<endl;
	}
}