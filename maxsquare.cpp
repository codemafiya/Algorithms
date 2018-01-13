#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll a[n][m];
		ll dp[n][m];
		ll i,j,mx=INT_MIN;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				
			}
		}
		for(i=0;i<n;i++)
		{
			dp[i][0]=a[i][0];
			
		}
		for(i=0;i<m;i++)
		{
			dp[0][i]=a[0][i];
		}
		for(i=1;i<n;i++)
		{
			for(j=1;j<m;j++)
			{
				if(a[i][j]==0)
				dp[i][j]=0;
				else
				dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
				mx=max(mx,dp[i][j]);
			}
		}
		cout<<mx<<endl;
	}
	return 0;
}
