#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll i;
		for(i=1;i<=1000000000;i=i*10)
		{
			if(n/i>=1&&n/i<=9)
			{
				cout<<i<<endl;
				break;		
			}	
		}	
	}
		
}
