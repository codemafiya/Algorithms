#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
	int start;
	int finish;
};
void activity_selection(int *,int *,int,int,struct node *,int *);
void merge(int *,int *,int,int,int);
void merge_sort(int *,int *,int,int);
int main()
{
	int *start,*finish,n,i;
	struct node *ans;
	printf("Enter the number of activities\n");
	scanf("%d",&n);
	start=(int*)malloc(n*sizeof(int));
	finish=(int *)malloc(n*sizeof(int));
	ans=(struct node *)malloc(n*sizeof(struct node));
	for(i=0;i<n;i++)
	{
		printf("Enter the start time and finish time of the %dth activity\n",i+1);
		scanf("%d%d",&start[i],&finish[i]);
	}
	printf("Before sorting...\nstart:  ");
	for(i=0;i<n;i++)
		printf("%d ",start[i]);
	printf("\nfinish: ");
	for(i=0;i<n;i++)
		printf("%d ",finish[i]);
	printf("\n\nAfter sorting...\n");
	merge_sort(start,finish,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",start[i]);
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d ",finish[i]);
	int index=0;
	ans[index].start=start[0];
	ans[index].finish=finish[0];
	activity_selection(start,finish,0,n,ans,&index);
	printf("\nMaximum number of activities that can be selected ara %d\nThe respective activities are\n",index+1);
	for(i=0;i<=index;i++)
		printf("%d ",ans[i].start);
	printf("\n");
	for(i=0;i<=index;i++)
		printf("%d ",ans[i].finish);
	return 0;
}
void activity_selection(int *start,int *finish,int k,int n,struct node *ans,int *index)
{
	int m;
	m=k+1;
	while(m<n && start[m]<finish[k])
		m++;
	if(m<n)
	{
		(*index)++;
		ans[*index].start=start[m];
		ans[*index].finish=finish[m];
		activity_selection(start,finish,m,n,ans,index);
	}
	else
		return;
}
void merge_sort(int *start,int *finish,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(start,finish,p,q);
		merge_sort(start,finish,q+1,r);
		merge(start,finish,p,q,r);
	}
}
void merge(int *start,int *finish,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int *left_start,*right_start,*left_finish,*right_finish,i,j,k;
	left_start=(int *)malloc(n1*sizeof(int));
	right_start=(int *)malloc(n2*sizeof(int));
	for(i=0;i<n1;i++)
		left_start[i]=start[p+i];
	for(i=0;i<n2;i++)
		right_start[i]=start[q+i+1];
	left_finish=(int *)malloc((n1+1)*sizeof(int));
	right_finish=(int *)malloc((n2+1)*sizeof(int));
	for(i=0;i<n1;i++)
		left_finish[i]=finish[p+i];
	for(i=0;i<n2;i++)
		right_finish[i]=finish[q+i+1];
	left_finish[n1]=INT_MAX;
	right_finish[n2]=INT_MAX;
	i=0;
	j=0;
	for(k=p;k<=r;k++)
	{
		if(left_finish[i]<=right_finish[j])
		{
			finish[k]=left_finish[i];
			start[k]=left_start[i];
			i++;
		}
		else
		{
			finish[k]=right_finish[j];
			start[k]=right_start[j];
			j++;
		}
	}
}
