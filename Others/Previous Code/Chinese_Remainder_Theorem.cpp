#include <bits/stdc++.h>
using namespace std;
#define ll int
#define sc(n) scanf("%d",&n)
#define pr(n) printf("%d\n",n)
#define pii pair<int,int>
#define x first
#define y second

pii f(int a,int b)
{
	if(b==0) return pii(1,0);
	else
	{
		pii d=f(b,a%b);
		return pii(d.y,d.x-d.y*(a/b));
	}
}

int modularInverse(int a,int n)
{
	pii res=f(a,n);
	return (((res.x%n)+n)%n);
}




int main()
{
	int n;
	cin>>n;
	int a[n+10];
	int b[n+10];
	int m=1;
	for(int i=0;i<n;i++) cin>>a[i],m*=a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int m1=m/a[i];
		int y1=modularInverse(m1,a[i]);
		sum+=(b[i]*m1*y1);
		//cout<<a[i]<<" "<<m1<<" "<<y1<<endl;
	}
	cout<<(sum%m)<<endl;
}
/* 3
3 5 7
2 3 2
=23
*/