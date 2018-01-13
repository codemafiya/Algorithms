#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findPivote(ll a[],ll left,ll right)
{
	if(left>right)
		return -1;
	if(left==right)
		return left;
	ll mid=(left+right)/2;
	if(mid<right&&a[mid]>a[mid+1])
		return mid;
	if(mid>left&&a[mid]<a[mid-1])
		return mid-1;
	if(a[left]>=a[mid])
		return findPivote(a,left,mid-1);
	return findPivote(a,mid+1,right);
}
ll binarySearch(ll a[],ll left,ll right,ll key)
{
	if(right<left)
	{
		return -1;	
	}
	ll md=(left+right)/2;
	if(a[md]==key)
		return md;
	if(a[md]<key)
		return binarySearch(a,md+1,right,key);
	return binarySearch(a,left,md-1,key);
		
}


ll search(ll a[],ll left,ll right,ll key)
{
	ll pivot=findPivote(a,left,right);
	if(pivot==-1)
		return binarySearch(a,left,right,key);
	if(a[pivot]==key)
		return pivot;
	if(a[0]<=key)
		return binarySearch(a,0,pivot-1,key);
	return binarySearch(a,pivot+1,right,key);
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i;
		ll a[n];
		for(i=0;i<n;i++)
			cin>>a[i];
		ll key;
		cin>>key;
		cout<<search(a,0,n-1,key);
	}
	return 0;
}
