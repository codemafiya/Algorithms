#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n,k,x,m,s;
vector<pair<ll,ll> > v[100001];
ll dist[100001];
ll vis[100001];
void bfs(ll i)
{
	queue<ll> q;
	memset(vis,0,sizeof(vis));
	q.push(i);
	vis[i]=1;
	while(!q.empty())
	{
		ll p=q.front();
		q.pop();
		if(vis[p]==0)
		continue;
		if(p<=k)
		{
			for(i=1;i<=k;i++)
			{
				if(i!=p)
				{
					if(dist[i]==0||dist[i]>dist[p]+x)
					{
						dist[i]=dist[p]+x;
						q.push(i);
						vis[i]=1;
					}
				}
			}
		}
		
		for(vector<pair<ll,ll> >:: iterator it=v[p].begin();it!=v[p].end();it++)
		{
			if(vis[(*it).first]==0||dist[(*it).first]>dist[p]+((*it).second))
			{
				dist[(*it).first]=dist[p]+((*it).second);
                q.push((*it).first);
                vis[(*it).first]=1;
            }
		}
		
	}
	
	
}
int main()
{
	ll t;
	//cin>>t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld",&n,&k,&x,&m,&s);
		
		//cin>>n>>k>>x>>m>>s;
		ll i,j;
		ll a,b,y;
		for(i=0;i<m;i++)
		{
			//cin>>a>>b>>y;
			scanf("%lld%lld%lld",&a,&b,&y);
			v[a].push_back(make_pair(b,y));
			v[b].push_back(make_pair(a,y));
			
		}
		memset(dist,-1,sizeof(dist));
		dist[s]=0;
		bfs(s);
		for(i=1;i<=n;i++)
		{
			//v[i].clear();
			if(i==s)
			printf("0 ");
			else
			printf("%lld ",dist[i]);
			//cout<<dist[i]<<" ";
		}
		for(i=1;i<=n;i++)
		v[i].clear();
		cout<<endl;
	}
	return 0;
} 
