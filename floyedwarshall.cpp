#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll m;
	cin>>m;
	ll a[n][n];
	memset(a,-1,sizeof(a));
	ll i,j,x,y,w,r;
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>w;
		a[x][y]=w;
		//a[y][x]=w;
				
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			a[i][j]=0;
			else if(a[i][j]==-1)
			a[i][j]=INT_MAX;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(r=0;r<n;r++)
			{
				if(a[i][r]!=INT_MAX&&a[r][j]!=INT_MAX&&a[i][r]+a[r][j]<a[i][j])
				a[i][j]=a[i][r]+a[r][j];
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
	return 0;	
}
