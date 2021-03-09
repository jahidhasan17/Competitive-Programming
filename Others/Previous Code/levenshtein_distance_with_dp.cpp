#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s1[1000],s2[1000];
	scanf("%s %s",s1,s2);
	int l1=strlen(s1),l2=strlen(s2);
	int dp[1000][1000];
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0)
			{
				dp[i][j]=j;
			}
			else if(j==0)
			{
				dp[i][j]=i;
			}
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
			}
		}
	}
	cout<<dp[l1][l2]<<endl;
}