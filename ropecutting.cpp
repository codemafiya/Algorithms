#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fun(ll n)
{
	ll val[n+1];
	val[0]=0;
	val[1]=0;
	ll i,j;
	for(i=1;i<=n;i++)
	{
		ll res=0;
		for(j=0;j<=i/2;j++)
		{
			res=max(res,max(j*(i-j),j*val[i-j]));	
		}
		val[i]=res;
	}
	return val[n];
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<fun(n)<<endl;
	}
	return 0;
}
