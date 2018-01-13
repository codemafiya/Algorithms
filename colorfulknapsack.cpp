#include <bits/stdc++.h>
using namespace std;

short color[101] = {0};
int K(int W[],int C[],int n,int w)
{
    int c = C[n-1];
    if(n == 0)
        return 0;
    int opt1=0,opt2=0;
    
    if(w >= W[n-1])
    {
        if(color[c] == 0)
        {
            color[c] = 1;
            opt1 = K(W,C,n-1,w-W[n-1])+W[n-1];
            color[c] = 0;
        }

    }
    
    opt2 = K(W,C,n-1,w);
    if(opt1 > opt2)
    {
        color[c] = 1;
        return opt1;
    }
    else
        return opt2;
}

void Knapsack(int W[],int C[],int n,int w,int m)
{
    int flag = 0;
    int max = K(W,C,n,w);
    for(int i =1;i<=m;i++)
    {
        if(color[i] == 0)
            {
                flag = 1;
                break;
            }
    }
    printf("\n");
    if(flag == 1)
        cout << -1 << "\n";
        else
    printf("%d %d ",max,w-max);
    
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		int W[n];
		int C[n];
	int i;
		for(i=0;i<n;i++)
		{
			cin>>W[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>C[i];
		}
		memset(color,0,sizeof(color));
		Knapsack(W,C,n,x,m);
	}
	return 0;
}
