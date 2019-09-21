#include<bits/stdc++.h>
using namespace std;
bool visited[550],mark[5001];
int primes[103],cnt = 1;

void seive(int n)
{
    for(int i = 2; i * i <= n; i ++){
        if(!visited[i]){
            for(int j = 2 * i; j <= n; j += i)
                visited[j] = true;
        }
    }
    primes[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            primes[cnt] = i;
            if(cnt == 100)
              break;
        }
    }
}

int bfs(int n,int q){

    int dist[q+1];
    memset(mark,false,sizeof(mark));
    dist[0] = 0;
    mark[0] = true;
    queue<int> Q;
    Q.push(0);

    while(!Q.empty()){

        int u = Q.front();
        Q.pop();
        if(u == q)
         return dist[q];

        for(int i = 1; i <= n; i++){
            int sum = primes[i] + u;
            if(sum <= q && !mark[sum]){
                mark[sum] = true;
                dist[sum] = dist[u] + 1;
                Q.push(sum);
            }
        }
    }

   return 0;
}
int main()
{
  seive(550);
  int n;

  scanf("%d",&n);

  while(n--){
    int area,score;
    scanf("%d %d",&area,&score);
    printf("%d\n",bfs(area,score));
  }

  return 0;
}
