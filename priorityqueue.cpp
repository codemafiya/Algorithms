#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct p{
	ll t,x,d;
	bool operator<(const p& o) const{
		if(d<o.d)
		return true;
		else if(d>o.d)
		return false;
		else
		{
			if(t<o.t)
			return true;
			else return false;
		}
	}
}p;
int main()
{
	ll n,b;
	cin>>n>>b;
	priority_queue<p> q;
	ll i,x;
	p z;
	for(i=0;i<n;i++)
	{
		cin>>x;
		
		z.d=x;
		z.t=x;
		
		z.x=1;
		q.push(z);
	}
	/*while(!q.empty())
	{
		p z;
		z=q.top();
		cout<<z.t<<z.d<<endl;
		q.pop();
	}*/
	b=b-n;
	while(b--)
	{
		z=q.top();
		z.x++;
		x=(z.t/z.x);
		if((z.x)*x<z.t)
		x++;
		cout<<x<<endl;
		z.d=x;
		//z.x++;
		q.pop();
		q.push(z);
	}
	z=q.top();
	cout<<z.d;
}
