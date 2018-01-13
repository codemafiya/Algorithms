#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minCut(string s)
{
	ll n=s.length();
	//cout<<n;
	ll c[n];
	bool p[n][n];
	ll i,j,l;
	for(i=0;i<n;i++)
		p[i][i]=true;
	
	for(l=2;l<=n;l++)
	{
		for(i=0;i<=n-l;i++)
		{
			j=i+l-1;
			if(l==2)
				p[i][j]=(s[i]==s[j]);
			else
				p[i][j]=((s[i]==s[j])&&p[i+1][j-1]);
		}
	}
	for(i=0;i<n;i++)
	{
		if(p[0][i]==true)
			c[i]=0;
		else
		{
			c[i]=INT_MAX;
			for(j=0;j<i;j++)
			{
				if(p[j+1][i]==true&&c[j]+1<c[i])
					c[i]=c[j]+1;
			}
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
		string s;
		cin>>s;
		cout<<s<<"   ="<<minCut(s)<<endl;	
	}
	return 0;	
}
