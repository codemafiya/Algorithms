#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum=0;
void merge(ll a[],ll temp[],ll l,ll mid,ll r)
{
	ll i=l;
	ll j=mid;
	ll k=l;
	while(i<=mid-1&&j<=r)
	{
		if(a[i]<a[j])
		{
			sum=sum+a[i]*(r-j+1);
			temp[k++]=a[i];
			i++;
		}
		else
		{
			temp[k++]=a[j++];
		}
		
	}
	while(i<=mid-1)
	temp[k++]=a[i++];
	while(j<=r)
	temp[k++]=a[j++];
	for(i=l;i<=r;i++)
	a[i]=temp[i];
}
void mergesort(ll a[],ll temp[],ll l,ll r)
{
	ll mid;
	
	if(l<r)
	{
		mid=l+(r-l)/2;
		mergesort(a,temp,l,mid);
		mergesort(a,temp,mid+1,r);
		merge(a,temp,l,mid+1,r);
		
	}
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n],temp[n];
		ll i;
		for(i=0;i<n;i++)
		cin>>a[i];
		sum=0;
		mergesort(a,temp,0,n-1);
		cout<<sum<<endl;
	}
}
