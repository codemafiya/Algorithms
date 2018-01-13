#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1001];
ll dp[1001][1001];
ll n;
ll sum;
void prints(vector<ll> v)
{
	ll m=v.size();
	for(ll i=0;i<m;i++)
	cout<<v[i]<<" ";
	cout<<endl;
}
void printsum(ll i,ll s,vector<ll> v)
{
	if(s==0)
	{
		prints(v);
		return;
	}
	if(i==0)
	return;
	if(a[i-1]<=s&&dp[i-2][s-a[i-1]])
	{
		v.push_back(a[i-1]);
		printsum(i-1,s-a[i-1],v);
	}
	if(dp[i-2][s])
	{
		vector<ll> b=v;
		printsum(i-1,s,b);
	}
	
	
	
}
ll issum()
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		dp[i][0]=1;
		
	}
	if(a[0]<=sum)
	dp[0][a[0]]=1;
	for(i=1;i<n;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(a[i]<=j)
			{
				if(dp[i-1][j]==1||dp[i-1][j-a[i]]==1)
				{
					dp[i][j]=1;
				}
			}
			else
			dp[i][j]=dp[i-1][j];
		}
	}
	if(dp[n-1][sum]==1)
	{
		vector<ll> v;
		printsum(n,sum,v);
	}
	return dp[n-1][sum];
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n>>sum;
		memset(dp,0,sizeof(dp));
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<issum()<<endl;
		
	}
}
