#include<bits/stdc++.h>
using namespace std;
int dist[30004],n;
bool visited[30004];

int bfs(vector<pair<int,int> > adj[],int src)
{
    queue<pair<int,int> > q;
    q.push(make_pair(src,0));
    memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));
    visited[src] = true;

    while(!q.empty())
    {
        int u = q.front().first;
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(!visited[v])
            {
                dist[v] = dist[u] + w;
                q.push(make_pair(v,dist[v]));
                visited[v] = true;
            }
        }
    }

    int idx,maxdis = 0;

    for(int i = 0; i < n; i++)
    {
        if(maxdis < dist[i])
        {
            maxdis = dist[i];
            idx = i;
        }
    }

    return idx;
}

int main()
{
    int testCases;
    scanf("%d",&testCases);

    for(int T = 1; T <= testCases; T++)
    {

        int u,v,w;
        scanf("%d",&n);
        vector<pair<int,int> > adj[n+1];

        for(int i = 1; i < n; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        int farthestNode = bfs(adj,0);
        bfs(adj,farthestNode);
        int ans = 0;

        for(int i = 0; i < n; i++)
            ans = max(ans,dist[i]);

        printf("Case %d: %d\n",T,ans);
    }
    return 0;
}
