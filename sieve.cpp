#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool a[100];
void sieve()
{
	
	memset(a,true,sizeof(a));
	ll i,j;
	for(i=2;i*i<=100;i++)
	{
		if(a[i]==true)
		{
			for(j=2*i;j<=100;j=j+i)
			{
				a[j]=false;	
			}	
		}
	}
	
}
int main()
{
	sieve();
	ll i;
	for(i=0;i<100;i++)
	{
		if(a[i])
		cout<<i<<" ";	
	}
}
