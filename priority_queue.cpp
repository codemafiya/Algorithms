#include<bits/stdc++.h>
using namespace std;
typedef struct p{
	int a , b;
}p;
bool comp(p x,p y)
{
	x.a<=y.b;
}
struct compare{
	bool operator()(p &x,p &y)
	{
		return x.a>=y.a;	
	}
};
int main()
{
	priority_queue<p,vector<p>,compare> q;
	p x;
	x.a=4;
	x.b=1; 
	q.push(x);
		x.a=3;
	x.b=2;
	q.push(x);
		x.a=5;
	x.b=3;
	q.push(x);
	while(!q.empty())
	{
		cout<<(q.top()).a;
		q.pop();
	}
}
