#include<bits/stdc++.h>
using namespace std;
bool mark[5000006];
unsigned long long ans[5000006],s;

void init(int n)
{
    int i,j;

    for(i = 1; i <= n; i++)
    {
        s = i;
        ans[i] = s;
    }
    ans[1] = 0;
    mark[1] = true;

    for(i = 2; i <= n ; i++)
    {
        if(!mark[i])
        {
            for(j = i; j <= n; j += i)
            {
                mark[j] = true;
                s = i;
                ans[j] = ans[j] / s * (s - 1);
            }
        }
    }
}

void solve(int n)
{
    unsigned long long sum = 0;
    for(int i = 2; i <= n; i++)
    {
         sum += (ans[i] * ans[i]);
         ans[i] = sum;
    }
}

int main()
{
    init(5000000);
    solve(5000000);
    int testCases,a,b;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %llu\n",test,ans[b] - ans[a-1]);
    }
    return 0;
}
