#include <bits/stdc++.h>
using namespace std;

bool f[1010],as=0;
vector<int> pr;
int n;
void prime()
{
    for(int i=0;i<=n;i++)f[i]=1;f[0]=f[1]=0;
    for(int i=4;i<=n;i+=2)f[i]=0;
    for(int i=3;i*i<=n;i+=2)if(f[i])for(int j=i+i;j<1010;j+=i)f[j]=0;
    for(int i=0;i<=n;i++)if(f[i])pr.push_back(i);
}

int main()
{
	cin>>n;
	prime();
	for(int i=0;i<pr.size();i++)
	{
		cout<<pr[i]<<endl;
	}
}