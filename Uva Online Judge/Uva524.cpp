#include<bits/stdc++.h>
using namespace std;
bool prime[32],visited[17];
int seq[17],n;

void init()
{
    prime[2] = prime[3] = prime[5] = true;
    prime[7] = prime[11] = prime[13] = true;
    prime[17] = prime[19] = prime[23] = true;
    prime[29] = prime[31] = true;
}

void solve(int idx)
{
    if(idx == n + 1 && prime[seq[n] + seq[1]])
    {
        bool space = false;

        for(int i = 1; i <= n; i++)
        {
            if(space) printf(" ");
            space = true;
            printf("%d",seq[i]);
        }
        printf("\n");
        return;
    }

    for(int i = 2; i <= n; i++)
    {
        if(!visited[i])
        {
            if(prime[seq[idx-1] + i] == true)
            {
                visited[i] = true;
                seq[idx] = i;
                solve(idx + 1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    init();
    int Cases = 0;

    while(scanf("%d",&n) != EOF)
    {
        ++Cases;
        if(Cases > 1) printf("\n");
        printf("Case %d:\n",Cases);
        memset(visited,false,sizeof(visited));
        seq[1] = 1;
        solve(2);
    }
    return 0;
}
