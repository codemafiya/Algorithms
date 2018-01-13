#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minx(ll a,ll b,ll c)
{
	return min(min(a,b),c);
}
ll editDistance(string s1,string s2,ll m,ll n)
{
	ll i,j;
	ll dp[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(s1[i-1]==s2[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+minx(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}
	return dp[m][n];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		cout<<editDistance(s1,s2,s1.length(),s2.length())<<endl;
		
	}
	return 0;
}
