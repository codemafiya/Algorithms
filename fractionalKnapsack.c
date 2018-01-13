#include<stdio.h>

typedef struct Item
{
	int no;
	float value;
	float weight;
	float ratio;
}Item;

void fractionalKnapsack(Item arr[],int n,int wt);
void buildMaxHeap(Item a[],int n);
void heapSort(Item a[],int n);
void heapify(Item a[],int n,int i);
void swap(Item *a,Item *b);
void printSolution(int res[],int n,float frac,float profit);

int main()
{
	int wt,n,i;
	printf("Enter the maximum weight limit: ");
	scanf("%d",&wt);
	printf("Enter the number of items: ");
	scanf("%d",&n);
	Item arr[n+1];
	printf("Enter the value and weight of each item:\n");
	for(i=1;i<=n;i++)
	{
		arr[i].no=i;
		scanf("%f%f",&arr[i].value,&arr[i].weight);
	}
	fractionalKnapsack(arr,n,wt);
	return 0;
}

void fractionalKnapsack(Item arr[],int n,int wt)
{
	int i;
	float profit;
	for(i=1;i<=n;i++)
	{
		arr[i].ratio=(arr[i].value)/(arr[i].weight);
	}
	heapSort(arr,n);
	profit=0;
	i=1;
	int res[n],index=0;
	float frac;
	while(wt>0)
	{
		if(wt>=arr[i].weight)
		{
			wt=wt-arr[i].weight;
			profit+=arr[i].value;
			res[index++]=arr[i].no;
			i++;
		}
		else
		{
			profit+=(arr[i].ratio)*wt;
			res[index++]=arr[i].no;
			frac=wt/(arr[i].weight);
			break;
		}
	}
	printSolution(res,index,frac,profit);
}

void buildMaxHeap(Item a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapify(a,n,i);
	}
}

void heapSort(Item a[],int n)
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

void heapify(Item a[],int n,int i)
{
	int min;
	int lchild=2*i;
	int rchild=(2*i)+1;
	if((lchild<=n)&&(a[lchild].ratio<a[i].ratio))
		min=lchild;
	else
		min=i;
	if((rchild<=n)&&(a[rchild].ratio<a[min].ratio))
		min=rchild;
	if(min!=i)
	{
		swap(&a[min],&a[i]);
		heapify(a,n,min);
	}
}

void swap(Item *a,Item *b)
{
	Item temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printSolution(int res[],int n,float frac,float profit)
{
	printf("Items numbers for maximum profit:\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",res[i]);
	}
	printf("\nFraction of last item taken: %f\n",frac);
	printf("Maximum Profit: %f\n",profit);
}
