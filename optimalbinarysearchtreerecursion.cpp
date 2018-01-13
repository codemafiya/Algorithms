#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fsum(ll f[],ll i,ll j)
{
	ll sum=0;
	for(ll r=i;r<=j;r++)
	{
		sum+=f[r];
	}
	return sum;
}
ll optimal_cost(ll f[],ll i,ll j)
{
	if(j<i)
	return 0;
	if(j==i)
	return f[i];
	ll sum=fsum(f,i,j);
	ll r;
	ll min_cost=INT_MAX;
	for(r=i;r<=j;r++)
	{
		ll cost=optimal_cost(f,i,r-1)+optimal_cost(f,r+1,j);
		if(cost<min_cost)
		min_cost=cost;	
	}
	return min_cost+sum;
}
int main()
{
	ll n;
	cin>>n;
	ll key[n];
	ll f[n];
	ll i;
	for(i=0;i<n;i++)
	{
		cin>>key[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>f[i];
	}
	cout<<optimal_cost(f,0,n-1);
	return 0;
	
}
