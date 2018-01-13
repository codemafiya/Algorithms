#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a[],ll n,ll m)
{
	ll b[m];
	ll i,j;
	for(i=0;i<m;i++)
	b[i]=0;
	for(i=0;i<n;i++)
	{
		if(b[0])
		return true;
		ll c[m];
		memset(c,0,sizeof(c));
		for(j=0;j<m;j++)
		{
			if(b[j]&&b[(j+a[i])%m]==0)
			c[(j+a[i])%m]=1;	
		}
		for(j=0;j<m;j++)
		{
			if(b[j]==0)
			b[j]=c[j];
		}
		b[a[i]%m]=1;
	}
	return b[0];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		ll m;
		cin>>m;
		cout<<fun(a,n,m)<<endl;
	}
	return 0;
}
