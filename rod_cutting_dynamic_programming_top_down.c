#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void memoized_rod_cut(int *,int *,int);
int memoized_rod_cut_aux(int *,int *,int);
int main()
{
	int i,*price,*revenue,n;
	printf("Enter the length of the rod\n");
	scanf("%d",&n);
	price=(int *)malloc((n+1)*sizeof(int));
	revenue=(int *)malloc((n+1)*sizeof(int));
	price[0]=0;
	for(i=0;i<=n;i++)
		revenue[i]=INT_MIN;
	for(i=1;i<=n;i++)
	{
		printf("Enter the cost of rod of length %d\n",i);
		scanf("%d",&price[i]);
	}
	memoized_rod_cut(price,revenue,n);
	return 0;
}
void memoized_rod_cut(int *price,int *revenue,int n)
{
	int i;
	for(i=0;i<=n;i++)
		revenue[i]=INT_MIN;
	printf("The maximum revenue that can be earned is %d\n",memoized_rod_cut_aux(price,revenue,n));
	printf("revenue is...\n");
	for(i=0;i<=n;i++)
		printf("%d ",revenue[i]);
}
int memoized_rod_cut_aux(int *price,int *revenue,int n)
{
	if(revenue[n]>=0)
		return revenue[n];
	if(n==0)
		revenue[n]=0;
	else
	{
		int temp,i;
		revenue[n]=INT_MIN;
		for(i=1;i<=n;i++)
		{
			int temp=price[i]+memoized_rod_cut_aux(price,revenue,n-i);;
			if(temp>revenue[n])
				revenue[n]=temp;
		}
	}
	return revenue[n];
}
