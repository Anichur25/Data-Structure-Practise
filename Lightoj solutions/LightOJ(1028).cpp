#include<bits/stdc++.h>
using namespace std;
bool mark[1000006];
int primes[78500];
int N = 78498;

void seive(int n)
{
    int cnt = 0;
    for(int i = 2; i * i <= n; i++)
        if(!mark[i])
            for(int j = 2 * i; j <= n; j += i)
                mark[j] = true;

   for(int i = 2; i <= n; i++)
       if(!mark[i]) primes[cnt] = i,++cnt;

}

long long solve(long long n)
{
    long long ans = 1;
    int cnt = 0;

    for(int i = 0; i < N; i++)
    {
        cnt = 0;
        long long x = primes[i];
        if((x * x) > n)
         break;

        while(n % x == 0)
        {
            n /= x;
            ++cnt;
        }
        ans *= (cnt + 1);
    }

    if(n != 1) ans *= 2;
   return ans - 1;
}

int main()
{
    long long n;
    seive(1000000);
    int testCases;
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",test,solve(n));
    }

    return 0;
}
