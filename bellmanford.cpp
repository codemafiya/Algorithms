#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;

typedef struct e{
	ll f,s,w;
}e;
e a[100];
ll src;
void fun()
{
	cout<<"a";
	ll i,j;
	//cout<<"k"<<m<<n;
	ll dist[n+1];
	memset(dist,INT_MAX,sizeof(dist));
	for(i=1;i<=n;i++)
	cout<<dist[i]<<" ";
	cout<<endl;
	dist[src]=0;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<m;j++)
		{
			ll u=a[j].f;
			ll v=a[j].s;
			ll we=a[j].w;
			cout<<u<<v<<we<<dist[u]<<endl;
			if(dist[u]!=INT_MAX&&dist[u]+we<dist[v])
			{
				dist[v]=dist[u]+we;	
				//cout<<u<<" "<<v<<" "<<dist[v]<<endl;	
			}		
		}	
	}
	for(i=0;i<m;i++)
	{
		ll u=a[i].f;
		ll v=a[i].s;
		ll we=a[i].w;
		
		if(dist[u]!=INT_MAX&&dist[u]+we<dist[v])
		{
			cout<<"graph contains a cycle"<<endl;	
		}	
	}
	for(i=1;i<=n;i++)
		{
			cout<<"b";
			cout<<dist[i]<<" ";
			//cout<<endl;
		
		}
		cout<<endl;	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		ll i=0,x,y;
		
		
	
		cin>>src;
		//dist[src]=0;
		while(i<m)
		{
			cin>>a[i].f>>a[i].s>>a[i].w;
			i++;	
		}
		fun();
		
		
	}
	return 0;
}
