#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000];
ll partition(ll l,ll r)
{
	ll i=l-1;
	ll p=a[r];
	ll j;
	for(j=l;j<r;j++)
	{
		if(a[j]<p)
		{
			i++;
			ll t=a[j];
			a[j]=a[i];
			a[i]=t;
		}
	}
	ll t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	return i+1;
}
void quicksort(ll l,ll r)
{
	if(l<r)
	{
		ll pi=partition(l,r);
		quicksort(l,pi-1);
		quicksort(pi+1,r);
		
	}
}
int main()
{
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(0,n-1);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}

