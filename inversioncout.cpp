#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100000];
ll merge(ll l,ll mid,ll r)
{
	ll i=l;
	ll j=mid;
	ll k=0;
	ll temp[r-l+1];
	ll count=0;
	while(i<=(mid-1)&&j<=r)
	{
		if(a[i]<a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			count=count+mid-i;
		}
		
	}
	while(i<mid)
	temp[k++]=a[i++];
	while(j<=r)
	temp[k++]=a[j++];
	for(i=l;i<=r-l+1;i++)
	{
		a[i]=temp[i-l];
	}
	
	return count;
	
}
ll fun(ll l,ll r)
{
	ll count=0;
	if(l<r)
	{
		ll mid=(l+r)/2;
		count=fun(l,mid);
		count=count+fun(mid+1,r);
		count=count+merge(l,mid+1,r);
		
	}
	return count;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<fun(0,n-1)<<endl;
			
	}
}
