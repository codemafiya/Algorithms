#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll n)
{
	ll dp[n];
	dp[0]=0;
	dp[1]=1;
	dp[3]=1;
	for(ll i=2;i<n;i++)
	{
		if(i!=3){
		
		dp[i]=INT_MAX;
		if(i-1>=0)
		dp[i]=min(dp[i],dp[i-1]+1);
		if(i-3>=0)
		dp[i]=min(dp[i],dp[i-3]+1);	
	}
	}
	return dp[n-1];	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<fun(n)<<endl;
	}
}
