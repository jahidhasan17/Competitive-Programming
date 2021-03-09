#include <bits/stdc++.h>
using namespace std;

vector<int>prime;
vector<int>primeinRange;
void prime_generator(int size)
{
    bool bo[size];
    memset(bo,0,sizeof(bo));
    for(int i=2;i<=size;i++)
    {
        if(!bo[i])
        {
            prime.push_back(i);
            for(int j=i;j<=size;j+=i)
            {
                bo[j]=1;
            }
        }
    }
}

void primeInRange(int l,int r)
{
    int size=sqrt(r)+1;
    prime_generator(size);
    int n=r-l+1;
    bool bo[n+10];
    memset(bo,0,sizeof(bo));

    for(int i=0;i<prime.size();i++)
    {
        int limit=((l/prime[i])*prime[i]);
        if(limit<l) limit+=prime[i];
        if(limit==prime[i]) limit+=prime[i];
        for(int j=limit;j<=r;j+=prime[i])
        {
            bo[j-l]=1;
        }
    }
    for(int i=l;i<=r;i++)
    {
        if(!bo[i-l])
        {
            primeinRange.push_back(i);
        }
    }
}

int main()
{
    int l,r;
    cin>>l>>r;
    primeInRange(l,r);
    for(int i=0;i<primeinRange.size();i++)
    {
        cout<<primeinRange[i]<<endl;
    }
}