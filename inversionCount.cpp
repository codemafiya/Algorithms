#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(ll a[],ll temp[],ll left,ll mid,ll right)
{
	ll i=left;
	ll j=mid;
	ll k=left;
	ll inv=0;
	while(i<=mid-1&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			inv=inv+mid-i;	
			//2 5 3 5 8 9 
		}
	}
	while(i<=mid-1)
	{
		temp[k++]=a[i++];
	}
	while(j<=right)
	{
		temp[k++]=a[j++];
	}
	for(i=left;i<=right;i++)
		a[i]=temp[i];
	return inv;
}
ll mergesort(ll a[],ll temp[],ll left,ll right)
{
	ll inv=0,mid;
	if(left<right)
	{
		mid=(left+right)/2;
		inv=mergesort(a,temp,left,mid);
		inv=inv+mergesort(a,temp,mid+1,right);
		inv=inv+merge(a,temp,left,mid+1,right);
	}
	return inv;
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
		{
			cin>>a[i];	
		}
		ll temp[n];
		cout<<mergesort(a,temp,0,n-1);
			
	}	
}
