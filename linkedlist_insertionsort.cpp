#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *link;
};
struct node* create(int);
void display(struct node *);
struct node* insertionSort(struct node *);
int main()
{
	int n;
	printf("Enter the number of entries in the list\n");
	scanf("%d",&n);
	struct node *first,*temp;
	first=create(n);
	temp=first;
	display(temp);
	temp=first;
	first=insertionSort(temp);
	temp=first;
	display(temp);
	return 0;
}
struct node* create(int n)
{
	int i;
	struct node *temp,*temp2,*first;
	first=(struct node *)malloc(sizeof(struct node));
	printf("Enter the value\n");
	scanf("%d",&first->val);
	temp=first;
	for(i=1;i<n;i++)
	{
		temp2=(struct node *)malloc(sizeof(struct node));
		printf("Enter the value\n");
		scanf("%d",&temp2->val);
		temp->link=temp2;
		temp=temp2;
	}
	temp->link=NULL;
	return first;
}
void display(struct node *first)
{
	struct node *temp=first;
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->link;
	}
	printf("\n");
}
struct node* insertionSort(struct node *first)
{
	if(!first)
		return first;
	struct node *pre,*temp,*search,*start;
	search=first;
	int flag;
	while(search->link!=NULL)
	{
		struct node *insertnode;
		pre=NULL;
		start=first;
		temp=(struct node *)malloc(sizeof(struct node));
		insertnode=search->link;
		temp->val=insertnode->val;
		flag=0;
		while(start!=insertnode)
		{
			if(start->val>temp->val)
			{
				if(start==first)
				{
					temp->link=first;
					first=temp;
				}
				else
				{
					temp->link=start;
					pre->link=temp;
				}
				search->link=insertnode->link;
				free(insertnode);
				flag=1;
				break ;
			}
			pre=start;
			start=start->link;
		}
		if(flag==0)
			search=search->link;
	}
	return first;
}
