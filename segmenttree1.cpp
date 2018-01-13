#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[100005];
ll tree[400021];
void build(ll i,ll l,ll r)
{
	if(r<l)
	return;
	if(l==r)
	{
		if(a[l]==1)
		tree[i]=1;
		else
		tree[i]=0;
		return;
		
	}
	else
	{
		ll mid=(l+r)/2;
		build(i*2,l,mid);
		build(i*2+1,mid+1,r);
		if(tree[2*i]==1&&tree[2*i+1]==1)
		tree[i]=tree[2*i]+tree[2*i+1];
		else
		tree[i]=max(tree[2*i],tree[2*i]+1);
	}
}
void update(ll i,ll l,ll r,ll x)
{
	if(l==r)
	{
		tree[i]=1;
	}
	else
	{
		ll mid=(l+r)/2;
		if(x<=mid)
		{
			update(i*2,l,mid,x);
		}
		else
		update(i*2+1,mid+1,r,x);
		if(tree[2*i]==1&&tree[2*i+1]==1)
		tree[i]=tree[2*i]+tree[2*i+1];
		else
		tree[i]=max(tree[2*i],tree[2*i]+1);
		
	}
}
ll find(ll i,ll l,ll r,ll k)
{
	if(tree[i]<k)
	return -1;
	if(l==r)
	return l;
	ll mid=(l+r)/2;
	return max(find(2*i,l,mid,k),find(2*i+1,mid+1,r,k-tree[2*i]));	
}
int main()
{
	ll k;
	cin>>n>>k;
	ll i;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0')
		a[i]=0;
		else
		a[i]=1;
	}
	build(1,0,n-1);
	for(i=0;i<6;i++)
	cout<<tree[i]<<" ";
	cout<<endl;
	while(k--)
	{
		ll t,x;
		cin>>t;
		if(t==1)
		{
			ll ans=tree[1];
			cout<<ans<<endl;
		}
		else
		{
			cin>>x;
			update(1,0,n-1,x);
		}
	}
	return 0;
	
}
