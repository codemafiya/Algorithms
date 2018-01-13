#include<bits/stdc++.h>
using namespace std;
int mina(int a,int b,int c);
int editchar(string a,string b,int m,int n)
{
	if(m==0)
	return n;
	else if(n==0)
	return m;
	else if(a[m-1]==b[n-1])
	return editchar(a,b,m-1,n-1);
	else
	return 1+mina(editchar(a,b,m-1,n),editchar(a,b,m,n-1),editchar(a,b,m-1,n-1));
	
}
int mina(int a,int b,int c)
{
	return min(min(a,b),c);
}
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		cout<<editchar(a,b,a.length(),b.length())<<endl;
	}
	return 0;
}
