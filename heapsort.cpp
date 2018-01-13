#include<bits/stdc++.h>
using namespace std;
#define ll long long
void heapify(ll a[],ll n,ll i)
{
	ll l=2*i+1;
	ll r=2*i+2;
	ll temp;
	ll largest=i;
	if(l<n&&a[l]>a[largest])
	largest=l;
	if(r<n&&a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}
void heapsort(ll a[],ll n)
{
	ll i;
	ll temp;
	for(i=n/2-1;i>=0;i--)
	{
		heapify(a,n,i);
	}
	for(i=n-1;i>=0;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapify(a,i,0);	
	}
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	ll i=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	heapsort(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}	
	return 0;
}
