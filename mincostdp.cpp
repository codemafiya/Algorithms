#include<bits/stdc++.h>
#define R 100
#define C 100
using namespace std;
int mina(int a,int b,int c);
int mincost(int cost[][C], int m, int n)
{
     int i, j;
 
     // Instead of following line, we can use int tc[m+1][n+1] or 
     // dynamically allocate memoery to save space. The following line is
     // used to keep te program simple and make it working on all compilers.
     int tc[R][C];  
 
     tc[0][0] = cost[0][0];
 
     /* Initialize first column of total cost(tc) array */
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
 
     /* Initialize first row of tc array */
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
 
     /* Construct rest of the tc array */
     for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = mina(tc[i-1][j-1], tc[i-1][j], tc[i][j-1]) + cost[i][j];
 
     return tc[m][n];
}
int mina(int a,int b,int c)
{
	return min(min(a,b),c);
}
int main(){
	int t,m,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		int a[R][C];
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		cout<<mincost(a,m-1,n-1)<<endl;
	}
	return 0;
}
