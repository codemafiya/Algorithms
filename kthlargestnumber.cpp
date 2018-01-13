#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100];
ll partition(ll l, ll r)
{
	ll i=l;
	ll j;
	for(j=l;j<r;j++)
	{
		if(a[j]<=a[r])
		{
			ll temp=a[j];
			a[j]=a[i];
			a[i]=a[temp];
			i++;
		}
	}
	ll temp=a[i];
	a[i]=a[r];
	a[r]=temp;
	return i;
}
ll fun(ll l,ll r,ll k)
{
	if(k>0&&k<=r-l+1)
	{
		//cout<<"a";
		ll p=partition(l,r);
		//cout<<p<<endl;	
		if(p-l==k-1)
		{
			return a[p];
		}
		if(p-l>k-1)
		return fun(l,p-1,k);
		return fun(p+1,r,k-(p-l+1));
	}
	return INT_MAX;
	
		
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<n;i++)
		cin>>a[i];
		cout<<fun(0,n-1,k)<<endl;
	}
	return 0;
}
