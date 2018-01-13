#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct p{
    ll s,e;
}p;
map<ll,ll> m;
ll fun(p a[],ll n)
{
    ll vis[31]={0};
    vis[1]=1;
    queue<ll> q;
    ll dist[31];
    ll i;
    for(i=0;i<31;i++)
    dist[i]=INT_MAX;
    if(m[1]>=0)
    {
        q.push(m[1]); 
        dist[m[1]]=0;
    }
    else
    {
        q.push(1);
        dist[1]=0;
    }
    
    while(!q.empty())
    {
        ll temp=q.front();
        q.pop();
        if(temp==30)
        {
            return dist[30];
        }
        for(i=1;i<=6;i++)
        {
            if(vis[temp+i]==0)
            {
                if(m[temp+i]>0)
                {
                    q.push(m[temp+i]);
                    vis[temp+i]=1;
                    vis[m[temp+i]]=1;
                    dist[m[temp+i]]=dist[temp]+1;
                }
                else
                {
                    q.push(temp+i);
                    vis[temp+i]=1;
                    dist[temp+i]=dist[temp]+1;
                }
            }
        }
    }
    
}
int main() {
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    p a[n];
	    ll b[31]={0};
	    ll i;
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i].s>>a[i].e;
	        m[a[i].s]=a[i].e;
	    }
	    cout<<fun(a,n);
	    m.erase(m.begin(),m.end());
	    
	}
	return 0;
}
