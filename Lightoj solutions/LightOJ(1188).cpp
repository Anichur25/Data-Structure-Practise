#include<bits/stdc++.h>
using namespace std;
int Max = 100001;
int block;
struct Query
{
    int L,R,ans,index;
};
bool f1(Query q1,Query q2)
{
    if(q1.L / block != q2.L / block)
     return q1.L / block < q2.L / block;
    else return q1.R < q2.R;
}

bool f2(Query q1,Query q2)
{
    return q1.index < q2.index;
}

void solve(int a[],Query q[],int n,int m)
{
    block = (int)sqrt(n);
    sort(q ,q + m, f1);
    int currL,currR,distinct;
    currL = currR = distinct = 0;
    int freq[Max] = {0};

    for(int i = 0; i < m; i++)
    {
        int L = q[i].L;
        int R = q[i].R;

        while(currL < L)
        {
            freq[a[currL]]--;
            if(freq[a[currL]] == 0)
             --distinct;
            ++currL;
        }

        while(currL > L)
        {
            freq[a[currL - 1]]++;
            if(freq[a[currL - 1]] == 1)
             ++distinct;
            --currL;
        }
        while(currR <= R)
        {
            freq[a[currR]]++;
            if(freq[a[currR]] == 1)
                ++distinct;
            ++currR;
        }
        while(currR > R + 1)
        {
            freq[a[currR - 1]]--;
            if(freq[a[currR - 1]] == 0)
                --distinct;
            currR--;
        }

        q[i].ans = distinct;
    }
}
int main()
{
    int testCases,q,n,l,r;
    int a[100005];
    scanf("%d",&testCases);

    for(int test  = 1; test <= testCases; test++)
    {

        scanf("%d %d",&n,&q);
        Query QA[q];
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);
        printf("Case %d:\n",test);
        for(int Q = 0; Q < q; Q++)
        {
            scanf("%d %d",&l,&r);
            QA[Q].L = l - 1;
            QA[Q].R = r - 1;
            QA[Q].ans = 0;
            QA[Q].index = Q;
        }

        solve(a,QA,n,q);
        sort(QA,QA+q,f2);

        for(int i = 0; i < q; i++)
         printf("%d\n",QA[i].ans);
    }
    return 0;
}
