#include<bits/stdc++.h>
using namespace std;
int factors[30],ocr[27],slen,total;
long long ways,ans = 0;

void solve(int n,bool flag,bool op)
{

    if(n == 1)
    {
        factors[1] = 1;
        return;
    }
    int low;
    low = (flag)? 2 : n;

    for(int number = low; number <= n; number++)
    {
        int x = number;
        for(int fa = 2; fa * fa <= x; fa++)
        {
            while(x % fa == 0)
            {
                factors[fa] += (op)? 1 : -1;
                x /= fa;
            }
        }

        if(x != 1)
            factors[x] += (op)? 1 : -1;
    }
}

void CalWays()
{
    ways = 0;
    for(int i = 1; i <= 29; i++)
    {
        if(factors[i] != 0)
        {
            if(ways == 0)
                ways = 1;
            ways *= pow((double)i,(double)factors[i]);
        }
    }
    ans += ways;
}

int main()
{
    char str[36];

    while(scanf("%s",str) && str[0] != '#')
    {
        memset(ocr,0,sizeof(ocr));
        slen = strlen(str);
        total = slen;
        ans = 0;

        for(int i = 0; i < slen; i++)
            ocr[str[i]-'a']++;

        for(int i = 0; i < slen-1; i++)
        {
            memset(factors,0,sizeof(factors));
            --total;
            int sum = 0;
            for(int j = 0; j < str[i]-'a'; j++)
                sum += ocr[j];
            if(sum >= 1)
                solve(sum,false,true);
            if(sum != 0)
                solve(total,true,true);

            for(int k = 0; k < 26; k++)
            {
                if(ocr[k] > 1)
                    solve(ocr[k],true,false);
            }
            CalWays();
            ocr[str[i]-'a']--;
        }

        printf("%10lld\n",ans+1);
    }
    return 0;
}
