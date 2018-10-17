#include<bits/stdc++.h>
using namespace std;

bool visited[101];
int dista[101];
int distb[101];

void BFS(int source,vector<int> adj[],int dist[])
{


    queue<int> q;
    visited[source] = true;
    q.push(source);
    dist[source] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i];
            if(!visited[v])
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }

}


int main()
{
    int caseno,N,R,u,v,mxfar,start,end;
    scanf("%d",&caseno);

    for(int i=1;i<=caseno;i++)
    {
        scanf("%d",&N);
        scanf("%d",&R);
        mxfar = 0;

        vector<int> adj[101];
        bool status[101];
        memset(visited,false,sizeof(visited));
        memset(status,false,sizeof(status));
        for(int k = 0;k<N;k++) dista[k] = 0;

        for(int k = 0;k<N;k++) distb[k] = 0;

        for(int j=0;j<R;j++)
        {
            scanf("%d%d",&u,&v);
            status[u] = status[v] = true;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        scanf("%d%d",&start,&end);

        BFS(start,adj,dista);
        memset(visited,false,sizeof(visited));
        BFS(end,adj,distb);

        for(int k=0;k<N;k++)
        {
            if(status[k])
            {
                mxfar = max(dista[k]+distb[k],mxfar);
            }
        }

        printf("Case %d: %d\n",i,mxfar);
    }

    return 0;
}
