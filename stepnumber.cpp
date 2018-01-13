#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll count1=0;
void fun(ll n,ll m,ll i)
{
	queue<ll> q;
	q.push(i);
	while(!q.empty()){
		ll no=q.front();
		q.pop();
		if(no>=n&&no<=m)
		count1++;
		if(i==0||no>m)
		continue;
		ll rem=no%10;
		if(rem==9)
		q.push(no*10+rem-1);
		else if(rem==0)
		q.push(no*10+rem+1);
		else
		{
			q.push(no*10+rem-1);
			q.push(no*10+rem+1);
			
		}
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll i;
		count1=0;
		for(i=0;i<=9;i++)
		{
			fun(n,m,i);
			
		}
		cout<<count1<<endl;
	}
	return 0;
}
