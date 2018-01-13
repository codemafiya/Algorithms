#include<bits/stdc++.h>
using namespace std;
#define ll long long
void heapify(ll a[],ll n,ll i)
{
	ll la=i;
	ll l=2*i+1;
	ll r=2*i+2;
	if(l<n&&a[la]<a[l])
	la=l;
	if(r<n&&a[la]<a[r])
	la=r;
	if(la!=i)
	{
		ll temp=a[la];
		a[la]=a[i];
		a[i]=temp;
		heapify(a,n,la);
	}
}
void heapsort(ll a[],ll n)
{
	ll i;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		ll temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	ll n;
	cin>>n;
	ll i;
	ll a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	heapsort(a,n);	
}
