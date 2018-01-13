#include<iostream>
using namespace std;
int a[1024],n;
int maxo(int x,int b,int c)
{
	int max=x>b?x:b;
	max=max>c?max:c;
	return max;
}
int maxprofit(int start,int end)
{
	int lstart,rstart,max1,max2,max3;
	if(start==end)
	return a[start];
	else
	{
		int mid=(end+start)/2;
		int sum1=INT_MIN;
		int k=mid,max=0;
		lstart=k;
		while(k>=start)
		{
			max=max+a[k];
			if(max>sum1)
			{	
				sum1=max;
				lstart=k;
			}
		k--;
		}
		cout<<"\n lsum"<<sum1;		
		int sum2=INT_MIN;
		k=mid+1,max=0;
		rstart=k;
		while(k<=end)
		{
			max=max+a[k];
			if(max>sum2)
			{	
				sum2=max;
				rstart=k;
			}
			k++;
		}
		cout<<"\n rsum"<<sum2;
		max1=sum1+sum2;
		max2=maxprofit(start,mid);
		max3=maxprofit(mid+1,end);
		return(maxo(max1,max2,max3));
	}
}
int main()
{

	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<"\n max profit is "<<maxprofit(0,n-1);
}
