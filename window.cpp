#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(string s)
{
	ll n=s.length();
	ll visited[26]={0};
	ll dist_count=0;
	ll i;
	for(i=0;i<n;i++)
	{
		if(visited[s[i]-97]==0)
		{
			dist_count++;
			visited[s[i]-97]=1;	
		}	
	}
	ll mn=INT_MAX;
	ll count[26]={0};
	ll k=0;
	ll start=0;
	for(i=0;i<n;i++)
	{
		count[s[i]-97]++;
		if(count[s[i]-97]==1)
		{
			k++;
		}
		if(k==dist_count)
		{
			while(count[s[start]-97]>1)
			{
				count[s[start]-97]--;
				start++;	
			}
			ll len=i-start+1;
			if(len<mn)
			{
				mn=len;	
			}	
		}	
	}
	return mn;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<fun(s)<<endl;
	}
	return 0;
}
