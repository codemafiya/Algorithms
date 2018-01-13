
#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef struct point{
	ll x,y,d;
	
}point;
ll vis[1001][1001];
ll n,m;
char a[1001][1001];
ll dx[]={1,0,-1,0,1,1,-1,-1};
ll dy[]={0,1,0,-1,1,-1,1,-1};
ll bfs(ll i,ll j,ll k,ll l)
{
	memset(vis,-1,sizeof(vis));
	queue<point> q;
	point p;
	p.x=i;
	p.y=j;
	p.d=0;
	q.push(p);
	vis[p.x][p.y]=0;
	ll i1;
	while(!q.empty())
	{
		point p1=q.front();
		q.pop();
		if(p1.x==k&&p1.y==l)
		return p1.d;
		if (p1.d>vis[p1.x][p1.y]||a[p1.x][p1.y]=='X'||vis[p1.x][p1.y]==-1)
            continue;
        for(i1=0;i1<8;i1++)
        {
        	ll nx,ny,j1=1;
        	while(1)
        	{
        		nx=p1.x+dx[i1]*j1;
        		ny=p1.y+dy[i1]*j1;
        		//point p2=
        		if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!='X')
        		{
        			if ((vis[nx][ny]==-1||vis[nx][ny]>p1.d+1))
					{
						point p2;
						p2.x=nx;
						p2.y=ny;
						p2.d=p1.d+1;
                    	q.push(p2);
                    	vis[nx][ny] = p1.d+1;
                    }
                }
                else 
                {
					break;
				}
                j1++;
			}
		}
	}
	return -1;
	
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>m;
		
		ll i,j,sx,sy,fx,fy;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				if(a[i][j]=='F')
				{
					fx=i;
					fy=j;
				}
			}
		}
		cout<<bfs(sx,sy,fx,fy)<<endl;
	}
	return 0;
}
