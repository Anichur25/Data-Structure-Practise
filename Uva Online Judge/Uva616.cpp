#include<bits/stdc++.h>
using namespace std;

int main()
{
    int coconuts,p,ans,i;

    while(scanf("%d",&coconuts) && coconuts > 0){

        int s = sqrt(coconuts)+1;
        bool sol = false;
        for(int people = s; people >= 2; people--){
             ans = coconuts;
            if(coconuts % people == 1){

                for( i = 1; i <= people; i++){
                    if( ans % people != 1)
                        break;
                    ans = ans - ans / people - 1;
                }

                if(i == people + 1 && ans % people == 0){
                    sol = true;
                    printf("%d coconuts, %d people and 1 monkey\n",coconuts,people);
                    break;
                }
            }
        }

        if(!sol) printf("%d coconuts, no solution\n",coconuts);
    }

    return 0;
}
