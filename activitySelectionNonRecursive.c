#include<stdio.h>

typedef struct Activity
{
	int number,start,finish;
}Activity;

void activitySelection(Activity a[],int n);
void printSolution(int a[],int n,int count);
void buildMaxHeap(Activity a[],int n);
void heapSort(Activity a[],int n);
void heapify(Activity a[],int n,int i);
void swap(Activity *a,Activity *b);

int main()
{
	int n,i;
	printf("Enter the number of activities: ");
	scanf("%d",&n);
	Activity a[n+1];
	printf("Enter starting and finishing time of each activity:\n");
	for(i=1;i<=n;i++)
	{
		a[i].number=i;
		scanf("%d%d",&a[i].start,&a[i].finish);
	}
	activitySelection(a,n);
	return 0;
}

void activitySelection(Activity a[],int n)
{
	heapSort(a,n);
	int res[n],index=0;
	res[index]=a[1].number;
	index++;
	int m=1,count=1,i;
	for(i=2;i<=n;i++)
	{
		if(a[i].start>=a[m].finish)
		{
			res[index++]=a[i].number;
			m=i;
			count++;
		}
	}
	printSolution(res,index,count);
}

void printSolution(int a[],int n,int count)
{
	printf("Selected activities:\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nNumber of activities selected: %d",count);
}

void buildMaxHeap(Activity a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapify(a,n,i);
	}
}

void heapSort(Activity a[],int n)
{
	buildMaxHeap(a,n);
	int i;
	for(i=n;i>=2;i--)
	{
		swap(&a[1],&a[n]);
		n--;
		heapify(a,n,1);
	}
}

void heapify(Activity a[],int n,int i)
{
	int maximum;
	int lchild=2*i;
	int rchild=(2*i)+1;
	if((lchild<=n)&&(a[lchild].finish>a[i].finish))
		maximum=lchild;
	else
		maximum=i;
	if((rchild<=n)&&(a[rchild].finish>a[maximum].finish))
		maximum=rchild;
	if(maximum!=i)
	{
		swap(&a[maximum],&a[i]);
		heapify(a,n,maximum);
	}
}

void swap(Activity *a,Activity *b)
{
	Activity temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
