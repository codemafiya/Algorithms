#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll a[],ll b[],ll n)
{
	ll dp[n+1][n+1];
	ll i;
	for(i=0;i<n;i++)
	{
		dp[0][i]=0;
		dp[i][0]=0;
		
	}
	ll j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==0||j==0)
			dp[i][j]=0;
			else if(a[i-1]==b[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;	
			}
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);	
		}
	}
	return dp[n][n];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i;
		ll a[n];
		ll b[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		cout<<fun(a,b,n);
			
	}	
}
