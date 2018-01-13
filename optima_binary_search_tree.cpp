#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(ll f[],ll i,ll j)
{
	ll sum=0;
	for(ll k=i;k<=j;k++)
	sum+=f[k];
	return sum;
}
ll optimal_cost(ll key[],ll f[],ll n)
{
	ll i,j,k,l;
	ll a[n][n];
	for(i=0;i<n;i++)
	a[i][i]=f[i];
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=n-i+1;j++)
		{
			k=i+j-1;
			a[j][k]=INT_MAX;
			for(l=j;l<=k;l++)
			{
				ll cost=(l>j?a[j][l-1]:0)+(l<k?a[l+1][k]:0)+sum(f,j,k);
				if(cost<a[j][k])
				a[j][k]=cost;	
			}
		}
	}
	return a[0][n-1];
}
int main()
{
	ll n;
	cin>>n;
	ll key[n];
	ll f[n];
	ll i;
	for(i=0;i<n;i++)
	cin>>key[i];
	for(i=0;i<n;i++)
	cin>>f[i];
	cout<<optimal_cost(key,f,n);
	return 0;	
}
