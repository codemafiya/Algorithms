#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,c;
		cin>>n>>c;
		ll i;
		ll a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		ll mid;
		ll l=1;
		ll r=1000000001;
		ll ans=0;
		while(l<=r)
		{
			mid=(l+r)/2;
			ll temp=a[0];
			ll count=1;
			for(i=1;i<n;i++)
			{
				if(a[i]-temp>=mid)
				{
					count++;
					temp=a[i];
				}
			}
			if(count<c)
			{
				r=mid-1;
			}
			else
			{
				ans=mid;
				l=mid+1;
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
