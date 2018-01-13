#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void print_cut_rod_solution(int *,int *,int *,int);
void rod_cut(int *,int *,int *,int);
int main()
{
	int i,*price,*revenue,*size,n;
	printf("Enter the length of the rod\n");
	scanf("%d",&n);
	price=(int *)malloc((n+1)*sizeof(int));
	revenue=(int *)malloc((n+1)*sizeof(int));
	size=(int *)malloc((n+1)*sizeof(int));
	price[0]=0;
	revenue[0]=0;
	for(i=1;i<=n;i++)
	{
		printf("Enter the cost of rod of length %d\n",i);
		scanf("%d",&price[i]);
	}
	print_cut_rod_solution(price,revenue,size,n);
	return 0;
}
void print_cut_rod_solution(int *price,int *revenue,int *size,int n)
{
	rod_cut(price,revenue,size,n);
	printf("The maximum revenue is %d\nFor this, the rod should be cut at the following points...\n",revenue[n]);
	while(n>0)
	{
		printf("%d ",size[n]);
		n-=size[n];
	}
}
void rod_cut(int *price,int *revenue,int *size,int n)
{
	int i,j,q;
	for(i=1;i<=n;i++)
	{
		q=INT_MIN;
		for(j=1;j<=i;j++)
		{
			if(q<price[j]+revenue[i-j])
			{
				q=price[j]+revenue[i-j];
				size[i]=j;
			}
		}
		revenue[i]=q;
	}
}
