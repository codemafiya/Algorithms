#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m,i;
	cin>>n>>m;
	vector<ll> e[n];
	ll v[n];
	ll x,y;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);			
		
	}
	queue<ll> q;
	memset(v,0,sizeof(v));
	q.push(2);
	v[2]=1;
	while(q.empty()==false)	
	{
		ll top=q.front();
		q.pop();
		cout<<top<<"  ";
		for(vector<ll>::iterator it=e[top].begin();it!=e[top].end();it++)
		{
			if(v[*it]==0)
			{
				v[*it]=1;
				q.push(*it);
			}
		}
	}
}
