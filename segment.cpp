#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[1000];
void build(ll a[],ll l,ll r,ll node){
	if(l>r)
	return;
	if(l==r)
	{
		t[node]=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(a,l,mid,2*node+1);
	build(a,mid+1,r,2*node+2);
	t[node]=t[node*2+1]+t[node*2+2];
	
}
int q(ll l,ll r,ll ql,ll qr,ll node)
{
	if(qr<l||ql>r||l>r)
	{
		return 0;
	}
	if(l>=ql&&r<=qr)
	return t[node];
	ll mid=(l+r)/2;
	return q(l,mid,ql,qr,node*2+1)+q(mid+1,r,ql,qr,node*2+2);
}
void update(ll l,ll r,ll i,ll val,ll node)
{
	if(l>r||i<l||i>r)
	return;
	t[node]=t[node]+val;
	if(l!=r)
	{
		ll mid=(l+r)/2;
		
		update(l,mid,i,val,node*2+1);
		update(mid+1,r,i,val,node*2+2);
	}
	
}
int main()
{
	ll n;
	cin>>n;
	ll a[n];
	ll i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	build(a,0,n-1,0);
	for(i=0;i<20;i++)
	cout<<t[i]<<"  ";
	cout<<endl;
	ll qe;
	cin>>qe;
	while(qe--)
	{
		ll x;
		cin>>x;
		if(x==1)
		{
			ll y,z;
			cin>>y>>z;
			cout<<q(0,n-1,y-1,z-1,0)<<endl;
		}
		else
		{
			ll ind,val;
			cin>>ind>>val;
			update(0,n-1,ind-1,val-a[ind-1],0);
		}
	}
}
