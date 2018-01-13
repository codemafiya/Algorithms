#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct p{
	ll ele,ind;
};
bool fun(p x,p y)
{
	return x.ele<=y.ele;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		p a[n];
		ll i;
		for(i=0;i<n;i++)
		{
			cin>>a[i].ele;
			a[i].ind=i;
		}
		sort(a,a+n,fun);
		bool vis[n];
		for(i=0;i<n;i++)
		{
			vis[i]=false;
		}
		ll ans=0;
		for(i=0;i<n;i++)
		{
			if(vis[i]||a[i].ind==i)
				continue;
			else
			{
				ll j=i;
				ll count=0;
				while(!vis[j])
				{
					vis[j]=true;
					j=a[j].ind;
					count++;	
				}
				ans=ans+count-1;	
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
