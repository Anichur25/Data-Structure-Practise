#include<bits/stdc++.h>
using namespace std;
int colors[20005];

int bfs(vector<int> adj[],int src)
{

    queue<int> q;
    q.push(src);
    colors[src] = 1;
    int lykans,vampires;
    lykans = vampires = 0;
    ++vampires;

    while(!q.empty())
    {

        int u = q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];


            if(colors[v] == 0)
            {
                q.push(v);
                if(colors[u] == 1)
                {
                    colors[v] = 2;
                    lykans++;
                }
                else
                {
                    colors[v] = 1;
                    vampires++;
                }
            }
        }
    }

    return max(lykans,vampires);

}
int main()
{
   int testCases,N,u,v,ans;

   scanf("%d",&testCases);

   for(int T = 1; T <= testCases; T++)
   {
       scanf("%d",&N);
       vector<int> adj[20005];
       ans = 0;
       memset(colors,0,sizeof(colors));

       for(int i = 1; i <= N; i++)
       {
           scanf("%d %d",&u,&v);
           adj[u].push_back(v);
           adj[v].push_back(u);
       }


       for(int i = 1; i <= 20000; i++)
       {
           if(adj[i].size() && colors[i] == 0)
           {
               ans += bfs(adj,i);
           }
       }

       printf("Case %d: %d\n",T,ans);
   }

   return 0;
}
