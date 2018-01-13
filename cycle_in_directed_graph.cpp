#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v[1001];
ll vis[1001];
ll s[1001];
ll fun(ll i)
{
	if(vis[i]==0)
	{
		vis[i]=1;
		s[i]=1;
		for(vector<ll>:: iterator it=v[i].begin();it!=v[i].end();it++)
		{
			if(vis[*it]==0&&fun(*it)==1)
			return 1;
			else if(s[*it]==1)
			{
				return 1;
			}
		}
	}
	s[i]=0;
	return 0;
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		memset(vis,0,sizeof(vis));
		memset(s,0,sizeof(s));
		ll x,y;
		while(m--)
		{
			cin>>x>>y;
			v[x].push_back(y);
		}
		ll i;
		ll flag=0;
		for(i=1;i<=n;i++)
		{
			if(fun(i))
			{
				flag=1;
				break;	
			}	
		}
		if(flag==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		for(i=0;i<=n;i++)
		v[i].clear();
		
		
	}
	return 0;
}
