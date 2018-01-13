#include<bits/stdc++.h>
using namespace std;
#define ll long long
	ll a[100][100];
ll fun(ll d[],ll vi[],ll n)
{
	ll mi=INT_MAX;
	ll k=-1,i;
	//for(i=0;i<n;i++)
	//cout<<d[i]<<"  ";
	for(i=0;i<n;i++)
	{
		if(vi[i]==false&&d[i]<=mi)
		{
			mi=d[i];
			k=i;
		}
	}
	return k;
}
void findd(ll n,ll src)
{
	ll vi[n];
	ll d[n];
	ll i,j;
	for(i=0;i<n;i++)
	{
		vi[i]=false;
		d[i]=INT_MAX;
	}
	d[src]=0;
	for(i=0;i<n-1;i++)
	{
		ll u=fun(d,vi,n);
		cout<<u<<"  ";
		vi[u]=true;
		for(j=0;j<n;j++)
		{
			if(vi[j]==false&&d[u]!=INT_MAX&&a[u][j]!=0&&d[u]+a[u][j]<d[j])
			d[j]=d[u]+a[u][j];
		}
	}
	for(i=0;i<n;i++)
	cout<<i<<"   "<<d[i];
	
	
	
}

int main()
{
	ll n;
	cin>>n;

	ll v;
	memset(a,0,sizeof(a));
	ll i,x,y,w;
	cin>>v;
	for(i=0;i<v;i++)
	{
		cin>>x>>y>>w;
		a[x][y]=w;
		a[y][x]=w;	
	}
	ll src;
	cin>>src;
	findd(n,src);
	return 0;
}
