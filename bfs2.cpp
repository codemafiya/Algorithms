#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll node;
vector<ll> v[10001];
bool vis[10001];
ll dist[10001];
ll mx,m;
void bfs(ll n)
{
	memset(vis,false,sizeof(vis));
	ll t;
	ll i;
	memset(dist,0,sizeof(dist));
	queue<ll> q;
	q.push(n);
	vis[n]=true;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<v[t].size();i++)
		{
			if(vis[v[t][i]]==false)
			{
				vis[v[t][i]]=true;
				dist[v[t][i]]=dist[t]+1;
				q.push(v[t][i]);
			}
			
		}	
	}
	mx=0;
	for(i=1;i<=node;i++)
	{
		if(mx<=dist[i])
		{
			mx=dist[i];
			m=i;
			
		}
		
	}
	
}
int main()
{
	
	cin>>node;
	ll t=node-1;
	ll x,y;
	while(t--)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);	
	}
	bfs(1);
	bfs(m);
	cout<<mx;
	return 0;
	
}
