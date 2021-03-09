/*
9
10 6 15 1 8 7 9 12 16
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
	int num;
	node *left,*right;
	node(){
		left=NULL;
		right=NULL;
	}
};

node *root=NULL;

void insert(int number){
	node *curr=root,*parent;
	if(root==NULL){
		root=new node();
		root->num=number;
	}else{
		while(1){
			if(number<=curr->num){
				if(curr->left==NULL) break;
				else curr=curr->left;
			}else{
				if(curr->right==NULL) break;
				else curr=curr->right;
			}
		}
		if(number<=curr->num){
			curr->left=new node();
			curr->left->num=number;
		}else{
			curr->right=new node();
			curr->right->num=number;
		}
	}
}

void del(int number){
	node *curr=root,*parent;
	//cout<<number<<endl;
	while(curr->num!=number){
		if(number<=curr->num) parent=curr,curr=curr->left;
		else parent=curr,curr=curr->right;
	}
	//cout<<parent->num<<endl;
	if(curr->left==NULL&&curr->right==NULL){
		if(number<=parent->num) parent->left=NULL;
		else parent->right=NULL;
		return;
	}else if(curr->left==NULL||curr->right==NULL){
		if(curr->num<=parent->num){
			if(curr->left==NULL) parent->left=curr->right;
			else parent->left=curr->left;
		}else{
			if(curr->left==NULL) parent->right=curr->right;
			else parent->right=curr->left;
		}
		return;	
	}else{
		node *temp=curr->right;
		while(temp->left!=NULL) temp=temp->left;
		//cout<<temp->num<<endl;
		del(temp->num);
		curr->num=temp->num;
	}
}

void pre_order(node *curr){
	if(curr==NULL) return;
	cout<<curr->num<<endl;
	pre_order(curr->left);
	pre_order(curr->right);
}

int main(){
	int n;cin>>n;
	while(n--){
		int q;cin>>q;
		insert(q);
	}
	del(7);
	pre_order(root);
}