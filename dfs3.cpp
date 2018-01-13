#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bfs(vector<ll> v[],ll n)
{
	ll vis[n+1];
	ll color[n+1];
	ll i,k;
	memset(vis,0,sizeof(vis));
	memset(color,-1,sizeof(color));
	ll flag=0;
	for(k=1;k<=n;k++)
	{
		if(vis[k]==0)
		{
			queue<ll> q;
			q.push(k);
			color[k]=1;
			while(!q.empty())
			{
				ll node=q.front();
				q.pop();
				vis[node]=1;
				for(i=0;i<v[node].size();i++)
				{
					if(color[v[node][i]]==-1)
					color[v[node][i]]=(!color[node]);
					else if(color[v[node][i]]==color[node])
					{
						flag=1;
						break;
						
					}
					if(vis[v[node][i]]==0)
					q.push(v[node][i]);
				}
				if(flag==1)
				break;
			}
		}
		if(flag==1)
		break;
		
	}
	return flag;
	
}
int main() 
{
	// your code goes here
	ll t;
	cin>>t;
	ll k;
	for(k=1;k<=t;k++)
	{
		ll n,m;
		cin>>n>>m;
		vector<ll> v[n+1];
		ll i,x,y;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		
		cout<<"Scenario #"<<k<<":"<<endl;
		if(bfs(v,n))
		{
			
			cout<<"Suspicious bugs found!"<<endl;
		}
		else
		{
			cout<<"No suspicious bugs found!";
		}
		
		
	}
	return 0;
}
