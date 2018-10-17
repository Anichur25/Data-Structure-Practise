#include<bits/stdc++.h>
using namespace std;

int main()
{

    long long factor;
    int cases;
    int case_no = 0;

    scanf("%d",&cases);

    while(cases--)
    {

        scanf("%lld",&factor);

        printf("Case %d: ",++case_no);

        if(factor % 2 != 0)
            printf("Impossible\n");
        else
        {
            for(long long i = 2; i <= factor; i+=2)
            {
                if(factor % i == 0)
                {
                    if((factor / i) % 2)
                    {
                        printf("%lld %lld\n",factor / i, i);
                        break;
                    }
                }
            }
        }

    }

    return 0;
}
