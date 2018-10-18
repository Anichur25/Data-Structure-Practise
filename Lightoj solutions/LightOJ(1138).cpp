#include<bits/stdc++.h>
using namespace std;

long long solve(long long low,long long high,int required)
{
    if(low <= high)
    {
        long long mid = (low + high) / 2;
        long long value = mid;

        int ans = 0;
        long long mul = 1;

        while(true)
        {
            mul *= 5;
            ans += (value / mul);
            if(value / mul == 0)
                break;
        }

        if(ans == required)
            return mid;
        else if(ans > required)
        {
            return solve(low,mid - 1,required);
        }

        else
            return solve(mid + 1,high,required);
    }

    return -1;
}

int main()
{
    int required;
    int cases;
    scanf("%d",&cases);

    for(int i = 1; i <= cases; i++)
    {
        scanf("%d",&required);

        long long ans = solve(5,5 * required,required);

        printf("Case %d: ",i);

        if(ans == -1)
            printf("impossible\n");
        else
            printf("%lld\n",ans - (ans % 5));
    }
    return 0;
}
