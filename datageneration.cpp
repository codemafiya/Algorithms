#include<bits/stdc++.h>
#include<sstream>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	ll a[n][21];
	ll pin[1000];
	ll i;
	ll syscode[]={101,102,103,104,105};
	string fname[n];
	ll k=1,j;
	for(i='A';i<='Z';i++)
	{
		for(j=i+1;j<='Z';j++)
		{
			fname[k++]=to_string(i)+to_string(j);
		}
	}
	for(i=1;i<=k;i++)
	cout<<fname[i]<<endl;
	for(i=1;i<=999;i++)
	{
		if(i<100)
		pin[i]=i*1000;
		else
		pin[i]=i*100;
	}
	for(i=1;i<1000;i++)
	cout<<pin[i]<<"  ";
	return 0;
}
