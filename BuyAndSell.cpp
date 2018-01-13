#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct pro{
	ll buy;
	ll sell;
}pro;
void getTheList(ll a[],ll n)
{
	if(n==0)
	return;
	pro p[n/2+1];
	ll i=0;
	ll count=0;
	while(i<n-1)
	{
		while(i<n-1&&a[i]>=a[i+1])
			i++;
		if(i==n-1)
			break;
		p[count].buy=i++;
		while(i<n&&a[i]>=a[i-1])
			i++;
		p[count].sell=i-1;
		count++;
		
	}
	if(count==0)
		cout<<"always Loss"<<endl;
	for(i=0;i<count;i++)
		cout<<p[i].buy<<"    "<<p[i].sell<<endl;
	
	
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
		getTheList(a,n);
	}
	return 0;
}
