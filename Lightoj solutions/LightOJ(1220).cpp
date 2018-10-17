#include<bits/stdc++.h>
using namespace std;

long long solve(long long n)
{
    bool sign = false;

    if(n < 0)
    {
        sign = true;
        n = -n;
    }
    long long ans,trail;
    long long sqr = sqrt(n);

    for(long long i = 2; i <= sqr; i++)
    {
        ans = 0;
        trail = n;

        while(trail % i == 0)
        {
            ++ans;
            trail /= i;
        }

        if(trail == 1)
        {
            if(!sign || ans % 2)
                return ans;
        }
    }

    return 1;
}

int main()
{
    int cases;
    long long n;

    scanf("%d",&cases);

    for(int i = 1; i <= cases; i++)
    {
        scanf("%lld",&n);
        printf("Case %d: %d\n",i,solve(n));
    }

    return 0;
}
