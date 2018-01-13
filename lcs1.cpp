#include<iostream>
using namespace std;
int lcs(string &x,string &y)
{
	int m=x.length();
	int n=y.length();
	int i,j;
	int l[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
			l[i][j]=0;
			else if(x[i-1]==y[j-1])
			l[i][j]=l[i-1][j-1]+1;
			else
			l[i][j]=max(l[i-1][j],l[i][j-1]);	
		}	
	}
	return l[m][n];	
} 
int main()
{
	int t;
	string s1,s2;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2;
		cout<<lcs(s1,s2)<<endl;
		
	}
	return 0;
}
