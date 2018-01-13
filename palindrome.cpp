#include<iostream>
using namespace std;
int palindrome(string s)
{
	int n=s.length();
	int i,j,k;
	
	bool a[n][n];
	int max_length=0;
	for(i=0;i<n;i++)
	{
		a[i][i]=true;
	}
	for(i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			a[i][i+1]=true;
			max_length=2;
		}
	}
	for(k=3;k<=n;k++)
	{
		for(j=0;j<n-k+1;j++)
		{
			i=j+k-1;
			if(a[j+1][i-1]&&s[j]==s[i])
			{
				a[j][i]=true;
				if(max_length<k)
				max_length=k;
			}
		}
	}
	return max_length;
}
int main()
{
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		cout<<palindrome(s)<<endl;	
	}	
	return 0;
}
