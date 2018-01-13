#include<stdio.h>

int knapsack01(int value[],int w[],int n,int wt);
int max(int a,int b);

int main()
{
	int wt,n,i;
	printf("Enter the maximum weight limit: ");
	scanf("%d",&wt);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	int value[n],w[n];
	printf("Enter the value of each item:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&value[i]);
	}
	printf("Enter the weight of each item:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	int maxProfit=knapsack01(value,w,n,wt);
	printf("Maximum possible profit: %d",maxProfit);
	return 0;
}

int knapsack01(int value[],int w[],int n,int wt)
{
	if(n==0||wt==0)
		return 0;
	if(wt>=w[n-1])
		return max(knapsack01(value,w,n-1,wt),value[n-1]+knapsack01(value,w,n-1,wt-w[n-1]));
	else
		return knapsack01(value,w,n-1,wt);
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
