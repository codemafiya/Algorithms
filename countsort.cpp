#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cout<<"enter number of range ";
	cin>>n;
	cout<<" \n enter number of elements";
	cin>>m;
	int i,a[m],b[n]={0};
	
	for(i=0;i<m;i++)
	cin>>a[i];
	
	for(i=0;i<m;i++)
	b[a[i]]++;
	cout<<"\n";
		
	for(i=1;i<n;i++)
	b[i]+=b[i-1];

	int c[m];
	for(i=m-1;i>=0;i--)
	{c[(b[a[i]]--)-1]=a[i];
	}
	cout<<"\n ";
	for(i=0;i<m;i++)
	cout<<c[i]<<"  ";
	
	
	return 0;
}
