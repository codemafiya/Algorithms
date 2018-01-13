#include<bits/stdc++.h>
using namespace std;
# define ll long long
ll a[100][100];
ll fun(ll vi[],ll d[],ll n)
{
	ll k=-1,mi=INT_MAX,i;
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
void findd(ll n)
{
	ll d[n],vi[n],p[n];
	ll i;
	for(i=0;i<n;i++)
	{
		d[i]=INT_MAX;
		vi[i]=false;
	}
	d[0]=0;
	p[0]=-1
	ll j;
	for(i=0;i<n-1;i++)
	{
		ll u=fun(vi,d);
		for(j=0;j<n;j++)
		{
			if(vi[j]==false&&a[u][j]!=0&&a[u][j]<d[j])
			{
				
				d[j]=a[u][j]
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<p[i]<<"    "<<i<<"    "<<a[i][p[i]]<<endl;
	}
	
}
int main()
{
	ll n,m,i;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(i=0;i<m;i++)
	{
		cin>>x>>y>>w;
		a[x][y]=w;
		a[y][x]=w;	
	}
	findd(n);
	return 0;
	
}
