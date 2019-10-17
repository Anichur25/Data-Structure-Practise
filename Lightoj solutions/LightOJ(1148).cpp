#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[50],cnt[50],n,testCases;
    long long ans;
    bool visited[50];
    scanf("%d",&testCases);

    for(int test = 1; test <= testCases; test++)
    {
        memset(visited,false,sizeof(visited));
        ans = 0;
        scanf("%d",&n);

        for(int i = 0; i < n; i++)
            scanf("%d",&a[i]),cnt[i] = a[i];

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {

                for(int j = 0; j < n; j++)
                {
                    if(i != j && a[i] == a[j] && cnt[j])
                    {
                        if(cnt[i] >= 1)
                        {
                            cnt[i]--;
                            visited[j] = true;
                            cnt[j] = 0;
                        }
                        else
                            break;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
            ans += cnt[i];
        printf("Case %d: %lld\n",test,ans + n);
    }
    return 0;
}
