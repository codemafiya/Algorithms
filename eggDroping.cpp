#include<bits/stdc++.h>
using namespace std;
#define ll  long long
ll fun(ll n,ll k)
{
	ll dp[n+1][k+1];
	ll i,j,x;
	for(i=1;i<=k;i++)
		dp[1][i]=i;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=0;
		dp[i][1]=1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			for(x=1;x<=j;x++)
			{
				ll res=1+max(dp[i-1][x-1],dp[i][j-x]);
				if(res<dp[i][j])
					dp[i][j]=res;
			}
		}
	}
	return dp[n][k];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		cout<<fun(n,k)<<endl;
	}
	return 0;
}
