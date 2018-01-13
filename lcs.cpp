#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m[100];
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	ll m=s1.length();
	ll n=s2.length();
	ll a[m+1][n+1];
	for(ll i=0;i<=m;i++)
	{
		for(ll j=0;j<=n;j++)
		{
			if(i==0||j==0)
			a[i][j]=0;
			else if(s1[i-1]==s2[j-1])
			a[i][j]=a[i-1][j-1]+1;
			else
			a[i][j]=max(a[i-1][j],a[i][j-1]);
		}		
	}
	cout<<a[m][n];
	return 0;	
}
