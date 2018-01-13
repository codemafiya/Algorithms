#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
	{
        ll m,n;
        cin>>m>>n;
        ll x[m],y[n];
        for(ll i=1;i<m;++i)
		{
            cin>>x[i];
        }
        for(ll i=1;i<n;++i)
		{
            cin >> y[i];
        }
        ll h=1,v=1;
        sort(x+1,x+m);
        reverse(x+1,x+m);
        sort(y+1,y+n);
        reverse(y+1,y+n);
        ll i=1,j=1;
        ll ans = 0;
        while(i<m&&j<n)
		{
            if(x[i]>y[j])
			{
                ans+=x[i]*v;
                ++h;
                ++i;
            } 
			else 
			{
                ans+=y[j]*h;
                ++v;
                ++j;
            }
        }
        if(i<m)
		{
           ll sum=0;
            while(i<m)
			{
                sum+=x[i];
                ++i;
            }
            ans+=sum*v;
        } 
		else 
		{
            ll sum=0;
            while(j<n)
			{
                sum+=y[j];
                ++j;
            }
            ans+=sum*h;
        }
        cout<<ans<<endl;
    }
    return 0;
}

