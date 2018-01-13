#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int minkey(int key[],bool mstset[])
{
	int min=INT_MAX,min_index;
	for(int i=0;i<n;i++)
	{
		if(mstset[i]==false && key[i]<min)
		{
			min=key[i],min_index=i;
		}
	}
	return min_index;
}
void print(int parent[],int n)
{
	for(int i=1;i<n;i++)
	{
		cout<<parent[i]<<" "<<i<<" "<<a[i][parent[i]]<<endl;
	}
}
void prims(int n)
{
	int parent[n];
	int key[n];
	bool mstset[n];
	for(int i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<n-1;count++)
	{
		int u=minkey(key,mstset);
		mstset[u]=true;
		for(int v=0;v<n;v++)
		{
			if(a[u][v]!=0 && mstset[v]==false && a[u][v]<key[v])
			{
				parent[v]=u,key[v]=a[u][v];
			}
		}
	}
	print(parent,n);
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		prims(n);
	}
	return 0;
}
