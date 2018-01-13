#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		ll acount=0;
		ll bcount=0;
		ll ccount=0;
		ll i;
		for(i=0;i<s.length();i++)
		{
			if(s[i]=='a')
				acount=1+2*acount;
			else if(s[i]=='b')
				bcount=acount+2*bcount;
			else if(s[i]=='c')
				ccount=bcount+2*ccount;
		}
		cout<<ccount<<endl;
		
	}
	return 0;
}
