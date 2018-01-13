#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a[],ll n)
{
	ll p[n];
	memset(p,0,sizeof(p));
	ll mx=a[n-1];
	ll i;
	for(i=n-2;i>=0;i--)
	{
		mx=max(mx,a[i]);
		p[i]=max(p[i+1],mx-a[i]);	
	}
	ll mn=a[0];
	for(i=1;i<n;i++)
	{
		mn=min(mn,a[i]);
		p[i]=max(p[i-1],p[i]+a[i]-mn);	
	}
	return p[n-1];	
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
		for(ll i=0;i<n;i++)
		cin>>a[i];
		cout<<fun(a,n)<<endl;
	}
	return 0;
}
