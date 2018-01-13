#include<stdio.h>
#include<limits.h>
int dp[1000][1000];
int mcm(int p[],int n)
{
	int temp,i,l,k,j;
	for(i=1;i<=n;i++)
	dp[i][i]=0;
	for(l=2;l<=n;i++) // l is the length
	{
		for(i=1;i<=n-l+1;i++)
		{
			dp[i][j]=INT_MAX;
			j=i+l-1;
			for(k=i;k<j;k++)
			{
				temp=dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(temp<dp[i][j])
				dp[i][j]=temp;
			}
		}
	}
	return dp[1][n];
}
int main()
{
	int p[10000],n,i,j;
	printf("Enter the number of matrices\n");
	scanf("%d",&n);
	
	for(i=1;i<=n+1;i++)
	scanf("%d",&p[i]);
	
	printf("%d\n",mcm(p,n));
	return 0;	
}
