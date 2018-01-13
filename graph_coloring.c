#include<stdio.h>
int x[1000],n,c;
int graph[10][10];
void color(int k)
{
	int i,j;
	for(i=1;i<=c;i++)
	{
		if(check(k,i)==1)
		{
			x[k]=i;
			if(k==n)
			{
				for(j=1;j<=n;j++)
				{
					printf("%d:%d\n",j,x[j]);
				}
				printf("\n");
			}
			else
			color(k+1);
		}
	}
}
int check(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if((graph[j][k]!=0)&&(i==x[j]))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int i,j;
	scanf("%d",&c);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	color(1);
	return 0;
}
