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
	int n,k;
	sc(n);
	sc(k);
	pr(modularInverse(n,k));
}
/* 3 11 = 4 */