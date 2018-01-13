#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll knapsack(ll w[],ll val[],ll we,ll n)
{
	if(n==0||we==0)
	return 0;
	if(w[n-1]>we)
	return knapsack(w,val,we,n-1);
	else
	return max(val[n-1]+knapsack(w,val,we-w[n-1],n-1),knapsack(w,val,we,n-1));
}
int main()
{
	ll n,we;
	cin>>n>>we;
	ll w[n],val[n];
	ll i;
	for(i=0;i<n;i++)
	cin>>w[i]; 
	for(i=0;i<n;i++)
	cin>>val[i];
	cout<<knapsack(w,val,we,n);
	return 0;
}
