#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,o;
		cin>>n>>m>>o;
		ll a[n];
		ll b[m];
		ll c[o];
		ll i,j,k;
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<m;i++)
			cin>>b[i];
		for(i=0;i<o;i++)
			cin>>c[i];
		i=0;
		j=0;
		k=0;
		while(i!=n&&j!=m&&k!=o)
		{
			if(a[i]<=b[j]&&a[i]<=c[k])
			{
				if(a[i]==b[j]&&a[i]==c[k])
				cout<<a[i]<<" ";
				i++;
			}
			if(b[j]<=a[i]&&b[j]<=c[k])
			{
				if(a[i]==b[j]&&a[i]==c[k])
				cout<<a[i]<<" ";
				j++;
			}
			if(c[k]<=b[j]&&c[k]<=a[i])
			{
				if(a[i]==b[j]&&a[i]==c[k])
				cout<<a[i]<<" ";
				k++;
			}
		}
		cout<<endl;
		
	}
	return 0;
}
