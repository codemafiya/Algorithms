#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll findCost(ll a[],ll n,ll m)
{
	ll extraSpace[n+1][n+1];
	ll l[n+1][n+1];
	ll c[n+1],i,j;
	for(i=1;i<=n;i++)
	{
	
		extraSpace[i][i]=m-a[i-1];
		for(j=i+1;j<=n;j++)
			extraSpace[i][j]=extraSpace[i][j-1]-a[j-1]-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(extraSpace[i][j]<0)
			{
				l[i][j]=INT_MAX;	
			}
			/*else if(j==n&&extraSpace[i][j]>=0)
			{
				l[i][j]=0;	
			}*/
			else
			{
				l[i][j]=extraSpace[i][j]*extraSpace[i][j]*extraSpace[i][j];	
			}	
		}
	}
	c[0]=0;
	for(j=1;j<=n;j++)
	{
		c[j]=INT_MAX;
		for(i=1;i<=j;i++)
		{
			if(c[i-1]!=INT_MAX&&l[i][j]!=INT_MAX&&c[j]>c[i-1]+l[i][j])
				c[j]=c[i-1]+l[i][j];
		}
	}
	return c[n-1];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n;
		ll i;
		ll a[n];
		for (i=0;i<n;i++)
			cin>>a[i];
		cin>>m;
		cout<<findCost(a,n,m);
	}
	return 0;
}
