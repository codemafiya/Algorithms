#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	ll dep[n];
	ll i;
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		ll h=0;
		ll j=0;
		while(s[j]!=':')
		{
			h=h*10+(s[j]-'0');
			j++;
		}
		h=h*60;
		ll m=0;
		j++;
		while(j<s.length())
		{
			m=m*10+(s[j]-'0');
			j++;	
		}
		ll ti=h+m;
		arr[i]=ti;
		
	}
	for(i=0;i<n;i++)
	{
		string s;
		cin>>s;
		ll h=0;
		ll j=0;
		while(s[j]!=':')
		{
			h=h*10+(s[j]-'0');
			j++;
		}
		h=h*60;
		ll m=0;
		j++;
		while(j<s.length())
		{
			m=m*10+(s[j]-'0');
			j++;	
		}
		ll ti=h+m;
		dep[i]=ti;
		
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" "<<dep[i]<<endl;
	}
	i=0;
	ll j=0;
	sort(arr,arr+n);
	sort(dep,dep+n);
	ll need=1,res=1;
	while(i<n&&j<n)
	{
		if(arr[i]<dep[j])
		{
				need++;
				if(need>res)
				{
					res=need;
				}
				i++;
		}
		else
		{
			need--;
			j++;
		}
	}
	cout<<res<<endl;
}
