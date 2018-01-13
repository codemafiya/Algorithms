#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum(ll f[],ll i,ll j)
{
	ll s=0;
	for(ll k=i;k<=j;k++)
	s=s+f[k];
	return s;
}
int main()
{
	ll n;
	cin>>n;
	ll f[n];
		ll i,j,k,l;
	for(i=0;i<n;i++)
	cin>>f[i];
	ll a[n][n];

	for(i=0;i<n;i++)
	{
		a[i][i]=f[i];	
	}
	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l+1;i++)
		{
			j=i+l-1;
			a[i][j]=INT_MAX;
			for(k=i;k<=j;k++)
			{
				ll c=((k>i)?a[i][k-1]:0)+((k<j)?a[k+1][j]:0)+sum(f,i,j);
				if(c<a[i][j])
				a[i][j]=c;	
			}	
		}	
	}
	cout<<a[0][n-1];
	return 0;	
}
