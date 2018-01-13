#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll n,ll m)
{
	if(m==0)
	return n;
	return gcd(m,n%m);
}
ll fun(ll from,ll to,ll d)
{
	ll s=0;
	ll f=from;
	ll t=0;
	s=1;
	while(f!=d&&t!=d)
	{
		ll temp=min(f,to-t);
		f=f-temp;
		t=t+temp;
		s++;
		if(f==d||t==d)
		break;
		if(f==0)
		{
			f=from;
			s++;	
		}
		if(t==to)
		{
			t=0;
			s++;	
		}
		
					
	}
	return s;
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,d;
		cin>>n>>m>>d;
		ll mx=max(n,m);
		ll mn=min(n,m);
		n=mx;
		m=mn;
		if(d>n)
		cout<<-1<<endl;
		else if(d%gcd(n,m)!=0)
		cout<<-1<<endl;
		else
		cout<<min(fun(n,m,d),fun(m,n,d))<<endl;
	}
	return 0;
}
