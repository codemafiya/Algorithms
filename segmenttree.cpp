#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int tree[400400];
int arr[100100];
void build(int node, int a, int b)
{
    if(b<a)
        return ;
    if(a==b){
		tree[node]=arr[a];
        return;
    }
    build(node*2+1, a, (a+b)/2);
    build(node*2+2, (a+b)/2+1, b);
	tree[node]=min(tree[2*node],tree[2*node+1]);
	
}
ll query(ll node,ll l,ll r,ll a,ll b)
{
	if(b<a||b<l||a>r)
	return INT_MAX;
	if(l>=a&&r<=b)
	return tree[node];
	ll q1=query(node*2+1,l,(l+r)/2,a,b);
	ll q2=query(node*)
}
int main() 
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	for(int i=0;i<=10;i++)
	cout<<tree[i]<<"  ";
	for(int i=0;i<m;i++){
	int l,r,k;
	scanf("%d%d%d",&l,&r,&k);
	//printf("%d\n",fun(1,1,l,r,k));
		
	}
	return 0;
}  
