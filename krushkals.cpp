#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll parent[10000];
ll rank[10000];
typedef struct edge
{
    ll n1,n2,val;
}edge;
ll gcd(ll x,ll y)
{
	if(y==0)
	return x;
	else
	return gcd(y,x%y);
}
bool fun(edge e1,edge e2)
{
    return e1.val<=e2.val;
}
ll find(ll x)
{
    if(parent[x]!=x)
    parent[x]=find(parent[x]);
    return parent[x];
    
}
void union1(ll x,ll y)
{
    ll xroot=find(x);
    ll yroot=find(y);
    if(rank[xroot]<rank[yroot])
    {
        parent[xroot]=yroot;
    }
    else if(rank[yroot]<rank[xroot])
        parent[yroot]=xroot;
    else
    {
        parent[yroot]=xroot;
        rank[xroot]++;
    }
    
}
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,e,k;
	    cin>>n>>e;
	    edge eg[e];
	    ll i;
	    for(i=0;i<e;i++)
	    {
	        cin>>eg[i].n1>>eg[i].n2>>eg[i].val;
	    }
	    for(i=0;i<=n;i++)
	    {
	        parent[i]=i;
	        rank[i]=0;
	    }
	    sort(eg,eg+e,fun);
	    map<pair<ll,ll>,ll> mp;
	    for(i=0;i<e;i++)
	    {
	        ll x=eg[i].n1;
	        ll y=eg[i].n2;
	        if(find(x)!=find(y))
	        {
	            
	            union1(x,y);
	            pair<ll,ll> p;
	            p.first=x;
	            p.second=y;
	            mp[p]=1;
	            p.first=y;
	            p.second=x;
	            mp[p]=1;
	            
	        }
	        
	    }
	    ll q;
		cin>>q;
		ll ans=0;
		ll de=q;
		while(q--)
		{
			ll x,y;
			cin>>x>>y;
			pair<ll,ll> p,p1;
			p.first=x;
			p1.first=y;
			p1.second=x;
			p.second=y;
			if(mp[p]==1||mp[p1]==1)
			ans++;	
		}
		cout<<ans<<endl;
		if(ans==0)
		cout<<0<<endl;
		else
		{
			ll gc=gcd(ans,de);
			cout<<ans/gc<<"/"<<de/gc<<endl;
		}
	}
     
    
	
    return 0;
}
