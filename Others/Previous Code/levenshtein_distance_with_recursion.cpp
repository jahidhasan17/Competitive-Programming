#include <bits/stdc++.h>
using namespace std;
char s1[1000],s2[1000];
int l1,l2;

int min(int x,int y,int z)
{
	return min(x,min(y,z));
}
int editdistance(int i,int j)
{
	if(i>=l1) return l2-j;
	if(j>=l2) return l1-i;
	if(s1[i]==s2[j]) return editdistance(i+1,j+1);
	return 1+min(editdistance(i+1,j),editdistance(i,j+1),editdistance(i+1,j+1));

}

int main()
{
	scanf("%s %s",s1,s2);
	l1=strlen(s1);
	l2=strlen(s2);	
	cout<<editdistance(0,0)<<endl;
}