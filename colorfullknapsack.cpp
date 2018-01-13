#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[101]={0};
ll K(ll a[],ll b[],ll n,ll m,ll x)
{
	if(n==0)
	{
		return 0;
	}
	ll o1=0;
	ll o2=0;
	ll color=b[n-1];
	if(x>=a[n-1])
	{
		if(c[color]==0)
		{
			c[color]=1;
			o1=a[n-1]+K(a,b,n-1,m,x-a[n-1]);
			c[color]=0;
		}
	}
	o2=K(a,b,n-1,m,x);
	if(o1>o2)
	{
		c[color]=1;
		return o1;
	}
	else
	return o2;
}
void fun(ll a[],ll b[],ll n,ll m,ll x)
{
	ll ans=K(a,b,n,m,x);
	ll flag=0;
	ll i;
	for(i=0;i<=m;i++)
	cout<<c[i]<<" ";
	cout<<endl;
	for(i=1;i<=m;i++)
	{
		if(c[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<"-1"<<endl;
	}
	else
	cout<<x<<" "<<ans<<endl;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,x;
		cin>>n>>m>>x;
		ll a[n];
		ll b[n];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		memset(c,0,sizeof(c));
		fun(a,b,n,m,x);
	}
	return 0;
}
