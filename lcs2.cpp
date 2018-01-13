#include<bits/stdc++.h>
using namespace std;
int lcs( string X, string Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}
int max(int a, int b)
{
    return (a > b)? a : b;
}
int main()
{
	int t;
	string a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<lcs(a,b,a.length(),b.length())<<endl;
	}
	return 0;
}
