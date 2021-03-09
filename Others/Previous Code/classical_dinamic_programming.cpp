#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[2][100004],n;
int dp[2][100004];
int dp1[2][100004];
int ff(int i,int j,int sum)
{
	if(dp[i][j]) return dp[i][j];
	if(j>=n) return 0;
	int q=(i+1)%2;
	int p1=a[i][j]+ff(q,j+1,a[q][j+1]);
	int p2=a[i][j]+ff(q,j+2,a[q][j+2]);
	dp[i][j]=max(p1,p2);
	return max(p1,p2);
}
int fff(int i,int j,int sum)
{
	if(dp1[i][j]) return dp1[i][j];
	if(j>=n) return 0;
	int q=(i+1)%2;
	int p1=a[i][j]+ff(q,j+1,a[q][j+1]);
	int p2=a[i][j]+ff(q,j+2,a[q][j+2]);
	dp1[i][j]=max(p1,p2);
	return max(p1,p2);
}

main()
{
	scanf("%lld",&n);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	cout<<max(ff(0,0,0),fff(1,0,0))<<endl;
}
/*https://codeforces.com/problemset/problem/1195/C*/