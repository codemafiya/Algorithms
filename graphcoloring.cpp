#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100][100];
ll c[100];
bool is(ll i,ll j,ll n)
{
	ll k;
	for(k=0;k<n;k++)
	{
		if(a[i][k]&&c[k]==j)
		return false;
		
	}
	return true;
}
bool fun(ll k,ll n,ll i)
{
	if(i>=n)
	return true;
	ll j;
	for(j=1;j<=k;j++)
	{
		if(is(i,j,n))
		{
			c[i]=j;
			if(fun(k,n,i+1))
			return true;
			c[i]=0;	
		}
	}
	return false;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	ll i,j,x,y;
	memset(a,0,sizeof(a));
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
			
	}
	memset(c,0,sizeof(c));
	ll k;
	cin>>k;
	if(fun(k,n,0)==false)
	cout<<"NOT POSSIBLE";
	else
	{
		for(i=0;i<n;i++)
		cout<<c[i]<<"   ";
	}
	return 0;
		
}
