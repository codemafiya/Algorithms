#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dx[8]={1,-1,2,-2,1,-1,-2,2};
ll dy[8]={2,2,1,-1,-2,-2,1,-1};
ll count;
ll dist[8][8];
bool vis[8][8];
ll bfs(ll i,ll j,ll k,ll l)
{
	pair<ll,ll>p;
	queue<pair<ll,ll> > q;
	memset(dist,INT_MAX,sizeof(dist));
	memset(vis,false,sizeof(vis));
	dist[i][j]=0;
	vis[i][j]=true;
	q.push(make_pair(i,j));
	ll i1;
	while(!q.empty())
	{
		pair<ll,ll> p1=q.front();
		ll x=p1.first;
		ll y=p1.second;
		q.pop();
		for(i1=0;i1<8;i1++)
		{
			if(x+dx[i1]<=7&&x+dx[i1]>=0&&y+dy[i1]<=7&&y+dy[i1]>=0&&vis[x+dx[i1]][y+dy[i1]]==false)
			{
				vis[x+dx[i1]][y+dy[i1]]=true;
				dist[x+dx[i1]][y+dy[i1]]=dist[x][y]+1;
				q.push(make_pair(x+dx[i1],y+dy[i1]));
				//cout<<dist[x+dx[i1]][y+dy[i1]]<<endl;
				
				
			}
		}
	}
	return dist[k][l];
	
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		ll i=s1[0]-97;
		ll j=s1[1]-49;
		ll k=s2[0]-97;
		ll l=s2[1]-49;
		//cout<<i<<j<<k<<l;
		
		cout<<bfs(i,j,k,l)<<endl;
		
		
	}
}
