#include<iostream>
using namespace std;
/* this program illustrate that in how many ways we can partition n numbers
of an array*/
/* suppose we have 3 nos numbered 1,2,3 then
we can prtition them like below-->
1-{{1},{2},{3}}
2-{{1},{2,3}}
3-{{2},{1,3}}
4-{{3},{1,2}}
5-{{1,2,3}} */
int bell(int n)
{
	int bell[n+1][n+1];
	bell[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		bell[i][0]=bell[i-1][i-1];
		for(int j=1;j<=i;j++)
		bell[i][j]=bell[i-1][j-1]+bell[i][j-1];
	}
	return bell[n][0];
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<bell(n)<<endl;
	}
	return 0;
}
