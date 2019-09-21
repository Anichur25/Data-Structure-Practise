#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
map<int,int> Indegree,mapping;
set<int> nodes;
int root,cnt = 0,reachable,Tnodes;
bool Istatus,visited[N];
vector<int> adj[N];

void solve()
{
   map<int,int> :: iterator it;

   for(it = Indegree.begin(); it != Indegree.end(); it++)
   {
       if(it -> second == 0) root = it -> first,++cnt;
       else if(it -> second > 1)
       {
           Istatus = true;
           return;
       }
   }
}

void dfs(int root)
{
    if(!visited[root])
    {
        visited[root] = true;
        ++reachable;

        for(int i = 0; i < adj[root].size(); i++)
        {
            if(!visited[adj[root][i]])
            {
                dfs(adj[root][i]);
            }
        }
    }
}

void init()
{
    Indegree.clear();
    mapping.clear();
    Istatus = false;
    cnt = 0;
    reachable = 0;
    Tnodes = 0;
    for(int i = 0; i < 10000; i++)
    {
        adj[i].clear();
        visited[i] = false;
    }
}
int main()
{
   int testCases = 0;
   int u,v;

   while(scanf("%d %d",&u,&v))
   {
      ++testCases;
      init();
      if(u == 0 && v == 0)
      {
          printf("Case %d is a tree.\n",testCases);
          continue;
      }
      else if(u < 0 && v < 0)
        break;
      else
      {
          if(mapping.find(u) == mapping.end())
              ++Tnodes,mapping[u] = Tnodes;
          if(mapping.find(v) == mapping.end())
              ++Tnodes,mapping[v] = Tnodes;


          Indegree[mapping[v]]++;
          Indegree[mapping[u]];
          int mpu = mapping[u];
          int mpv = mapping[v];
          adj[mpu].push_back(mpv);

          while(scanf("%d %d",&u,&v) && u && v)
          {
              if(mapping.find(u) == mapping.end())
              ++Tnodes,mapping[u] = Tnodes;
              if(mapping.find(v) == mapping.end())
              ++Tnodes,mapping[v] = Tnodes;

              int mpu = mapping[u];
              int mpv = mapping[v];
              adj[mpu].push_back(mpv);
              Indegree[mpv]++;
              Indegree[mpu];
          }

          solve();

          if(Istatus == true || cnt == 0 || cnt > 1) printf("Case %d is not a tree.\n",testCases);
          else
          {
              dfs(root);
              if(reachable == Tnodes)  printf("Case %d is a tree.\n",testCases);
              else printf("Case %d is not a tree.\n",testCases);
          }
      }
   }
   return 0;
}
