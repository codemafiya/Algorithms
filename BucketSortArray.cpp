#include<stdio.h>
#include<stdlib.h>

void insertion(float *arr,float item,int len)
{
    if(len==0||arr[len-1]<=item)
        arr[len] = item;
    else
        for(int i=0;i<len;i++)
        {
            if(arr[i]>item)
            {
                for(int j=len+1;j>=i+1;j--)
                    arr[j] = arr[j-1];
                arr[i] = item;
            }
        }
}

float* BucketSort(float *arr,int n,float Max)
{
    int k = 10;
	float bsize = (Max)/k;
	float Bucket[10][20];
	int len[10];
	for(int i=0;i<k;i++)
        len[i]=0;
    for(int i=0;i<n;i++)
    {
        int B_No = (int)(arr[i]/bsize);
        insertion(Bucket[B_No],arr[i],len[B_No]);
        len[B_No]++;
    }
    int p=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<len[i];j++)
            arr[p++] = Bucket[i][j];
    }
    return arr;
}

int main()
{
	int n;
	float Max;
	printf("Enter no. of elements : ");
	scanf("%d",&n);
	printf("Enter the max range : ");
	scanf("%f",&Max);
	float *arr = (float*)malloc((n+1)*sizeof(float));
	for(int i=0;i<n;i++)
	{
		scanf("%f",&arr[i]);
	}
	printf("Before Sorting :\n");
	for(int i=0;i<n;i++)
		printf("%f ",arr[i]);
	BucketSort(arr,n,Max);
	printf("\nAfter Sorting :\n");
	for(int i=0;i<n;i++)
		printf("%f ",arr[i]);
	return 0;
}
