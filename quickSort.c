#include<stdio.h>

//Function Prototypes
void quickSortCormen(int a[],int left,int right,int *swapsCormen);
void quickSortHoare(int a[],int left,int right,int *swapsHoare);
void display(int a[],int n);
void swap(int *a,int *b);

//main function
int main()
{
	int n,a[20],i,b[20],swapsCormen=0,swapsHoare=0;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	printf("Before Sorting:\n");
	display(a,n);
	quickSortCormen(a,0,n-1,&swapsCormen);
	printf("After Cormen Quick Sort:\n");
	display(a,n);
	quickSortHoare(b,0,n-1,&swapsHoare);
	printf("After Hoare Quick Sort:\n");
	display(b,n);
	printf("Number of swaps:\nCormen Quick Sort: %d\nHoare Quick Sort:%d",swapsCormen,swapsHoare);
	return 0;
}

//Cormen Quick Sort Algorithm
void quickSortCormen(int a[],int left,int right,int *swapsCormen)
{
	if(left>=right)
	return;
	int i=left-1;
	int j;
	int pivot=right;
	for(j=left;j<right;j++)
	{
		if(a[j]<=a[pivot])
		{
			i++;
			(*swapsCormen)++;
			swap(&a[i],&a[j]);
		}
	}
	int pos=i+1;
	(*swapsCormen)++;
	swap(&a[pos],&a[pivot]);
	quickSortCormen(a,left,pos-1,swapsCormen);
	quickSortCormen(a,pos+1,right,swapsCormen);
}

//Hoare Quick Sort Algorithm
void quickSortHoare(int a[],int left,int right,int *swapsHoare)
{
	if(left>=right)
	   return;
	int pivot,i,j;
	pivot = left;
	i=left;
	j=right+1;
	do
	{
		do
		{
			i++;
		}
		while(a[i]<a[pivot]);
		do
		{
			j--;
		}
		while(a[j]>a[pivot]);
		if(i<j)
		{
			(*swapsHoare)++;
			swap(&a[i],&a[j]);
		}
	}
	while(i<=j);
	(*swapsHoare)++;
	swap(&a[j],&a[pivot]);
	quickSortHoare(a,left,j-1,swapsHoare);
	quickSortHoare(a,j+1,right,swapsHoare);
}

//Function to swap two values
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

//To display the array
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
