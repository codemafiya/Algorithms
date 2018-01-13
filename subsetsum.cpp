#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool fun(ll a[],ll n,ll sum)
{
	if(sum==0&&n>=0)
	return true;
	else if(n<0)
	return false;
	else
	return fun(a,n-1,sum)||fun(a,n-1,sum-a[n-1]);
}
int main()
{
	ll n;
	cin>>n;
	ll a[n],i;
	for(i=0;i<n;i++)
	cin>>a[i];
	ll sum;
	cin>>sum;
	if(fun(a,n,sum))
	cout<<"possible";
	else
	cout<<"not posiible";
	return 0;
}
