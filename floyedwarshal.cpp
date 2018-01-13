#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll point[n][n];
	ll k,i,a,b,j,x;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			point[i][j]=0;
			else
			point[i][j]=INT_MAX;
		}
	}
	cin>>k;
	for(i=0;i<k;i++)
	{
		cin>>a>>b>>x;
		point[a][b]=x;
			
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(point[i][k]!=INT_MAX&&point[k][j]!=INT_MAX&&point[i][k]+point[k][j]<point[i][j])
				{
					point[i][j]=point[i][k]+point[k][j];
				}	
			}	
		}	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(point[i][j]==INT_MAX)
			cout<<-1;
			else
			cout<<point[i][j];
			cout<<"    ";	
		}
		cout<<endl;	
	}
	return 0;	
}
