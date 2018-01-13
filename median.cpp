#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000];
ll b[1000];
ll get(ll a[],ll b[],ll n)
{
	if(n<=0)
	return -1;
	if(n==1)
	return (a[0]+b[0])/2;
	if(n==2)
	return (max(a[0],b[0])+min(a[1],b[1]))/2;
	ll m1,m2;
	if(n%2==0)
	{
		m1=(a[n/2]+a[n/2-1])/2;
		m2=(b[n/2]+b[n/2-1]);	
	}
	else
	{
		m1=a[n/2];
		m2=b[n/2];
	}
	if(m1==m2)
	return m1;
	else if(m1<m2)
	{
			
	}
	
}
int main()
{
	ll n,m,i;
	cin>>n;
	
	for(i=0;i<n;i++)
	cin>>a[i];
	
	for(i=0;i<n;i++)
	cin>>b[i];
	cout<<get(0,n-1,0,n-1,n);
}
