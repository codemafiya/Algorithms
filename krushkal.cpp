#include<stdio.h>
#include<iostream>
using namespace std;
int parent[100];
typedef struct node
{
	int u,v,w;
}node;

int find(int x)
{
	while(x!=parent[x])
	{
		x=parent[x];
	}
	return x;
}

void sort(node a[],int e)
{
	for(int i=0;i<e-1;i++)
	{
		for(int j=i+1;j<e;j++)
		{
			if(a[i].w>a[j].w)
			{
				node t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	node a[e];
	
	for(int i=0;i<e;i++)
	{
		cin>>a[i].w>>a[i].u>>a[i].v;
	}
	
	sort(a,e);
	
	for(int i=0;i<=n;i++)
	{
		parent[i]=i;
	}
	
	int ans=0;
	
	for(int i=0;i<e;i++)
	{
		int root1=find(a[i].v);
		int root2=find(a[i].u);
		if(root1!=root2)
		{
			parent[root1]=root2;
			ans+=a[i].w;
		}
	}
	
	cout<<ans<<endl;
	return 0;
	
	
}
