#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a[],ll n)
{
	ll lis[n];
	ll lds[n];
	ll i,j;
	for(i=0;i<n;i++)
	{
		lis[i]=1;
		lds[i]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i]&&lis[i]<lis[j]+1)
			lis[i]=lis[j]+1;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		for(j=n-1;j>i;j--)
		{
			if(a[j]<a[i]&&lds[i]<lds[j]+1)
			lds[i]=lds[j]+1;
		}
	}
	ll mx=lis[0]+lds[0]-1;
	for(i=1;i<n;i++)
	{
		mx=max(mx,lis[i]+lds[i]-1);		
	}
	return mx;
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
			cin>>a[i];
		cout<<fun(a,n)<<endl;
	}
	return 0;
}
