#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;


typedef struct e{
	ll s,d,w;
}e;
typedef struct subset{
	ll parent,rank;
}subset;
e a[100001];
subset sub[10001];
ll find(ll x)
{
	if(x!=sub[x].parent)
	{
		sub[x].parent=find(sub[x].parent);
	}
	return sub[x].parent;
}
void union1(ll x,ll y)
{
	ll rootx=find(x);
	ll rooty=find(y);
	if(sub[rootx].rank<sub[rooty].rank)
	{
		sub[rootx].parent=rooty;
	}
	else if(sub[rooty].rank<sub[rootx].rank)
	{
		sub[rooty].rank=rootx;
	}
	else
	{
		sub[rooty].parent=rootx;
		sub[rootx].rank++;
	}
}
bool fun(e x,e y)
{
	return x.w<=y.w;
}
int main()
{
	
	cin>>n>>m;
	
	ll i,x,y;
	for(i=0;i<m;i++)
	{
		cin>>a[i].s>>a[i].d>>x;
		if(x==0)
		a[i].w=0;
		else
		{
			cin>>y;
			a[i].w=y;
		}
	}
	for(i=1;i<=n;i++)
	{
		sub[i].parent=i;
		sub[i].rank=0;
	}
	sort(a,a+m,fun);
	x=0;
	i=0;
	e res[n-1];
	while(x<n-1)
	{
		ll source=a[i].s;
		ll dest=a[i].d;
		ll we=a[i++].w;
		ll s1=find(source);
		ll s2=find(dest);
		if(s1!=s2)
		{
			union1(s1,s2);
			res[x].s=source;
			res[x].d=dest;
			res[x++].w=we;
		}
	}
	ll sum=0;
	for(i=0;i<n-1;i++)
	{
		sum=sum+res[i].w;
	}
	cout<<sum;
}
