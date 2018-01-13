#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll v[100];
vector<ll> p[100];
void dfs(ll i)
{
	cout<<i;
	v[i]=1;
	for(vector<ll>::iterator it=p[i].begin();it!=p[i].end();it++)
	{
		if(v[*it]==0)
		{
			dfs(*it);	
		}
	}
}
int main()
{
	ll n,m;
	cin>>n>>m;
	
	memset(v,0,sizeof(v));
	ll i;
	ll a,b;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		p[a].push_back(b);
		p[b].push_back(a);
			
	}
	for(i=0;i<n;i++)
	{
		if(v[i]==0)
		{
			dfs(i);
			cout<<endl;
		}
	}
	return 0;
	
}
