#include<bits/stdc++.h>
using namespace std;

int factorize(long long n,long long factor)
{
    int counter = 0;

    while(n % factor == 0)
    {
        ++counter;
        n /= factor;
    }

    return counter;
}

int main()
{
    long long a,b,L,LCM,C;
    int cases;

    scanf("%d",&cases);

    for(int c = 1; c <= cases; c++)
    {
        C = 1;

        scanf("%lld%lld%lld",&a,&b,&L);

        LCM = (a * b) / __gcd(a,b);

        printf("Case %d: ",c);

        if(L % LCM != 0)
        {
            printf("impossible\n");
            continue;
        }


        int limit = sqrt(L);

        for(long long i = 2; i <= limit; i++)
        {
            int counter = 0;
            long long save = 1;

            while(L % i == 0)
            {
                counter++;
                L /= i;
                save *= i;
            }

            if(counter != 0)
            {
                int res = factorize(LCM,i);

                if(counter > res)
                    C *= save;

            }
        }

        if(L != 1)
        {
            int res = factorize(LCM,L);

            if(res == 0)
                C *= L;
        }

        printf("%lld\n",C);
    }
    return 0;
}
