#include <bits/stdc++.h>
using namespace std;

bool Check(int N,int pos) {return (bool)(N&(1<<pos));}
int Set(int N,int pos) {return (N|=(1<<pos));}
int reset(int N,int pos) {return N&=~(1<<pos);}

int dp[1<<15];
int n;
int a[16][16];

int main()
{
	cin>>n;
	for(int i=0;i<(1<<n);i++) dp[i]=1000;
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(Check(i,j)==0)
			{
				int q=a[j][j]+dp[i];
				for(int k=0;k<n;k++)
				{
					if(k!=j && Check(i,k)==1) q+=a[k][j];
				}
				dp[i|(1<<j)]=min(dp[i|(1<<j)],q);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}