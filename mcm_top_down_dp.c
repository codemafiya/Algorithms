#include<stdio.h>
#include<limits.h>
int dp[1000][1000];
int s[1000][1000];
int mcm(int p[],int i,int j)
{
	int min=INT_MAX,temp,k;
	if(dp[i][j]==-1)
	{
		if(i==j)
		dp[i][j]=0;
		else
		{
			for(k=i;k<j;k++)
			{
				temp=mcm(p,i,k)+mcm(p,k+1,j)+p[i]*p[k+1]*p[j+1];
				if(temp<min)
				{
					min=temp;
					s[i][j]=k;
				}
			}
			dp[i][j]=min;
		}
	}
	return dp[i][j];
}
void parsz(int i,int j)
{
	if(i==j)
	printf(" A%d ",i);
	else
	{
		printf("(");
		parsz(i,s[i][j]);
		parsz(s[i][j]+1,j);
		printf(")");
	}
}
int main()
{
	int p[10000],n,i,j;
	printf("Enter the number of matrices\n");
	scanf("%d",&n);
	
	for(i=1;i<=n+1;i++)
	scanf("%d",&p[i]);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		dp[i][j]=-1;
	}
	
	printf("%d\n",mcm(p,1,n));
	parsz(1,n);
	return 0;	
}
