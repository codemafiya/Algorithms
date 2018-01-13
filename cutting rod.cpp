#include<iostream>
#include<algorithm>
using namespace std;
int cutrod(int a[],int n)
{
	int i;
	if(n<=0)
	return 0;
	int max_val=INT_MIN;
	for(i=0;i<n;i++)
	max_val=max(max_val,a[i]+cutrod(a,n-i-1));
	return max_val;
}
int main()
{
	int t,n,i;
	//string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(i=0;i<n;i++)
		cin>>a[i];
		cout<<cutrod(a,n)<<endl;
	}
	return 0;
}
