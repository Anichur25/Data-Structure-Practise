#include<bits/stdc++.h>
using namespace std;
bool visited[10000002];
int p[664586],len;
void seive(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(!visited[i])
        {
            for(int j = 2 * i; j <= n; j += i)
             visited[j] = true;
        }
    }

    p[0] = 2;
    int idx = 1;
    for(int i = 3; i <= n; i += 2)
    {
        if(!visited[i])
        p[idx++] = i;
    }
    len = idx;
}

long long solve(long long n)
{
    int cnt = 0;
    long long ans = 1;


   for(int idx = 0; idx < len && p[idx] * p[idx] <= n; idx++)
    {
        cnt = 0;
        while(n % p[idx] == 0)
        {
            n /= p[idx];
            ++cnt;
        }

        if(cnt != 0 && p[idx] != 2) ans *= (cnt + 1);
    }

    if(n > 1 && n != 2) ans *= 2;
   return ans - 1;
}
int main()
{
    long long n;
    int testCases;
    long long ans;
    seive(10000000);
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%lld",&n);
        ans = solve(n);
        printf("Case %d: %lld\n",test,ans);
    }

    return 0;
}
