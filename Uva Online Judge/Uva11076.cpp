#include<bits/stdc++.h>
using namespace std;
long long fa[13],Ways,Pow[13],x;
unsigned long long sum;
int cnt[10];

void init()
{
    for(int i = 0; i <= 12; i++)
        Pow[i] = 1;
    fa[0] = 1;
    for(int i = 1; i <= 12; i++)
    {
        fa[i] = fa[i-1] * i;
        Pow[i] = 10 * Pow[i-1];
    }
}

void solve(int a[],int n)
{
    sum = 0;
    memset(cnt,0,sizeof(cnt));
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;

    for(int d = 0; d <= 9; d++)
    {
        Ways = fa[n-1];
        if(cnt[d])
        {
           for(int k = 0; k <= 9; k++){
             if(k == d)
                Ways /= fa[cnt[k]-1];
             else Ways /= fa[cnt[k]];
           }

           for(int pos = 0; pos < n; pos++)
             sum += Ways * d * Pow[pos];
        }
    }
}

int main()
{
    init();
    int n;
    int arr[15];

    while(scanf("%d",&n) && n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d",&arr[i]);
        solve(arr,n);
        printf("%llu\n",sum);
    }

    return 0;
}
