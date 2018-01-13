#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fun(string s,ll l,ll r)
{
	if(l==r)
	{
		cout<<s<<endl;
		//return;
	}
	else
	{
		for(ll i=l;i<=r;i++)
		{
			char temp=s[i];
			s[i]=s[l];
			s[l]=temp;
			fun(s,l+1,r);
			temp=s[i];
			s[i]=s[l];
			s[l]=temp;
		}
	}
	
	
}
int main()
{
	string s;
	cin>>s;
	ll n=s.length();
	fun(s,0,n-1);
}
