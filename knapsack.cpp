#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll val[n];
		ll wt[n];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>val[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>wt[i];
		}
		ll w;
		cin>>w;
		ll dp[n+1][w+1];
		ll j;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=w;j++)
			{
				if(i==0||j==0)
				dp[i][j]=0;
				else if(wt[i-1]<=j)
				{
					dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
						
				}
				else
				dp[i][j]=dp[i-1][j];	
			}
		}
		cout<<dp[n][w];
	}
	return 0;
}
