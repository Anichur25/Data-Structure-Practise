#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,testCaes;

    scanf("%d",&testCaes);

    for(int Case = 1; Case <= testCaes; Case++)
    {
        scanf("%d",&n);
        int arr[n+1],diff;
        arr[0] = 0;
        int maxK = 0,ans;

        for(int i = 1; i <= n; i++)
            scanf("%d",&arr[i]);

        for(int i = 1; i <= n; i++)
        {
            diff = arr[i] - arr[i-1];
            maxK = max(diff,maxK);
        }

        ans = maxK;

        for(int i = 1; i <= n; i++)
        {

            diff = arr[i] - arr[i-1];
            if(diff == maxK)
                --maxK;
            else if(diff > maxK)
            {
                ++ans;
                break;
            }
        }

        printf("Case %d: %d\n",Case,ans);
    }
    return 0;
}
