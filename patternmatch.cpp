#include<iostream>
using namespace std;
bool fun(char *s1,char *s2)
{
	if(*s1=='\0'&&*s2=='\0')
	return true;
	if(*s1=='*'&&*(s1+1)!='\0'&&*s2=='\0')
	return false;
	if(*s1=='?'||*s1==*s2)
	return fun(s1+1,s2+1);
	if(*s1=='*')
	return fun(s1+1,s2)||fun(s1,s2+1);
	//return false;
}
int main()
{
	int t;
	char *s1,*s2;
	cin>>t;
	while(t--)
	{
		cin>>s1;
		cin>>s2;	
		cout<<fun(s1,s2)<<endl;
	}
	return 0;
}
