#include <bits/stdc++.h>
using namespace std;

#define mx 26
struct node
{
	bool endmark;
	node* next[mx];
	node()
	{
		endmark=false;
		for(int i=0;i<mx;i++)next[i]=NULL;
	}
};
node *root=new node();


void insert(string s)
{
	node *curr=root;
	for(int i=0;i<s.size();i++)
	{
		int id=s[i]-'a';
		if(curr->next[id]==NULL)
		{
			curr->next[id]=new node();
		}
		curr=curr->next[id];
	}
	curr->endmark=true;
}

bool search(string s)
{
	node *curr=root;
	for(int i=0;i<s.size();i++)
	{
		int id=s[i]-'a';
		if(curr->next[id]==NULL)
		{
			return false;
		}
		curr=curr->next[id];
	}
	return curr->endmark;
}


int main(int argc, char const *argv[])
{
	int n;
	string s;


	cin>>n;
	while(n--)
	{
		cin>>s;
		insert(s);
	}


	cin>>n;
	while(n--)
	{
		cin>>s;
		cout<<search(s)<<endl;
	}
	return 0;
}