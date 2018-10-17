#include<bits/stdc++.h>
using namespace std;

void reverse(long long arr[],int n)
{

    int idx = 0;
    long long save[n];

    for(int i = n - 1; i >= 0; i--)
    {
        save[idx] = arr[i];
        ++idx;
    }

    for(int i = 0; i < n; i++)
        arr[i] = save[i];
}

void division(long long arr[],int n,long long d)
{
    for(int i = 0; i < n; i++)
        arr[i] = arr[i] / d;
}

void multiply(long long arr[],int n,long long m)
{
    for(int i = 0; i < n; i++)
        arr[i] = arr[i] * m;
}

void add(long long arr[],int n,long long a)
{
    for(int i = 0; i < n; i++)
        arr[i] = arr[i] + a;
}

void print(long long arr[],int n)
{
    bool space  = false;

    for(int i = 0; i < n; i++)
    {
        if(space)
            printf(" ");
        space = true;
        printf("%lld",arr[i]);
    }

    printf("\n");
}

int main()
{
    int cases;
    int case_no = 0;
    long long arr[102];
    int n;
    int m;
    char str[5];
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&n,&m);

        for(int i = 0; i < n; i++)
            scanf("%lld",&arr[i]);

        for(int j = 1; j <= m; j++)
        {

            scanf("%s",str);

            if(str[0] == 'P')
            {
                int a,b;
                scanf("%d%d",&a,&b);
                swap(arr[a],arr[b]);
            }
            else if(str[0] == 'R')
            {
                reverse(arr,n);
            }
            else if(str[0] == 'S')
            {
                long long a;
                scanf("%lld",&a);
                add(arr,n,a);
            }
            else if(str[0] == 'M')
            {
                long long m;
                scanf("%lld",&m);
                multiply(arr,n,m);
            }
            else if(str[0] == 'D')
            {
                long long d;
                scanf("%lld",&d);
                division(arr,n,d);
            }

        }

        printf("Case %d:\n",++case_no);
        print(arr,n);
    }

    return 0;
}
