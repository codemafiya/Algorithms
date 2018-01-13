#include<iostream>
using namespace std;
int lis(int a[],int n)
{
	int l[n];

	int max=0,i,j;
	for(i=0;i<n;i++)
	l[i]=1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j-1]<=a[j])
			l[i]++;
			else 
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		if(max<l[i])
		max=l[i];
	}
	return max;
}
int main()
{
	int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<lis(a,n);
	}
	return 0;	
}
