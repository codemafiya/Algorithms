#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(string s,string s1)
{
	ll m=s.length();
	ll n=s1.length();
	ll dp[m+1][n+1];
	ll i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
			{
				dp[i][j]=i;	
			}
			else if(s[i-1]==s1[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	//cout<<dp[m][n]<<endl;
	
	return dp[m][n];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		ll k;
		cin>>s>>k;
		string s1;
		s1=s;
		reverse(s1.begin(),s1.end());
		//cout<<s1<<endl;
		//cout<<fun(s,s1)<<endl;
		if(fun(s,s1)<=2*k)
		{
			cout<<"YES"<<endl;
		}
		else
		cout<<"NO"<<endl;
		
	}
	return 0;
}
