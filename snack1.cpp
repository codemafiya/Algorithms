#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t,i;
	cin>>t;
	while(t--)
	{
		ll flag=1;
		ll n;
		cin>>n;
		string s;
		cin>>s;
		for(i=0;i<s.length();i++)
		{
			if(flag==1&&s[i]=='H')
			{
				flag=2;	
			}
			else if(flag==2&&s[i]=='T')
			{
				flag=1;	
			}
			else if((flag==1&&s[i]=='T')||(flag==2&&s[i]=='H'))
			{
				flag=3;
				break;
			}
				
		}
		if(flag==1)
			cout<<"Valid"<<endl;
		else
			cout<<"Invalid"<<endl;
	}
	return 0;
}
