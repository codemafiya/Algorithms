#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll m=s1.length();
		ll n=s2.length();
		ll dp[m+1][n+1];
		ll i,j;
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(i==0||j==0)
					dp[i][j]=0;
				else if(s1[i-1]==s2[j-1])
					dp[i][j]=dp[i-1][j-1]+1;
				else
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
