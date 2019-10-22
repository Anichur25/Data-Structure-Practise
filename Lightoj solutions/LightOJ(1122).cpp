#include<bits/stdc++.h>
using namespace std;
int a[10],d[10],ans,m,n;

int Abs(int x)
{
    if(x < 0) return -x;
    else return x;
}
void solve(int idx)
{
    if(idx == n)
    {
        ++ans;
        return;
    }

    for(int i = 0; i < m; i++)
    {
        if(idx > 0)
        {
            if(Abs(a[i] - d[idx-1]) <= 2)
            {
                d[idx] = a[i];
                solve(idx+1);
            }
        }
        else
        {
            d[idx] = a[i];
            solve(idx+1);
        }
    }
}

int main()
{
    int testCases;
    scanf("%d",&testCases);

    for(int t = 1; t <= testCases; t++)
    {
        scanf("%d %d",&m,&n);
        for(int i = 0; i < m; i++) scanf("%d",&a[i]);
        ans = 0;
        solve(0);
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
