#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
typedef struct point{
	ll x,y;
}point;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		point p11,p12,p21,p22;
		ll x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(x1<=x2)
		{
			p11.x=x1;
			p11.y=y1;
			p12.x=x2;
			p12.y=y2;
		}
		else
		{
			p11.x=x2;
			p11.y=y2;
			p12.x=x1;
			p12.y=y1;
		}
		cin>>x1>>y1>>x2>>y2;
		if(x1<=x2)
		{
			p21.x=x1;
			p21.y=y1;
			p22.x=x2;
			p22.y=y2;
		}
		else
		{
			p21.x=x2;
			p21.y=y2;
			p22.x=x1;
			p22.y=y1;
		}
		if(p11.x==p12.x==p21.x==p22.x)
		if(flag==1)
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
		
	}
	return 0;
	
}
