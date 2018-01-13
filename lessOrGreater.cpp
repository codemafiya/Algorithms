#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll b[],ll n,ll key,ll l,ll r)
{
	ll mid;
	while(l<r)
	{
		
		mid=(l+r)/2;
		if(b[mid]==key)
		{
			while(b[mid+1]==key&&mid+1<n)
			{
				mid++;
			}
			break;
		}
		else if(b[mid]>key)
		{
			r=mid;
		}
		else
		l=mid+1;
	} 
	while(b[mid]>key)
		mid--;
	return mid+1;
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
		ll b[n];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			
			
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
			
			
		}
		sort(b,b+n);
	
		for(i=0;i<n;i++)
		{
			ll ans=fun(b,n,a[i],0,n)<0?fun(b,n,a[i],0,n):0;
			if(i==n-1)
			cout<<ans;
			else
			cout<<ans<<",";
		}
		cout<<endl;
			
	}
}
