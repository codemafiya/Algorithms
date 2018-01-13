#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll vis[1001];
vector<ll> v[1001];
ll iscycle(ll i,ll p)
{
	vis[i]=1;
	for(vector<ll>:: iterator it=v[i].begin();it!=v[i].end();it++)
	{
		if(vis[*it]==0)
		{
			if(iscycle(*it,i))
			return 1;	
		}
		else if(*it!=p)
		return 1;
	}
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
		ll i,x,y;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		ll flag=0;
		ll count=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				flag=iscycle(i,-1);
				if(flag==1)
				{
					count++;
					flag=0;	
				}
					
			}	
		}
		if(flag==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		cout<<count<<endl;
		for(i=0;i<=n;i++)
		{
			v[i].clear();
		}
		
	}
	return 0;
}
