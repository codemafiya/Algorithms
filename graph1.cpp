#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll visited[100003];
vector<ll> v[100003];
ll nodes=0;
void dfs(ll i)
{
	visited[i]=1;
	nodes++;
	//cout<<n<<endl;
	for(vector<ll>:: iterator it=v[i].begin();it!=v[i].end();it++)
	{
		if(visited[*it]==0)
		{
			dfs(*it);
		}
	}
}
int main()
{
	ll t;
	cin>>t;
	ll n,m,a,b;
	while(t--)
	{
		cin>>n>>m>>a>>b;
		ll x,y;
		ll i;
		for(i=0;i<m;i++)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);	
		}
		memset(visited,0,sizeof(visited));
		ll cost=0;
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				nodes=0;
				
				dfs(i);
				cost=cost+a;
				//cout<<nodes<<endl;
				//cost1=cost1+(nodes-1)*b+a;
				if(a > b)
                    cost = cost + (b*(nodes-1));
                else
                    cost = cost + (a*(nodes-1));	
			}	
		}
		cout<<cost<<endl;
		for(i=0 ; i<=n ; i++)
        {
            v[i].clear();
        }	
	}	
	return 0;
}
