#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll knapsack(ll w[],ll val[],ll we,ll n)
{
	ll i,j;
	ll a[n+1][we+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=we;j++)
		{
			if(i==0||j==0)
			{
				a[i][j]=0;
			}
			else if(w[i-1]<=j)
			{
				a[i][j]=max(val[i-1]+a[i-1][j-w[i-1]],a[i-1][j]);
			}
			else
			a[i][j]=a[i-1][j];
		}
	}
	return a[n][we];
}
int main()
{
	ll n,we;
	cin>>n>>we;
	ll w[n],val[n];
	ll i;
	for(i=0;i<n;i++)
	cin>>w[i]; 
	for(i=0;i<n;i++)
	cin>>val[i];
	cout<<knapsack(w,val,we,n);
	return 0;
}
