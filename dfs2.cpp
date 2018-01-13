#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool is[10001];
void seive()
{
	is[2]=false;
	ll i,j;
	for(i=2;i*i<=10000;i++)
	{
		if(is[i]==false)
		{
			for(j=2*i;j<=10000;j=j+i)
			is[j]=true;
			
		}
	}
}
void getdigit(ll top,ll num[])
{
	ll i=3;
	while(top>0)
	{
		num[i--]=top%10;
		top=top/10;
	}
	
}
ll getnumber(ll num[])
{
	ll temp=0;
	ll k;
	for(k=0;k<=3;k++)
	{
		temp=temp*10+num[k];
		
	}
	return temp;
}
int main()
{
	seive();
	ll t;
	cin>>t;
	ll n,m;
	while(t--)
	{
		cin>>n>>m;
		ll dist[10001];
		memset(dist,-1,sizeof(dist));
		dist[n]=0;
		queue<ll> q;
		q.push(n);
		ll i,j;
		ll num[4];
		while(!q.empty())
		{
			ll top=q.front();
			
			for(i=3;i>=0;i--)
			{
				getdigit(top,num);
				for(j=0;j<=9;j++)
				{
					num[i]=j;
					ll temp=getnumber(num);
					if((!is[temp])&&dist[temp]==-1&&temp>=1000)
					{
						dist[temp]=dist[top]+1;
						q.push(temp);
					}
					
				}				
			}
			q.pop();
			
		}
		if(dist[m]==-1)
		cout<<"Impossible"<<endl;
		else
		cout<<dist[m]<<endl;
			
	}	
}
