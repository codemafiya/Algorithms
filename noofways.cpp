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
		ll dp[n+1];
		ll i;
		for(i=0;i<=n;i++)
		{
			if(i<=2)
			dp[i]=i;
			else
			dp[i]=dp[i-1]+(i-1)*dp[i-2];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
