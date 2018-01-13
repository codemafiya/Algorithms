#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a[],ll n)
{
	ll left[n];
	ll right[n];
	ll i;
	ll w=0;
	left[0]=a[0];
	for(i=1;i<n;i++)
	left[i]=max(left[i-1],a[i]);
	right[n-1]=a[n-1];
	for(i=n-1;i>=0;i--)
	right[i]=max(right[i+1],a[i]);
	for(i=0;i<n;i++)
	w=w+min(left[i],right[i])-a[i];
	return w;
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
		ll i;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<fun(a,n);
		cout<<endl;
	}
	return 0;
}
