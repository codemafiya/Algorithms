
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000];
ll quick(ll l,ll r)
{
	ll i=l-1,j;
	ll temp;
	for(j=l;j<=r-1;j++)
	{
		if(a[j]<=a[r])
		{
			i++;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;		
		}	
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;	
}
void partition(ll l,ll r)
{
	if(l<r)
	{
		int pi=quick(l,r);
		partition(l,pi-1);	
		partition(pi+1,r);		
	}
}
int main()
{
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<n;i++)
	cin>>a[i];
	partition(0,n-1);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}
