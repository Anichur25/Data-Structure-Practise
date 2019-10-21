#include<bits/stdc++.h>
using namespace std;

int bigMod(int a,int b,int M)
{
    if(b == 0) return 1 % M;
    int x = bigMod(a,b/2,M);
    x = (x * x) % M;
    if(b % 2 == 1) x = (x * a) % M;
    return x;
}


int main()
{
    int testCases,n,k,M,mod,loop;
    long long number,sum,MOD,ans;

    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        scanf("%d %d %d",&n,&k,&M);
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&number);
            sum += number;
        }

        MOD = M;
        ans = (bigMod(n,k-1,M) * (k % M)) % MOD;
        ans  = ans % MOD;
        sum  = sum % MOD;
        ans = (sum * ans) % MOD;
        printf("Case %d: %lld\n",test,ans);
    }
    return 0;
}
