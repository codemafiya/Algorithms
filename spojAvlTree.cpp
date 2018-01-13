#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct Node{
	ll key;
	Node *left;
	Node *right;
	ll height;
}Node;
ll hgt(Node *node)
{
	if(node==NULL)
		return 0;
	else 
		return node->height;
}
Node* leftRotate(Node *node)
{
	Node *x=node->right;
	Node *y=x->left;
	x->left=node;
	node->right=y;
	node->height=max(hgt(node->left),hgt(node->right))+1;
	x->height=max(hgt(x->left),hgt(x->right))+1;
	return x;
	
}
Node* rightRotate(Node *node)
{
	Node *x=node->left;
	Node *y=x->right;
	x->right=node;
	node->left=y;
	node->height=max(hgt(node->left),hgt(node->right))+1;
	x->height=max(hgt(x->left),hgt(x->right))+1;
	return x;
}

Node* insert(Node *node,ll val)
{
	//Step 1: insertion of node
	if(node==NULL)
	{
		node=(Node*)malloc(sizeof(Node));
		node->key=val;
		node->left=NULL;
		node->right=NULL;
		node->height=1;
		return node;
	}
	else if(val<node->key)
		node->left=insert(node->left,val);
	else if(val>node->key)
		node->right=insert(node->right,val);
	else
		return node;
	//Step 2: Updating the height of each node
	node->height=1+max(hgt(node->left),hgt(node->right));
	//Step 3: Finding the unbalanced tree
	ll bal;
	if(node==NULL)
	{
		bal=0;
	}
	else
	{
		bal=hgt(node->left)-hgt(node->right);
	}
	//Step 4: Rotating the tree
	if(bal>1&&val<node->left->key)
		return rightRotate(node);
	if(bal<-1&&val>node->right->key)
		return leftRotate(node);
	if(bal>1&&val>node->left->key)
	{
		node->left=(leftRotate(node->left));
		return rightRotate(node);
	}
	if(bal<-1&&val<node->right->key)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
		
	
}
void preOrderTraversal(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
		
	}
}
int main()
{
	ll op,val;
	Node *node=NULL;
	cin>>op;
	while(op!=-1)
	{
		cin>>val;
		if(op==1)
		{
			node=insert(node,val);
		}
		else if(op==2)
		{
			//remove(val);
		}
		else if(op==3)
		{
			//printIndex(val);
		}
		else if(op==4)
		{
			//printData(val);
		}
		cin>>op;
		
	}
	preOrderTraversal(node);
	return 0;
}
