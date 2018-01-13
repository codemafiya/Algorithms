#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll f,s,de,u,d,m;
ll vis[1000001];
ll dist[1000001];

void bfs()
{
    ll cur,nextu,nextd;
    queue<ll> q;
    vis[s]=1;
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        cur= q.front();
        q.pop();
        nextu=cur+u;
        nextd=cur-d;
        if(nextu<=f&&!vis[nextu])
        {
            vis[nextu]=1;
            dist[nextu]=dist[cur]+1;
            q.push(nextu);
        }
        if(nextd>=1&&!vis[nextd])
        {
            vis[nextd]=1;
            dist[nextd]=dist[cur]+1;
            q.push(nextd);
        }
    }
}

int main()
{
    cin>>f>>s>>de>>u>>d;
    dist[de]=-1;
    bfs();
    if(dist[de]==-1)
    {
        cout<<"use the stairs";
    }
    else
    {
        cout<<dist[de];
    }
    return 0;

}
