#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100];
void merge(ll l,ll m,ll r)
{
	ll b[100];
	ll k=0;
	ll i=l;
	ll j=m+1;
	while(i<=m&&j<=r)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i];
			i++;
		}
		else if(a[i]==b[j])
		{
			b[k++]=a[j];
			b[k++]=a[i];
			i++;
			j++;
		}
		else
		{
			b[k++]=a[j];
			j++;
		}
	}
	while(i<=m)
	{
		b[k++]=a[i];
		i++;	
	}
	while(j<=r)
	{
		b[k++]=a[j];
		j++;	
	}
	i=0;
	for(j=l;j<=r;j++)
	{
		a[j]=b[i];
		i++;
	}
	
}
void msort(ll l,ll r)
{
	if(l<r)
	{
		ll m=(l+r)/2;
		msort(l,m);
		msort(m+1,r);
		merge(l,m,r);
		
	}
	
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	cin>>a[i];
	msort(0,n-1);
	for(ll i=0;i<n;i++)
	cout<<a[i]<<" ";
	
		
}

