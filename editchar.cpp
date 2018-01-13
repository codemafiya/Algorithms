#include<bits/stdc++.h>
using namespace std;
int mina(int a,int b,int c);
int editchar(string a,string b)
{
	int m=a.length();
	int n=b.length();
	int dp[m+1][n+1];
	int i,j;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0)
			dp[i][j]=j;
			else if(j==0)
			dp[i][j]=i;
			else if(a[i-1]==b[j-1])
			dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=1+mina(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
	
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
		cout<<editchar(a,b)<<endl;
	}
	return 0;
}
