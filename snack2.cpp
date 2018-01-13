#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,i;
	cin>>t;
	while(t--)
	{
		ll flag=1;
		ll n;
		cin>>n;
		ll a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		if(n%2==0)
			cout<<"no"<<endl;
		else if(n%2==1&&a[0]==1)
		{
			for(i=1;i<=n/2;i++)
			{
				if(a[i]!=a[i-1]+1)
				{
					flag=2;
					break;
				}
			}
			for(i=n/2+1;i<n;i++)
			{
				if(a[i]!=a[i-1]-1)
				{
					flag=2;
					break;
				}
				
			}
			if(flag==1)
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
		else
			cout<<"no"<<endl;
	}
	return 0;
}
