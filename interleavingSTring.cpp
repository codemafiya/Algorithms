#include<bits/stdc++.h>
using namespace std;
#define ll long long
void fun(string s1,string s2,ll m,ll n,ll i,ll j,ll k,char *s3)
{
	if(m==0&&n==0)
		cout<<s3<<endl;
	if(m!=0)
	{
		s3[k++]=s1[i++];
		fun(s1,s2,m-1,n,i,j,k,s3);
	}
	if(n!=0)
	{
		s3[k++]=s2[j++];
		fun(s1,s2,m,n-1,i,j,k,s3);
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		string s1;
		string s2;
		cin>>s1>>s2;
	
		ll i=0;
		ll j=0;
		ll m=s1.length();
		ll n=s2.length();
		
		char *s3=(char*)malloc((m+n+1)*sizeof(char));
		s3[m+n]='\0';
		fun(s1,s2,m,n,i,j,0,s3);
		free(s3);
	}
	return 0;
}
