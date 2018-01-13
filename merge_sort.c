#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void merge_sort(int *,int,int);
void merge(int *,int,int,int);
int main()
{
	int n,*arr,i;
	printf("Enter the number of elements you want to sort\n");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	merge_sort(arr,0,n-1);
	printf("Elements after sorting are...\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
void merge_sort(int *arr,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
void merge(int *arr,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *left,*right,i,j,k;
	left=(int *)malloc((n1+1)*sizeof(int));
	right=(int *)malloc((n2+1)*sizeof(int));
	for(i=0;i<n1;i++)
		left[i]=arr[p+i];
	for(i=0;i<n2;i++)
		right[i]=arr[q+i+1];
	left[n1]=INT_MAX;
	right[n2]=INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
	}
}
