#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll block=174;
typedef struct qu{
	ll l,r,ind;
}qu;
ll h[1000001];
bool cmp(qu f,qu s)
{
    if((f.l/block)!=(s.l/block))
        return (f.l/block)<(s.l/block);
    else
        return f.r<s.r;
}
int main()
{
	ll n;
	cin>>n;
	ll i;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll q;
	cin>>q;
	qu b[q];
	memset(h,0,sizeof(h));
	for(i=0;i<q;i++)
	{
		cin>>b[i].l>>b[i].r;
		b[i].ind=i;
		
		b[i].l--;
		b[i].r--;
	}
	sort(b,b+q,cmp);
	ll l1=b[0].l;
	ll r1=b[0].r;
	ll ans[q];
	//for(i=0;i<q;i++)
	//cout<<b[i].l<<b[i].r<<endl;
	memset(ans,0,sizeof(ans));
	//cout<<l1<<r1<<endl;
	for(i=l1;i<=r1;i++)
	{
		if(h[a[i]]==0)
		ans[b[0].ind]++;
		h[a[i]]++;
	}
	ll s=ans[b[0].ind];
	//cout<<s<<endl;
	for(i=1;i<q;i++)
	{
		while(l1<b[i].l)
		{
			if(h[a[l1]]>0)
			h[a[l1]]--;
			if(h[a[l1]]==0)
			s--;
			l1++;
		}
		while(l1>b[i].l)
		{
			h[a[l1-1]]++;
			if(h[a[l1-1]]==1)
			s++;
			l1--;
		}
		while(r1<b[i].r)
		{
			h[a[r1+1]]++;
			if(h[a[r1+1]]==1)
			s++;
			r1++;
		}
		while(r1>b[i].r)
		{
			h[a[r1]]--;
			if(h[a[r1]]==0)
			s--;
			r1--;
		}
		ans[b[i].ind]=s;
		//cout<<ans[b[i].ind]<<endl;
		
	}
	for(i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
